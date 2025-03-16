#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    int games_count = 0;
    int **games = (int **)malloc((x - a) * (y - b) * sizeof(int *));

    for (int i = a; i <= x; i++) {
        if (i <= b) continue;
        for (int j = b; j <= y; j++) {
            if (i > j) {
                games[games_count] = (int *)malloc(2 * sizeof(int));
                games[games_count][0] = i;
                games[games_count][1] = j;
                games_count++;
            }
        }
    }

    printf("%d\n", games_count);
    for (int i = 0; i < games_count; i++) {
        printf("%d %d\n", games[i][0], games[i][1]);
        free(games[i]);
    }
    free(games);

    return 0;
}
