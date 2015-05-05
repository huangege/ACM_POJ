#include <stdio.h>

const int INF = 0xffffff0;

typedef struct Node {
	int L, R, M;
	int minV, maxV;
}Node;

Node tree[800010];
int tMax;
int tMin;

void BuildTree(int root, int l, int r) {
	tree[root].L = l;
	tree[root].R = r;
	tree[root].M = (l+r) / 2;
	tree[root].minV = INF;
	tree[root].maxV = -INF;
	if(l == r)
		return ;
	BuildTree(2*root+1, l, tree[root].M);
	BuildTree(2*root+2, tree[root].M+1, r);
}

void Insert(int root, int i, int value) {
	int mid;

	if(tree[root].L == tree[root].R) {
		tree[root].minV = value;
		tree[root].maxV = value;
		return ;
	}

	if(tree[root].minV > value)
		tree[root].minV = value;
	if(tree[root].maxV < value)
		tree[root].maxV = value;

	if(i <= tree[root].M)
		Insert(root*2+1, i, value);
	else
		Insert(root*2+2, i, value);
}

void Query(int root, int l, int r) {
	if(tree[root].minV >= tMin && tree[root].maxV <= tMax)
		return ;

	if(l == tree[root].L && r ==tree[root].R) {
		if(tree[root].minV < tMin)
			tMin = tree[root].minV;
		if(tree[root].maxV > tMax)
			tMax = tree[root].maxV;
		return ;
	}
	else if(l > tree[root].M) {
		Query(root*2+2, l, r);
	}
	else if(r < tree[root].M+1) {
		Query(root*2+1, l, r);
	}
	else {
		Query(root*2+1, l, tree[root].M);
		Query(root*2+2, tree[root].M+1, r);
	}
}

int main() {
	int n, q;
	int l, r;
	int v;
	int i = 0;

	scanf("%d%d", &n, &q);
	BuildTree(0, 0, n-1);

	for(i=0; i<n; i++) {
		scanf("%d", &v);
		Insert(0, i, v);
	}
	for(i=0; i<q; i++) {
		tMin = INF;
		tMax = -INF;

		scanf("%d%d", &l, &r);
		Query(0, l-1, r-1);
		printf("%d\n", tMax-tMin);
	}
}
