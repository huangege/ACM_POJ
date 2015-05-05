#include <stdio.h>

double b[12];
double ave;
double sum;

int main() {
	int i;

	sum = 0;
	for(i=0; i<12; i++) {
		scanf("%lf", &b[i]);
		sum += b[i];
	}
	ave = sum / 12;
	printf("$%.2lf\n", ave);
}
