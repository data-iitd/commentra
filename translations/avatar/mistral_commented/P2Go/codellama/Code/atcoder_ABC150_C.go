// Ask the user for the size of the permutation list
fmt.Print("Enter the size of the permutation list: ")
var n int
fmt.Scan(&n)

// Import the itertools module for generating permutations
import "github.com/golang/example/stringutil"

// Create a list of all possible permutations of numbers from 1 to n
orig := stringutil.Permutations(n)

// Ask the user for two permutations as tuples
fmt.Print("Enter the first permutation: ")
var p, q []int
fmt.Scan(&p)
fmt.Print("Enter the second permutation: ")
fmt.Scan(&q)

// Find the indices of p and q in the orig list
pn := orig.Index(p)
qn := orig.Index(q)

// Print the absolute difference between the indices of p and q
fmt.Println(math.Abs(float64(pn - qn)))

