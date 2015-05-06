#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
	char seq[60];
	int reNum;
	int sourceIndex;
} strings[110];

struct string s[110];

int lCount[26];

int stringCmp(const void* a, const void* b) {
	int cmp1 = 0;
	int cmp2 = 0;

	cmp1 = ((struct string*)a)->reNum -  ((struct string*)b)->reNum;
	if(cmp1 != 0)
		return cmp1;
	return ((struct string*)a)->sourceIndex -  ((struct string*)b)->sourceIndex;
}

int main() {
	int n, m, index, i, j, k;

	scanf("%d%d", &n, &m);
	for(i=0; i<m; i++) {
		scanf("%s", strings[i].seq);
		strings[i].reNum = 0;
		strings[i].sourceIndex = i;
		memset(lCount, 0, 26*sizeof(int));
		for(j=n-1; j>=0; j--) {
			index = strings[i].seq[j] - 'A';
			lCount[index]++;
			for(k=0; k<index; k++) {
				strings[i].reNum += lCount[k];
			}
		}
	}

	qsort(strings, m, sizeof(struct string), stringCmp);
	
	for(i=0; i<m; i++)
		printf("%s\n", strings[i].seq);

	return 0;
}
