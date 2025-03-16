#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
#define MAX_H 20
#define MAX_W 20
#define BLACK 35

int countBlack(int h, int w, int m[MAX_H][MAX_W]) {
    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == BLACK) {
                count++;
            }
        }
    }
    return count;
}

int solve(int h, int w, int a, int m[MAX_H][MAX_W]) {
    int result = 0;
    for (int i = 0; i < (1 << h); i++) {
        for (int k = 0; k < (1 << w); k++) {
            int tmp[MAX_H][MAX_W];
            memcpy(tmp, m, sizeof(int) * h * w);
            for (int j = 0; j < h; j++) {
                if (i & (1 << j)) {
                    for (int l = 0; l < w; l++) {
                        tmp[j][l] = 1;
                    }
                }
            }
            for (int j = 0; j < w; j++) {
                if (k & (1 << j)) {
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1;
                    }
                }
            }
            if (countBlack(h, w, tmp) == a) {
                result++;
            }
        }
    }
    return result;
}
=======
#define INF 1000000007
#define BLACK 35

// Function prototypes
int countBlack(int h, int w, int **m);
int solve(int h, int w, int a, int **m);
void debug(const char *msg);
void debugInt(int value);
void debugArray(int *arr, int size);
>>>>>>> 98c87cb78a (data updated)

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);
<<<<<<< HEAD
    int m[MAX_H][MAX_W];
    for (int i = 0; i < h; i++) {
        char s[MAX_W + 1];
=======
    
    // Allocate memory for the matrix
    int **m = (int **)malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++) {
        m[i] = (int *)malloc(w * sizeof(int));
        char s[w + 1]; // +1 for null terminator
>>>>>>> 98c87cb78a (data updated)
        scanf("%s", s);
        for (int j = 0; j < w; j++) {
            m[i][j] = (int)s[j];
        }
    }

    int answer = solve(h, w, k, m);
    printf("%d\n", answer);
<<<<<<< HEAD
    return 0;
}
=======

    // Free allocated memory
    for (int i = 0; i < h; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}

int countBlack(int h, int w, int **m) {
    int count = 0;
    debug("new table");
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == BLACK) {
                count++;
            }
        }
        debugArray(m[i], w);
    }
    debugInt(count);
    return count;
}

int solve(int h, int w, int a, int **m) {
    int result = 0;
    for (int i = 0; i < (1 << h); i++) {
        for (int k = 0; k < (1 << w); k++) {
            // Create a temporary matrix
            int **tmp = (int **)malloc(h * sizeof(int *));
            for (int j = 0; j < h; j++) {
                tmp[j] = (int *)malloc(w * sizeof(int));
                memcpy(tmp[j], m[j], w * sizeof(int));
            }

            // Paint rows
            for (int j = 0; j < h; j++) {
                if (i & (1 << j)) {
                    for (int l = 0; l < w; l++) {
                        tmp[j][l] = 1;
                    }
                }
            }

            // Paint columns
            for (int j = 0; j < w; j++) {
                if (k & (1 << j)) {
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1;
                    }
                }
            }

            if (countBlack(h, w, tmp) == a) {
                result++;
            }

            // Free temporary matrix
            for (int j = 0; j < h; j++) {
                free(tmp[j]);
            }
            free(tmp);
        }
    }
    return result;
}

void debug(const char *msg) {
    // Uncomment the following line to enable debugging
    // fprintf(stderr, "%s\n", msg);
}

void debugInt(int value) {
    // Uncomment the following line to enable debugging
    // fprintf(stderr, "%d\n", value);
}

void debugArray(int *arr, int size) {
    // Uncomment the following lines to enable debugging
    // for (int i = 0; i < size; i++) {
    //     fprintf(stderr, "%d ", arr[i]);
    // }
    // fprintf(stderr, "\n");
}
>>>>>>> 98c87cb78a (data updated)
