#include <stdio.h> // For input and output operations
#include <stdlib.h> // For dynamic memory allocation
#include <limits.h> // For INT_MAX constant
#include <assert.h> // For assert function to validate assumptions

// Structure to represent the size of a matrix
typedef struct {
    int r; // Number of rows
    int c; // Number of columns
} TSize;

// Class to solve the Matrix Chain Multiplication problem
typedef struct {
    int** FMemo; // Memoization table to store intermediate results
    TSize* FChain; // Pointer to the chain of matrices
    int size; // Size of the chain
} TMcmSolver;

// Function to calculate the cost of multiplying two matrices
static int Count(const TSize* Left, const TSize* Right) {
    return Left->r * Right->c * Left->c; // Cost = rows of Left * columns of Right * columns of Left
}

// Recursive function to solve the matrix chain multiplication problem
int Solve(TMcmSolver* solver, int s, int l) {
    assert(s <= l); // Ensure the start index is less than or equal to the end index
    if (s == l) return 0; // Base case: no cost if there is only one matrix
    if (solver->FMemo[s][l] != 0) return solver->FMemo[s][l]; // Return cached result if already computed
    if (s + 1 == l) {
        // If there are two matrices, calculate the cost directly
        solver->FMemo[s][l] = Count(&solver->FChain[s], &solver->FChain[l]);
    } else {
        int min = INT_MAX; // Initialize minimum cost to maximum possible value
        // Try every possible split point to find the minimum cost
        for (int i = s; i < l; ++i) {
            // Calculate cost of multiplying the two parts and add the cost of multiplying the resulting matrices
<<<<<<< HEAD
            int c = Solve(solver, s, i) + Count(&(TSize){solver->FChain[s].r, solver->FChain[i].c}, &(TSize){solver->FChain[i + 1].r, solver->FChain[l].c}) + Solve(solver, i + 1, l);
=======
            int c = Solve(solver, s, i) + Count(&solver->FChain[s], &solver->FChain[i]) + Solve(solver, i + 1, l);
>>>>>>> 98c87cb78a (data updated)
            if (c < min) {
                min = c; // Update minimum cost
            }
        }
        solver->FMemo[s][l] = min; // Store the minimum cost in the memoization table
    }
    return solver->FMemo[s][l]; // Return the computed minimum cost
}

<<<<<<< HEAD
// Function to initialize the solver with a chain of matrices
TMcmSolver* CreateSolver(TSize* Chain, int size) {
    TMcmSolver* solver = (TMcmSolver*)malloc(sizeof(TMcmSolver));
    solver->FChain = Chain;
=======
// Function to create a new TMcmSolver instance
TMcmSolver* CreateSolver(TSize* chain, int size) {
    TMcmSolver* solver = (TMcmSolver*)malloc(sizeof(TMcmSolver));
    solver->FChain = chain;
>>>>>>> 98c87cb78a (data updated)
    solver->size = size;

    // Allocate memory for the memoization table
    solver->FMemo = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; ++i) {
        solver->FMemo[i] = (int*)calloc(size, sizeof(int)); // Initialize all values to 0
    }
    return solver;
}

<<<<<<< HEAD
// Function to free the solver resources
=======
// Function to free the TMcmSolver instance
>>>>>>> 98c87cb78a (data updated)
void FreeSolver(TMcmSolver* solver) {
    for (int i = 0; i < solver->size; ++i) {
        free(solver->FMemo[i]);
    }
    free(solver->FMemo);
    free(solver);
}

<<<<<<< HEAD
// Function to get the final answer (minimum multiplication cost)
int Answer(TMcmSolver* solver) {
    return Solve(solver, 0, solver->size - 1); // Solve for the entire chain
}

=======
>>>>>>> 98c87cb78a (data updated)
int main() {
    int n; // Number of matrices
    scanf("%d", &n); // Input the number of matrices
    if (n == 1) {
        printf("0\n"); // If there is only one matrix, no multiplication is needed
        return 0; // Exit the program
    }

    TSize* Chain = (TSize*)malloc(n * sizeof(TSize)); // Array to hold the sizes of the matrices
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &Chain[i].r, &Chain[i].c); // Input the dimensions of each matrix
    }

<<<<<<< HEAD
    TMcmSolver* solver = CreateSolver(Chain, n); // Create an instance of the solver with the matrix chain

    printf("%d\n", Answer(solver)); // Output the minimum multiplication cost

    FreeSolver(solver); // Free the allocated resources
=======
    TMcmSolver* Solver = CreateSolver(Chain, n); // Create an instance of the solver with the matrix chain

    printf("%d\n", Solve(Solver, 0, n - 1)); // Output the minimum multiplication cost

    FreeSolver(Solver); // Free the allocated memory
>>>>>>> 98c87cb78a (data updated)
    free(Chain); // Free the chain array
    return 0; // Exit the program
}

// <END-OF-CODE>
