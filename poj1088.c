#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int height[110][110];
int length[110][110];
int R, C;

int max(int a, int b) {
	if(a > b)
		return a;
	return b;
}

int search(int i, int j) {
	int m;
	if(i<0 || i>=R || j<0 || j>=C)
		return 0;

	if(length[i][j] != 0)
		return length[i][j];
	
	m = 1;
	if(i>0 && height[i][j] > height[i-1][j])
		m = max(m, search(i-1, j)+1);
	if(i<R-1 && height[i][j] > height[i+1][j])
		m = max(m, search(i+1, j)+1);
	if(j>0 && height[i][j] > height[i][j-1])
		m = max(m, search(i, j-1)+1);
	if(j<C-1 && height[i][j] > height[i][j+1])
		m = max(m, search(i, j+1)+1);
	length[i][j] = m;
	return m;
}

int main() {
	int mLength = 0;
	int i, j;

	scanf("%d%d", &R, &C);
	for(i=0; i<R; i++) {
		for(j=0; j<C; j++) {
			scanf("%d", &height[i][j]);
			length[i][j] = 0;
		}
	}

	for(i=0; i<R; i++)
		for(j=0; j<C; j++) {
			if(length[i][j] == 0) {
				length[i][j] = search(i, j);
				mLength = max(mLength, length[i][j]);
			}
		}
	printf("%d\n", mLength);

	return 0;
}
