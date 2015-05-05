#include <stdio.h>

int p, e, i, d;
int pp = 23, ep = 28, ip = 33;

int main() {
	int j;
	int k = 0;

	while(scanf("%d%d%d%d", &p, &e, &i, &d) != EOF) {
		k++;
		if(p==-1 && e==-1 && i==-1 && d==-1)
			break;
		p = p % pp;
		e = e % ep;
		i = i % ip;

		if(i == 0)
			j = ip;
		else
			j = i;
		for(; j<=21252+d; j+=ip) {
			if((j-p) % pp == 0 && (j-e) % ep == 0 && j > d)
				break;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n", k, j-d);
	}

	return 0;
}
