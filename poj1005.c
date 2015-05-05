#include <stdio.h>
#include <math.h>
#define pi 3.14

int main() {
	int n;
	int i;
	double x, y;
	double dist;
	int years;
	double area;

	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%lf%lf", &x, &y);
		dist = sqrt(x*x+y*y);
		area = pi * dist * dist / 2;
		years = (int)(area/50);
		if (area - years*50.0 > 0)
			years++;
		printf("Property %d: This property will begin eroding in year %d.\n", i+1, years);
	}
	printf("END OF OUTPUT.\n");

	return 0;
}
