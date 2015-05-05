#include <stdio.h>

int num[30001];
int parent[30001];

void makeSet(int n) {
	int i;

	for(i=0; i<n; i++) {
		num[i] = 1;
		parent[i] = i;
	}
}

int find(int x) {
	if(parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void setUnion(int x, int y) {
	int fx, fy;

	fx = find(x);
	fy = find(y);
	if(fx == fy)
		return;
	if(fy > fx) {
		parent[fy] = fx;
		num[fx] += num[fy];
	}
	else {
		parent[fx] = fy;
		num[fy] += num[fx];
	}
}

int main() {
	int n, m, i, k, j, x, y;

	while(1) {
		scanf("%d%d", &n, &m);
		if(n==0 && m==0)
			break;
		if(m==0) {
			printf("1\n");
			continue;
		}

		makeSet(n);
		for(i=0; i<m; i++) {
			scanf("%d", &k);
			scanf("%d", &x);
			for(j=1; j<k; j++) {
				scanf("%d", &y);
				setUnion(x, y);
			}
		}
		printf("%d\n", num[0]);
	}
}
