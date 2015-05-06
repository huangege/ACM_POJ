#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXINPUT 10000
int colorOccupy[MAXINPUT+10];

struct post {
	int left;
	int right;
} poster[MAXINPUT+10];

struct lineCoordinate {
	int x;
	int pnum;
} line[2*MAXINPUT+10];

int lineCmp(const void *a, const void *b) {
	return ((struct lineCoordinate*)a)->x -  ((struct lineCoordinate*)b)->x;
}

struct TreeNode {
	int left;
	int right;
	int color;
} nodes[100*MAXINPUT+10];

void buildTree(int l, int r, int nodeIndex) {
	int mid;

	nodes[nodeIndex].left = l;
	nodes[nodeIndex].right = r;
	nodes[nodeIndex].color = 0;
	if(l == r)
		return ;
	mid = (l+r) / 2;
	buildTree(l, mid, nodeIndex*2+1);
	buildTree(mid+1, r, nodeIndex*2+2);
}

void insertPoster(int nodeIndex, int l, int r, int color) {
	int nl = nodes[nodeIndex].left;
	int nr = nodes[nodeIndex].right;
	int mid = (nl + nr) / 2;

	if(l == nl && r == nr) {
		nodes[nodeIndex].color = color;
		return ;
	}

	if(nodes[nodeIndex].color != 0) {
		/*if current node has color, then give it to its children*/
		nodes[nodeIndex*2+1].color = nodes[nodeIndex].color;
		nodes[nodeIndex*2+2].color = nodes[nodeIndex].color;
		nodes[nodeIndex].color = 0;
	}

	if(r <= mid) {
		insertPoster(nodeIndex*2+1, l, r, color);
	}
	else if(l > mid) {
		insertPoster(nodeIndex*2+2, l, r, color);
	}
	else {
		insertPoster(nodeIndex*2+1, l, mid, color);
		insertPoster(nodeIndex*2+2, mid+1, r, color);
	}
}

void query(int nodeIndex) {
	if(nodes[nodeIndex].color != 0) {
		colorOccupy[nodes[nodeIndex].color] = 1;
		return ;
	}
	
	if(nodes[nodeIndex].left == nodes[nodeIndex].right)
		return ;
	
	query(nodeIndex*2+1);
	query(nodeIndex*2+2);
}

int main() {
	int c, n, i, extraCount, count, prePoint;
	int colorCount;

	scanf("%d", &c);
	while(c > 0) {
		c--;
		scanf("%d", &n);

		memset(colorOccupy, 0, n*sizeof(int));

		for(i=0; i<n; i++) {
			/*Get the points and store in the line array*/
			scanf("%d%d", &(poster[i].left), &(poster[i].right));
			line[i*2].x = poster[i].left;
			/*set the left coordinate to negative number*/
			line[i*2].pnum = i*2;
			line[i*2+1].x = poster[i].right;
			line[i*2+1].pnum = i*2+1;
		}
		qsort(line, n*2, sizeof(struct lineCoordinate),  lineCmp);

		/*Disperse*/
		prePoint = 0;
		count = 0;
		for(i=0; i<n*2; i++) {
			if(line[i].x != prePoint)
				count++;
			if(line[i].x-prePoint > 1)
				count++;
			if(line[i].pnum % 2 == 0)
				poster[line[i].pnum/2].left = count;
			else
				poster[line[i].pnum/2].right = count;
			prePoint = line[i].x;
		}
		
		buildTree(1, count, 0);
		for(i=0; i<n; i++)
			insertPoster(0, poster[i].left, poster[i].right, i+1);

		query(0);

		colorCount = 0;
		for(i=1; i<=n; i++)
			colorCount += colorOccupy[i];

		printf("%d\n", colorCount);

	}

	return 0;
}
