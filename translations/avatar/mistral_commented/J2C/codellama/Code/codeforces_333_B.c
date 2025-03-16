
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    // Structure declaration

    int n ;
    int m ;
    int bannedRows[MAX_SIZE] ;
    int bannedCols[MAX_SIZE] ;
} Input ;

int main() {
    // Main method declaration

    Input input ;  // Creating an instance of Input structure
    int answer ;  // Creating a variable to store the answer

    scanf("%d %d", &input.n, &input.m) ;  // Reading the number of rows and columns in the grid

    for (int i = 0 ; i < input.m ; i ++ ) {
        // Reading banned cells and adding them to the respective arrays

        scanf("%d %d", &input.bannedRows[i], &input.bannedCols[i]) ;
    }

    answer = (input.n - 2) * 2 ;  // Initializing answer as the total number of cells in the grid minus the banned cells
    answer -= input.m ;  // Subtracting the number of banned rows
    answer -= input.m ;  // Subtracting the number of banned columns

    if (input.n % 2 != 0) {
        // Special case when the number of rows is odd

        int mid = (input.n + 1) / 2 ;
        if (!isInArray(input.bannedRows, input.m, mid) && !isInArray(input.bannedCols, input.m, mid)) {
            // If the middle cell is not banned, decrement the answer
            answer-- ;
        }
    }

    printf("%d\n", answer) ;  // Writing the answer to the output stream

    return 0 ;  // Returning 0 to indicate successful execution
}

int isInArray(int arr[], int size, int element) {
    // Method for checking if an element is in an array

    for (int i = 0 ; i < size ; i ++ ) {
        if (arr[i] == element) return 1 ;
    }
    return 0 ;
}

