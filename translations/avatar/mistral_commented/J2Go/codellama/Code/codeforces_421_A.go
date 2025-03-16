// Import necessary packages
import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Create the main function
func main() {
	// Declare and initialize variables
	var n, a, b int
	var list1, list2 []int

	// Read the number of test cases
	fmt.Scan(&n)

	// Read the number of elements in the first list
	fmt.Scan(&a)

	// Read the number of elements in the second list
	fmt.Scan(&b)

	// Create slices to store the lists
	list1 = make([]int, a)
	list2 = make([]int, b)

	// Read and store the elements of the first and second lists
	for i := 0; i < a; i++ {
		fmt.Scan(&list1[i])
	}
	for i := 0; i < b; i++ {
		fmt.Scan(&list2[i])
	}

	// Iterate through the input array and print the corresponding number based on the presence of the element in list1
	for i := 0; i < n; i++ {
		if contains(list1, i+1) { // Check if the current input element is present in list1
			fmt.Printf("1 ") // If present, print 1
		} else {
			fmt.Printf("2 ") // If not present, print 2
		}
	}
}

// Define the contains function
func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

