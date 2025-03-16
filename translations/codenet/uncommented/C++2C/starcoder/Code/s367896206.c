#include<stdio.h>

typedef struct {
	int f[6];
}Cube;

void roll(Cube *c, int i, int j, int k, int l) {
	int t = c->f[i]; c->f[i] = c->f[j]; c->f[j] = c->f[k]; c->f[k] = c->f[l]; c->f[l] = t;
}

int main()
{
	Cube c1, c2;
	
	for (int i = 0; i < 6; i++)scanf("%d", &c1.f[i]);
	for (int i = 0; i < 6; i++)scanf("%d", &c2.f[i]);

	int i, j, k, l;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 4; j++) {
			if (c1.f[0] == c2.f[0] && c1.f[1] == c2.f[1] && c1.f[2] == c2.f[2] && c1.f[3] == c2.f[3] && c1.f[4] == c2.f[4] && c1.f[5] == c2.f[5]) {
				printf("Yes\n");
				return 0;
			}
			roll(&c1, 1, 2, 4, 3);
		}
		if (i % 2 == 0)roll(&c1, 0, 2, 5, 3);
		else roll(&c1, 0, 1, 5, 4);
	}
	printf("No\n");

    return 0;
}

