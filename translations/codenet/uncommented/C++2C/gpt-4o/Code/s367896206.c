#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int f[6];
} Cube;

void roll(Cube *c, int i, int j, int k, int l) {
    int t = c->f[i];
    c->f[i] = c->f[j];
    c->f[j] = c->f[k];
    c->f[k] = c->f[l];
    c->f[l] = t;
}

void roll_z(Cube *c) { roll(c, 1, 2, 4, 3); }
void roll_y(Cube *c) { roll(c, 0, 2, 5, 3); }
void roll_x(Cube *c) { roll(c, 0, 1, 5, 4); }

bool eq(Cube c1, Cube c2) {
    for (int i = 0; i < 6; i++)
        if (c1.f[i] != c2.f[i]) return false;
    return true;
}

bool equal(Cube c1, Cube c2) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (eq(c1, c2)) return true;
            roll_z(&c1);
        }
        if (i % 2 == 0) roll_y(&c1);
        else roll_x(&c1);
    }
    return false;
}

int main() {
    Cube c1, c2;

    for (int i = 0; i < 6; i++) scanf("%d", &c1.f[i]);
    for (int i = 0; i < 6; i++) scanf("%d", &c2.f[i]);

    if (equal(c1, c2)) printf("Yes\n");
    else printf("No\n");

    return 0;
}

// <END-OF-CODE>
