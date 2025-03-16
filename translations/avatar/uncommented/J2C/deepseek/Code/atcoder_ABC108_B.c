#include <stdio.h>

int* revpos(int* p, int* q) {
    int vec[2] = {0, 0};
    for (int i = 0; i < 2; i++) {
        vec[i] = p[i] - q[i];
    }
    int tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp;
    int newpos[2] = {0, 0};
    for (int i = 0; i < 2; i++) {
        newpos[i] = q[i] + vec[i];
    }
    return newpos;
}

int main() {
    int input[4];
    for (int i = 0; i < 4; i++) {
        scanf("%d", &input[i]);
    }
    int position[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    position[0][0] = input[0];
    position[0][1] = input[1];
    position[1][0] = input[2];
    position[1][1] = input[3];
    int* pos2 = revpos(position[0], position[1]);
    int* pos3 = revpos(position[1], pos2);
    if (position[0][0] == pos2[0] && position[0][1] == pos2[1] && position[1][0] == pos3[0] && position[1][1] == pos3[1]) {
        printf("OK\n");
    }
    int output[4];
    output[0] = pos2[0];
    output[1] = pos2[1];
    output[2] = pos3[0];
    output[3] = pos3[1];
    for (int i = 0; i < 4; i++) {
        printf("%d\n", output[i]);
    }
    return 0;
}
