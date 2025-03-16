// Read an integer input n, which defines the range of numbers to permute
n, _ := strconv.Atoi(input())

// Import the itertools module to use its permutations function
import "github.com/golang/itertools"

// Generate all possible permutations of the numbers from 1 to n
orig := itertools.Permutations([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10})

// Read the first permutation input as a tuple of integers
p := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

// Read the second permutation input as a tuple of integers
q := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

// Find the index of the first permutation in the list of all permutations
pn := orig.Index(p)

// Find the index of the second permutation in the list of all permutations
qn := orig.Index(q)

// Calculate and print the absolute difference between the two indices
fmt.Println(math.Abs(float64(pn - qn)))

