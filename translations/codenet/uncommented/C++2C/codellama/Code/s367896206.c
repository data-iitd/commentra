#include<stdio.h>
#include<stdbool.h>

typedef struct Cube {
	int f[6];
} Cube;

void roll(Cube *c, int i, int j, int k, int l) {
	int t = c->f[i]; c->f[i] = c->f[j]; c->f[j] = c->f[k]; c->f[k] = c->f[l]; c->f[l] = t;
}

bool eq(Cube c1, Cube c2) {
	for (int i = 0; i < 6; i++)
		if (c1.f[i] != c2.f[i])return false;
	return true;
}

bool equal(Cube c1, Cube c2) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (eq(c1, c2))return true;
			roll(&c1, 1, 2, 4, 3);
		}
		if (i % 2 == 0)roll(&c1, 0, 2, 5, 3);
		else roll(&c1, 0, 1, 5, 4);
	}
	return false;
}

int main()
{
	Cube c1, c2;
	
	for (int i = 0; i < 6; i++)scanf("%d", &c1.f[i]);
	for (int i = 0; i < 6; i++)scanf("%d", &c2.f[i]);

	if (equal(c1, c2))printf("Yes\n");
	else printf("No\n");

    return 0;
}

