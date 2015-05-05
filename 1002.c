#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[26] = {
	2, 2, 2,
	3, 3, 3,
	4, 4, 4,
	5, 5, 5,
	6, 6, 6,
	7, 7, 7, 7,
	8, 8, 8,
	9, 9, 9, 9
};
char str[100000][200];
int num[100000][7];

int myCompare(const void *a, const void *b) {
	int i, t;

	for(i=0; i<7; i++) {
		t = ((int*)a)[i] - ((int*)b)[i];
		if(t > 0)
			return 1;
		else if(t == 0)
			continue;
		else
			return -1;
	}
	return 0;
}

int main() {
	int n;
	int i, j, k, flag;

	/*Input.*/
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%s", str[i]);
	}

	/*Transform.*/
	for(i=0; i<n; i++) {
		k = 0;
		for(j=0; j<strlen(str[i]); j++) {
			if(str[i][j]>='0' && str[i][j]<='9') {
				num[i][k++] = str[i][j] - '0';
			}
			else if(str[i][j]>='A' && str[i][j]<='Z' && str[i][j]!='Q' && str[i][j]!='Z') {
				num[i][k++] = map[(str[i][j] - 'A')];
			}
			else
				continue;
		}
	}

	/*sort*/
	qsort(num, n, sizeof(int)*7, myCompare);

	/*Output.*/
	k=0;
	flag = 0;
	for(i=1; i<n; i++) {
		if(myCompare(num[i], num[i-1]) == 0) {
			flag = 1;
			k++;
		}
		else {
			if(k == 0)
				continue;
			else {
				for(j=0; j<3; j++)
					printf("%d", num[i-1][j]);
				printf("-");
				for(j=3; j<7; j++)
					printf("%d", num[i-1][j]);
				printf(" %d\n", k+1);
				k = 0;
			}
		}
	}
	if(k != 0) {
		for(j=0; j<3; j++)
			printf("%d", num[i-1][j]);
		printf("-");
		for(j=3; j<7; j++)
			printf("%d", num[i-1][j]);
		printf(" %d\n", k+1);
		k = 0;
	}
	if(flag == 0)
		printf("No duplicates.\n");

	return 0;
}
