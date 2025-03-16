#include <cassert> // For assert function to validate assumptions
// #include <algorithm> // Not used in this code
#include <iostream> // For input and output operations
#include <vector> // For using the vector container
#include <climits> // For INT_MAX constant

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
class TMcmSolver
{
    typedef std::vector<std::vector<int> > TMatrix; // Define a type for a 2D matrix
    TMatrix FMemo; // Memoization table to store intermediate results
    const std::vector<TSize>& FChain; // Reference to the chain of matrices

    // Function to calculate the cost of multiplying two matrices
    static int Count(const TSize& Left, const TSize& Right)
    {
        return Left.r * Right.c * Left.c; // Cost = rows of Left * columns of Right * columns of Left
    }

    // Recursive function to solve the matrix chain multiplication problem
    int Solve(int s, int l)
    {
        assert(s <= l); // Ensure the start index is less than or equal to the end index
        if(s == l) return 0; // Base case: no cost if there is only one matrix
        if(FMemo[s][l] != 0) return FMemo[s][l]; // Return cached result if already computed
        if(s + 1 == l){
            // If there are two matrices, calculate the cost directly
            FMemo[s][l] = Count(FChain[s], FChain[l]);
        }else{
            int min = INT_MAX; // Initialize minimum cost to maximum possible value
            // Try every possible split point to find the minimum cost
            for(int i = s; i < l; ++i){
                // Calculate cost of multiplying the two parts and add the cost of multiplying the resulting matrices
                int c = Solve(s, i) + Count(TSize(FChain[s].r, FChain[i].c), TSize(FChain[i+1].r, FChain[l].c)) + Solve(i+1, l);
                min = std::min(min, c); // Update minimum cost
            }
            FMemo[s][l] = min; // Store the minimum cost in the memoization table
        }
        // std::cout << "Solve! [" << s << "], [" << l << "]" << std::endl; 
        return FMemo[s][l]; // Return the computed minimum cost
    }

public:
    // Constructor to initialize the solver with a chain of matrices
    TMcmSolver(const std::vector<TSize>& Chain)
     : FChain(Chain)
    {
        // Resize the memoization table based on the size of the chain
        FMemo.resize(Chain.size());
        for(std::size_t i = 0; i < FMemo.size(); ++i){
            FMemo[i].resize(Chain.size(), 0); // Initialize all values to 0
        }
    }

    // Function to get the final answer (minimum multiplication cost)
    int Answer()
    {
        return Solve(0, FMemo.size()-1); // Solve for the entire chain
    }

    // Function to print the memoization table (for debugging purposes)
    void Print()const
    {
        for(std::size_t s = 0; s < FMemo.size(); ++s){
            for(std::size_t l = 0; l < FMemo[0].size(); ++l){
                std::cout << FMemo[s][l] << '\t'; // Print each value in the table
            }
            std::cout << '\n'; // New line after each row
        }
    }
};

int main()
{
    int n; // Number of matrices
    std::cin >> n; // Input the number of matrices
    if(n == 1){
        std::cout << 0 << std::endl; // If there is only one matrix, no multiplication is needed
        return 0; // Exit the program
    }
    
    std::vector<TSize> Chain(n); // Vector to hold the sizes of the matrices
    for(int i = 0; i < n; ++i){
        std::cin >> Chain[i].r >> Chain[i].c; // Input the dimensions of each matrix
    }
    
    TMcmSolver Solver(Chain); // Create an instance of the solver with the matrix chain
    
    std::cout << Solver.Answer() << std::endl; // Output the minimum multiplication cost
    // Solver.Print(); // Uncomment to print the memoization table
    return 0; // Exit the program
}
