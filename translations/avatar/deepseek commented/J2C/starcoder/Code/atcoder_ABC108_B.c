#include <stdio.h>
#include <stdlib.h>

int main() {
    int input[4];
    for (int i = 0; i < 4; i++) {
        scanf("%d", &input[i]);
    }
    int position[4][2];
    position[0][0] = input[0];
    position[0][1] = input[1];
    position[1][0] = input[2];
    position[1][1] = input[3];
    position[2][0] = position[0][0] - position[1][0];
    position[2][1] = position[0][1] - position[1][1];
    position[3][0] = position[1][0] - position[2][0];
    position[3][1] = position[1][1] - position[2][1];
    if (position[0][0] == position[3][0] && position[0][1] == position[3][1]) {
        printf("OK\n");
    }
    int output[4];
    output[0] = position[2][0];
    output[1] = position[2][1];
    output[2] = position[3][0];
    output[3] = position[3][1];
    for (int i = 0; i < 4; i++) {
        printf("%d\n", output[i]);
    }
    return 0;
}

