// Importing the "fmt" and "sort" packages to use the Println and Sort functions
import (
	"fmt"
	"sort"
)

// Define a function named 'run' that takes two arguments 's' and 't'
func run(s, t string) string {
	// Using the Sort function to sort the list of occurrences of characters in string 's'
	// and storing the result in a slice
	ss := sort.IntSlice(make([]int, 0))
	for _, v := range s {
		ss = append(ss, int(v))
	}
	sort.Sort(ss)

	// Using the Sort function to sort the list of occurrences of characters in string 't'
	// and storing the result in a slice
	tt := sort.IntSlice(make([]int, 0))
	for _, v := range t {
		tt = append(tt, int(v))
	}
	sort.Sort(tt)

	// Comparing the sorted slices of occurrences of characters in strings 's' and 't'
	// If they are equal, then the strings have the same frequency distribution of characters
	// and thus are identical, so return 'Yes'
	// Otherwise, return 'No'
	if ss.Equal(tt) {
		return "Yes"
	} else {
		return "No"
	}
}

// Define a function named 'main' that takes no arguments
func main() {
	// Taking input strings 's' and 't' from the user
	var s, t string
	fmt.Scan(&s, &t)

	// Calling the 'run' function with strings 's' and 't' as arguments and printing the result
	fmt.Println(run(s, t))
}

// If the script is run as the main program, then call the 'main' function
func init() {
	main()
}

