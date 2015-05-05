#include <stdio.h>
#include <math.h>
#include <string.h>

char baseStr[10];
int exponent;
int a[200], b[200];
int alen, blen;
int result[200];
int rlen;
int dot;

void BigMulti(){
	int i, j, k;
	int carry;

	memset(result, 0, sizeof(int)*200);
	rlen = alen + blen;
	for(i=alen-1; i>=0; i--) {
		for(j=blen-1; j>=0; j--) {
			k = i + j + 1;
			result[k] += a[i]*b[j];
			carry = result[k] / 10;
			if(carry != 0) {
				result[k-1] += carry;
			}
			result[k] = result[k] % 10;
		}
	}

	blen = rlen;
	for(i=0; i<rlen; i++) {
		b[i] = result[i];
	}
}

void Solve() {
	int i, j, k;
	int dp = 0;
	int pstart, pend;

	/*Initialize.*/
	memset(a, 0, sizeof(int)*200);
	memset(b, 0, sizeof(int)*200);
	memset(result, 0, sizeof(int)*200);
	alen = 0;
	blen = 0;
	rlen = 0;

	/*Transform string to number.*/
	j=0;
	for(i=0; i<strlen(baseStr); i++) {
		if(baseStr[i] == '.') {
			dp = i;
			continue;
		}
		a[j++] = baseStr[i]-'0';
	}
	if(i == j)
		dot = 0;
	else {
		dot = strlen(baseStr) - 1 - dp;
		dot = exponent * dot;
	}
	alen = j;

	/*Calculation.*/
	b[0] = 1;
	blen = 1;
	for(i=0; i<exponent; i++) {
		BigMulti();
	}

	/*Print the result.*/
	for(pstart=0; pstart<rlen; pstart++) {
		if(result[pstart] != 0 || pstart == rlen-dot)
			break;
	}
	for(pend=rlen-1; pend>=0; pend--) {
		if(result[pend] != 0 || pend == rlen-dot-1)
			break;
	}
	for(i=pstart; i<=pend; i++) {
		if(i == rlen-dot)
			printf(".");
		printf("%d", result[i]);
	}
	if(pstart > pend)
		printf("0");
	printf("\n");

}

int main() {
	int i;

	while(scanf("%s%d", baseStr, &exponent) != EOF)
		Solve();
	
	return 0;
}
