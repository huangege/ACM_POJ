#include <stdio.h>

int main() {
	float length;
	int k;

	while(scanf("%f", &length) != EOF) {
		if(length < 0.01)
			break;
		k = 1;
		length = length - 1/(float)(k+1);
		while(length > 0) {
			k++;
			length = length - 1/(float)(k+1);
		}
		printf("%d card(s)\n", k);
	}


	return 0;
}
