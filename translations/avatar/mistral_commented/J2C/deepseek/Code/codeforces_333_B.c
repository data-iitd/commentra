#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    int rows;
    int cols;
    bool bannedRows[1001];
    bool bannedCols[1001];
} Grid;

void readGrid(Grid *grid) {
    scanf("%d %d", &grid->rows, &grid->cols);
    memset(grid->bannedRows, 0, sizeof(grid->bannedRows));
    memset(grid->bannedCols, 0, sizeof(grid->bannedCols));

    for (int i = 0; i < grid->cols; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        if (r > 1 && r < grid->rows) grid->bannedRows[r] = true;
        if (c > 1 && c < grid->cols) grid->bannedCols[c] = true;
    }
}

int calculateAnswer(Grid *grid) {
    int answer = (grid->rows - 2) * 2;
    answer -= (grid->bannedRows[1] ? 0 : 1) + (grid->bannedRows[grid->rows] ? 0 : 1);
    answer -= (grid->bannedCols[1] ? 0 : 1) + (grid->bannedCols[grid->cols] ? 0 : 1);

    if (grid->rows % 2 != 0) {
        int mid = (grid->rows + 1) / 2;
        if (!grid->bannedRows[mid] && !grid->bannedCols[mid]) {
            answer--;
        }
    }

    return answer;
}

int main() {
    Grid grid;
    readGrid(&grid);
    int answer = calculateAnswer(&grid);
    printf("%d\n", answer);
    return 0;
}

