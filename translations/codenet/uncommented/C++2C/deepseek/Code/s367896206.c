#include <stdio.h>

typedef struct {
    int f[6];
} Cube;

void roll_z(Cube *c) {
    int t = c->f[1]; c->f[1] = c->f[2]; c->f[2] = c->f[4]; c->f[4] = c->f[3]; c->f[3] = t;
}

void roll_y(Cube *c) {
    int t = c->f[0]; c->f[0] = c->f[2]; c->f[2] = c->f[5]; c->f[5] = c->f[3]; c->f[3] = t;
}

void roll_x(Cube *c) {
    int t = c->f[0]; c->f[0] = c->f[1]; c->f[1] = c->f[5]; c->f[5] = c->f[4]; c->f[4] = t;
}

void roll(Cube *c, int i, int j, int k, int l) {
    int t = c->f[i]; c->f[i] = c->f[j]; c->f[j] = c->f[k]; c->f[k] = c->f[l]; c->f[l] = t;
}

int eq(Cube c1, Cube c2) {
    for (int i = 0; i < 6; i++)
        if (c1.f[i] != c2.f[i]) return 0;
    return 1;
}

int equal(Cube c1, Cube c2) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (eq(c1, c2)) return 1;
            roll_z(&c1);
        }
        if (i % 2 == 0) roll_y(&c1);
        else roll_x(&c1);
    }
    return 0;
}

int main() {
    Cube c1, c2;

    for (int i = 0; i < 6; i++) scanf("%d", &c1.f[i]);
    for (int i = 0; i < 6; i++) scanf("%d", &c2.f[i]);

    if (equal(c1, c2)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
