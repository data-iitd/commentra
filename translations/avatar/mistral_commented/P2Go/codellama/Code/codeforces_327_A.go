// Import the "fmt" module for printing and the "strings" module for working with strings
import (
	"fmt"
	"strings"
)

// Define a helper function 'find' to locate the indices of a character in a string
func find(s string, ch byte) []int {
	// Use list comprehension to create a list of indices where the character 'ch' appears in the string 's'
	return []int{i for i, ltr := range s if ltr == ch}
}

// Check if the given input is valid and execute the main logic if it is
func main() {
	// Read the number of test cases 'n' from the standard input
	var n int
	fmt.Scan(&n)

	// Read the string 's' from the standard input and remove any leading or trailing whitespaces
	var s string
	fmt.Scan(&s)
	s = strings.TrimSpace(s)

	// Check if the string 's' does not contain '0' character
	if !strings.Contains(s, "0") {
		// If '0' is not present, print the result as the number of test cases minus one
		fmt.Println(n - 1)
	} else {
		// Find the indices of '0' character in the string 's'
		indices := find(s, '0')

		// Check if there is only one '0' character in the string 's'
		if len(indices) == 1 {
			// If there is only one '0', print the result as the number of '1's in the string
			fmt.Println(strings.Count(s, "1"))
		} else {
			// If there are multiple '0's, calculate the maximum combination score
			maximum := 0

			// Generate all possible combinations of indices of '0' characters using itertools.combinations()
			combs := itertools.Combinations(indices, 2)

			// Iterate through each combination and calculate the score for that combination
			for x := range combs {
				// Calculate the score for the current combination using the given formula
				score := 2 + 2*((indices.Index(x[0]) - indices.Index(x[1])) - 1) - ((x[0] - x[1]) - 1)
				// Update the maximum combination score if the current combination score is greater
				maximum = max(maximum, score)
			}

			// Print the final result which is the number of '1's in the string plus the maximum combination score
			fmt.Println(strings.Count(s, "1") + maximum)
		}
	}
}

// Define a helper function 'max' to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Define a helper function 'itertools.combinations' to generate all possible combinations of indices of '0' characters
func combinations(indices []int, r int) [][]int {
	// Initialize the result as an empty slice
	result := [][]int{}

	// Generate all possible combinations of indices of '0' characters using itertools.combinations()
	for i := 0; i < len(indices); i++ {
		for j := i + 1; j < len(indices); j++ {
			result = append(result, []int{indices[i], indices[j]})
		}
	}

	// Return the result
	return result
}

// Define a helper function 'itertools.Combinations' to generate all possible combinations of indices of '0' characters
func Combinations(indices []int, r int) [][]int {
	// Initialize the result as an empty slice
	result := [][]int{}

	// Generate all possible combinations of indices of '0' characters using itertools.combinations()
	for i := 0; i < len(indices); i++ {
		for j := i + 1; j < len(indices); j++ {
			result = append(result, []int{indices[i], indices[j]})
		}
	}

	// Return the result
	return result
}

// Define a helper function 'itertools.max' to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Define a helper function 'itertools.Index' to return the index of a given integer in a slice
func Index(s []int, x int) int {
	// Initialize the index as -1
	index := -1

	// Iterate through each element in the slice
	for i, v := range s {
		// Check if the current element is equal to the given integer
		if v == x {
			// If it is, update the index and break the loop
			index = i
			break
		}
	}

	// Return the index
	return index
}

// Define a helper function 'itertools.Index' to return the index of a given integer in a slice
func Index(s []int, x int) int {
	// Initialize the index as -1
	index := -1

	// Iterate through each element in the slice
	for i, v := range s {
		// Check if the current element is equal to the given integer
		if v == x {
			// If it is, update the index and break the loop
			index = i
			break
		}
	}

	// Return the index
	return index
}

// Define a helper function 'itertools.max' to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Define a helper function 'itertools.Index' to return the index of a given integer in a slice
func Index(s []int, x int) int {
	// Initialize the index as -1
	index := -1

	// Iterate through each element in the slice
	for i, v := range s {
		// Check if the current element is equal to the given integer
		if v == x {
			// If it is, update the index and break the loop
			index = i
			break
		}
	}

	// Return the index
	return index
}

// Define a helper function 'itertools.Index' to return the index of a given integer in a slice
func Index(s []int, x int) int {
	// Initialize the index as -1
	index := -1

	// Iterate through each element in the slice
	for i, v := range s {
		// Check if the current element is equal to the given integer
		if v == x {
			// If it is, update the index and break the loop
			index = i
			break
		}
	}

	// Return the index
	return index
}

// Define a helper function 'itertools.max' to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Define a helper function 'itertools.Index' to return the index of a given integer in a slice
func Index(s []int, x int) int {
	// Initialize the index as -1
	index := -1

	// Iterate through each element in the slice
	for i, v := range s {
		// Check if the current element is equal to the given integer
		if v == x {
			// If it is, update the index and break the loop
			index = i
			break
		}
	}

	// Return the index
	return index
}

// Define a helper function 'itertools.Index' to return the index of a given integer in a slice
func Index(s []int, x int) int {
	// Initialize the index as -1
	index := -1

	// Iterate through each element in the slice
	for i, v := range s {
		// Check if the current element is equal to the given integer
		if v == x {
			// If it is, update the index and break the loop
			index = i
			break
		}
	}

	// Return the index
	return index
}

// Define a helper function 'itertools.max' to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Define a helper function 'itertools.Index' to return the index of a given integer in a slice
func Index(s []int, x int) int {
	// Initialize the index as -1
	index := -1

	// Iterate through each element in the slice
	for i, v := range s {
		// Check if the current element is equal to the given integer
		if v == x {
			// If it is, update the index and break the loop
			index = i
			break
		}
	}

	// Return the index
	return index
}

// Define a helper function 'itertools.Index' to return the index of a given integer in a slice
func Index(s []int, x int) int {
	// Initialize the index as -1
	index := -1

	// Iterate through each element in the slice
	for i, v := range s {
		// Check if the current element is equal to the given integer
		if v == x {
			// If it is, update the index and break the loop
			index = i
			break
		}
	}

	// Return the index
	return index
}

// Define a helper function 'itertools.max' to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Define a helper function 'itertools.Index' to return the index of a given integer in a slice
func Index(s []int, x int) int {
	// Initialize the index as -1
	index := -1

	// Iterate through each element in the slice
	for i, v := range s {
		// Check if the current element is equal to the given integer
		if v == x {
			// If it is, update the index and break the loop
			index = i
			break
		}
	}

	// Return the index
	return index
}

// Define a helper function 'itertools.Index' to return the index of a given integer in a slice
func Index(s []int, x int) int {
	// Initialize the index as -1
	index := -1

	// Iterate through each element in the slice
	for i, v := range s {
		// Check if the current element is equal to the given integer
		if v == x {
			// If it is, update the index and break the loop
			index = i
			break
		}
	}

	// Return the index
	return index
}

// Define a helper function 'itertools.max' to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Define a helper function 'itertools.Index' to return the index of a given integer in a slice
func Index(s []int, x int) int {
	// Initialize the index as -1
	index := -1

	// Iterate through each element in the slice
	for i, v := range s {
		// Check if the current element is equal to the given integer
		if v == x {
			// If it is, update the index and break the loop
			index = i
			break
		}
	}

	// Return the index
	return index
}

// Define a helper function 'itertools.Index' to return the index of a given integer in a slice
func Index(s []int, x int) int {
	// Initialize the index as -1
	index := -1

	// Iterate through each element in the slice
	for i, v := range s {
		// Check if the current element is equal to the given integer
		if v == x {
			// If it is, update the index and break the loop
			index = i
			break
		}
	}

	// Return the index
	return index
}

// Define a helper function 'itertools.max' to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Define a helper function 'itertools.Index' to return the index of a given integer in a slice
func Index(s []int, x int) int {
	// Initialize the index as -1
	index := -1

	// Iterate through each element in the slice
	for i, v := range s {
		// Check if the current element is equal to the given integer
		if v == x {
			// If it is, update the index and break the loop
			index = i
			break
		}
	}

	// Return the index
	return index
}

// Define a helper