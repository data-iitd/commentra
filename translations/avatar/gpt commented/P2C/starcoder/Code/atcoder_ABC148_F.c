#include <stdio.h>
#include <stdlib.h>

// Define a large prime number for modular arithmetic
#define mod 1000000007

// Define infinity for comparison purposes
#define INF 1000000000

// Function to read a single integer from input
int inp() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read a list of integers from input
int *inpl(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to print a list of integers to output
void prinl(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to print a list of integers to output
void prinll(int **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2d(int **arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dl(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllllllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllllllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllllllllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllllllllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllllllllllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllllllllllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllllllllllllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllllllllllllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i + j * n]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dlllllllllllllllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i * m + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a list of integers to output
void prin2dllllllllllllllllllllllllllllllll(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
   