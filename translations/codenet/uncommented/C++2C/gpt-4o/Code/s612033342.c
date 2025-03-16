#include <stdio.h>
#include <stdlib.h>

int pow2(int a) {
    int ret = 1;
    for (int i = 0; i < a; i++) ret *= 2;
    return ret;
}

int count(int** hw, int h, int w, int a, int b) {
    int sum = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
<<<<<<< HEAD
            if ((a >> i & 1) && (b >> j & 1) && hw[i][j] == 1) sum++;
=======
            if ((a >> i) & 1 && (b >> j) & 1 && hw[i][j] == 1) sum++;
>>>>>>> 98c87cb78a (data updated)
        }
    }
    return sum;
}

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);
    
    // Allocate memory for the 2D array
    int** hw = (int**)malloc(h * sizeof(int*));
    for (int i = 0; i < h; i++) {
        hw[i] = (int*)malloc(w * sizeof(int));
    }

<<<<<<< HEAD
    // Read the input and fill the hw array
=======
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            scanf(" %c", &c); // Note the space before %c to consume any whitespace
            if (c == '#') hw[i][j] = 1;
            else hw[i][j] = 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < pow2(h); i++) {
        for (int j = 0; j < pow2(w); j++) {
            if (count(hw, h, w, i, j) == k) sum++;
        }
    }

    printf("%d\n", sum);

    // Free allocated memory
    for (int i = 0; i < h; i++) {
        free(hw[i]);
    }
    free(hw);

    return 0;
}

// <END-OF-CODE>
