#include <assert.h> // For assert function to validate assumptions
// #include <algorithm> // Not used in this code
#include <stdio.h> // For input and output operations
#include <stdlib.h> // For using the vector container
#include <limits.h> // For INT_MAX constant

// Structure to represent the size of a matrix
struct TSize
{
    int r; // Number of rows
    int c; // Number of columns
    TSize() : r(0), c(0) {} // Default constructor initializing rows and columns to 0
    TSize(int Ar, int Ac) // Parameterized constructor to initialize with given values
     : r(Ar), c(Ac)
    {}
};

// Class to solve the Matrix Chain Multiplication problem
typedef struct TMcmSolver
{
    typedef struct TMatrix
    {
        int** data; // 2D array to store the matrix
        int r; // Number of rows
        int c; // Number of columns
    } TMatrix; // Define a type for a 2D matrix
    TMatrix* FMemo; // Memoization table to store intermediate results
    const struct TSize* FChain; // Reference to the chain of matrices

    // Function to calculate the cost of multiplying two matrices
    static int Count(const struct TSize* Left, const struct TSize* Right)
    {
        return Left->r * Right->c * Left->c; // Cost = rows of Left * columns of Right * columns of Left
    }

    // Recursive function to solve the matrix chain multiplication problem
    int Solve(int s, int l)
    {
        assert(s <= l); // Ensure the start index is less than or equal to the end index
        if(s == l) return 0; // Base case: no cost if there is only one matrix
        if(FMemo[s].data != NULL){
            return FMemo[s].data[l]; // Return cached result if already computed
        }
        if(s + 1 == l){
            // If there are two matrices, calculate the cost directly
            FMemo[s].data[l] = Count(FChain + s, FChain + l);
        }else{
            int min = INT_MAX; // Initialize minimum cost to maximum possible value
            // Try every possible split point to find the minimum cost
            for(int i = s; i < l; ++i){
                // Calculate cost of multiplying the two parts and add the cost of multiplying the resulting matrices
                int c = Solve(s, i) + Count(FChain + s, FChain + i) + Count(FChain + i + 1, FChain + l) + Solve(i+1, l);
                min = min < c ? min : c; // Update minimum cost
            }
            FMemo[s].data[l] = min; // Store the minimum cost in the memoization table
        }
        // printf("Solve! [%d], [%d]\n", s, l); 
        return FMemo[s].data[l]; // Return the computed minimum cost
    }

    // Constructor to initialize the solver with a chain of matrices
    TMcmSolver(const struct TSize* Chain)
     : FChain(Chain)
    {
        // Resize the memoization table based on the size of the chain
        FMemo = (TMatrix*)malloc(sizeof(TMatrix) * (Chain[0].r + 1));
        for(int i = 0; i < Chain[0].r + 1; ++i){
            FMemo[i].data = (int**)malloc(sizeof(int*) * (Chain[0].r + 1));
            for(int j = 0; j < Chain[0].r + 1; ++j){
                FMemo[i].data[j] = NULL; // Initialize all values to NULL
            }
        }
    }

    // Function to get the final answer (minimum multiplication cost)
    int Answer()
    {
        return Solve(0, FMemo[0].r - 1); // Solve for the entire chain
    }

    // Function to print the memoization table (for debugging purposes)
    void Print()const
    {
        for(int s = 0; s < FMemo[0].r; ++s){
            for(int l = 0; l < FMemo[0].r; ++l){
                printf("%d\t", FMemo[s].data[l]); // Print each value in the table
            }
            printf("\n"); // New line after each row
        }
    }
} TMcmSolver;

int main()
{
    int n; // Number of matrices
    scanf("%d", &n); // Input the number of matrices
    if(n == 1){
        printf("0\n"); // If there is only one matrix, no multiplication is needed
        return 0; // Exit the program
    }
    
    struct TSize* Chain = (struct TSize*)malloc(sizeof(struct TSize) * n); // Vector to hold the sizes of the matrices
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &Chain[i].r, &Chain[i].c); // Input the dimensions of each matrix
    }
    
    TMcmSolver Solver = TMcmSolver(Chain); // Create an instance of the solver with the matrix chain
    
    printf("%d\n", Solver.Answer()); // Output the minimum multiplication cost
    // Solver.Print(); // Uncomment to print the memoization table
    return 0; // Exit the program
}

