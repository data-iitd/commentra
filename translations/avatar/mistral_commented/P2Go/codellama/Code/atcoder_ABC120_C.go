// Import necessary libraries and modules
import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"sort"
	"strings"
)

// Set up input reading functions
var (
	read = bufio.NewReader(os.Stdin).Read
	readline = bufio.NewReader(os.Stdin).ReadString
	readlines = bufio.NewReader(os.Stdin).ReadBytes
)

// Define constants
const (
	INF = float("inf")
	MOD = 1000000007
)

// Define main function
func main() {
	// Read input string
	s := readline()

	// Check if all characters in the string are the same
	if len(strings.Split(s, "")) == 1 {
		// If so, print 0 and exit
		fmt.Println(0)
		os.Exit(0)
	}

	// Count the occurrences of each character in the string
	a := make(map[string]int)
	for _, c := range s {
		a[string(c)]++
	}

	// Calculate the answer
	ans := 0
	for _, v := range a {
		if v > ans {
			ans = v
		}
	}
	ans *= 2

	// Print the answer
	fmt.Println(ans)
}

// Call the main function if the script is run as the main program
func init() {
	main()
}

