#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

// Structure to represent the size of a matrix
typedef struct TSize{
    int r; // Number of rows
    int c; // Number of columns
}TSize;

// Class to solve the Matrix Chain Multiplication problem
typedef struct TMcmSolver{
    TSize* Chain; // Pointer to the chain of matrices
    int n; // Number of matrices
    int** FMemo; // Memoization table to store intermediate results

    // Function to calculate the cost of multiplying two matrices
    static int Count(TSize Left, TSize Right){
        return Left.r * Right.c * Left.c; // Cost = rows of Left * columns of Right * columns of Left
    }

    // Recursive function to solve the matrix chain multiplication problem
    int Solve(int s, int l){
        assert(s <= l); // Ensure the start index is less than or equal to the end index
        if(s == l) return 0; // Base case: no cost if there is only one matrix
        if(FMemo[s][l]!= 0) return FMemo[s][l]; // Return cached result if already computed
        if(s + 1 == l){
            // If there are two matrices, calculate the cost directly
            FMemo[s][l] = Count(Chain[s], Chain[l]);
        }else{
            int min = INT_MAX; // Initialize minimum cost to maximum possible value
            // Try every possible split point to find the minimum cost
            for(int i = s; i < l; ++i){
                // Calculate cost of multiplying the two parts and add the cost of multiplying the resulting matrices
                int c = Solve(s, i) + Count(TSize{Chain[s].r, Chain[i].c}, TSize{Chain[i+1].r, Chain[l].c}) + Solve(i+1, l);
                min = c < min? c : min; // Update minimum cost
            }
            FMemo[s][l] = min; // Store the minimum cost in the memoization table
        }
        // printf("Solve! [%d], [%d]\n", s, l); 
        return FMemo[s][l]; // Return the computed minimum cost
    }

public:
    // Constructor to initialize the solver with a chain of matrices
    TMcmSolver(TSize* Chain, int n){
        this->Chain = Chain;
        this->n = n;
        // Resize the memoization table based on the size of the chain
        FMemo = (int**)malloc(sizeof(int*) * n);
        for(int i = 0; i < n; ++i){
            FMemo[i] = (int*)malloc(sizeof(int) * n); // Initialize all values to 0
            memset(FMemo[i], 0, sizeof(int) * n);
        }
    }

    // Function to get the final answer (minimum multiplication cost)
    int Answer(){
        return Solve(0, n-1); // Solve for the entire chain
    }

    // Function to print the memoization table (for debugging purposes)
    void Print(){
        for(int s = 0; s < n; ++s){
            for(int l = 0; l < n; ++l){
                printf("%d\t", FMemo[s][l]); // Print each value in the table
            }
            printf("\n"); // New line after each row
        }
    }
};

int main(){
    int n; // Number of matrices
    scanf("%d", &n); // Input the number of matrices
    if(n == 1){
        printf("%d\n", 0); // If there is only one matrix, no multiplication is needed
        return 0; // Exit the program
    }
    
    TSize* Chain = (TSize*)malloc(sizeof(TSize) * n); // Vector to hold the sizes of the matrices
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &Chain[i].r, &Chain[i].c); // Input the dimensions of each matrix
    }
    
    TMcmSolver Solver = TMcmSolver(Chain, n); // Create an instance of the solver with the matrix chain
    
    printf("%d\n", Solver.Answer()); // Output the minimum multiplication cost
    // Solver.Print(); // Uncomment to print the memoization table
    return 0; // Exit the program
}
