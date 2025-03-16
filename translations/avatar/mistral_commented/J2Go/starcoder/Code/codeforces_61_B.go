// Importing necessary packages
import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strings"
)

// Creating a Main function
func main() {
	// Creating a new Scanner object
	in := bufio.NewScanner(os.Stdin)

	// Reading the first word from the user input
	var word1 string
	in.Scan()
	word1 = strings.ToLower(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(in.Text(), ""))
	// This block of code reads a line from the user input, removes all non-alphabetic characters, and converts it to lowercase.
	// The resulting string is stored in the 'word1' variable.

	// Reading the second word from the user input
	var word2 string
	in.Scan()
	word2 = strings.ToLower(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(in.Text(), ""))
	// This block of code reads a line from the user input, removes all non-alphabetic characters, and converts it to lowercase.
	// The resulting string is stored in the 'word2' variable.

	// Reading the third word from the user input
	var word3 string
	in.Scan()
	word3 = strings.ToLower(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(in.Text(), ""))
	// This block of code reads a line from the user input, removes all non-alphabetic characters, and converts it to lowercase.
	// The resulting string is stored in the 'word3' variable.

	// Creating six permutations of the given words
	perm1 := word1 + word2 + word3
	perm2 := word1 + word3 + word2
	perm3 := word2 + word1 + word3
	perm4 := word2 + word3 + word1
	perm5 := word3 + word2 + word1
	perm6 := word3 + word1 + word2

	// Reading the number of students
	var students int
	in.Scan()
	students, _ = strconv.Atoi(in.Text())
	// This block of code reads an integer value from the user input.
	// The number of students is stored in the'students' variable.

	// Looping through each student's test case
	for i := 0; i < students; i++ {
		// Reading a test case from the user input
		var testCase string
		in.Scan()
		testCase = strings.ToLower(regexp.MustCompile("[^a-zA-Z]").ReplaceAllString(in.Text(), ""))
		// This block of code reads a line from the user input, removes all non-alphabetic characters, and converts it to lowercase.
		// The resulting string is stored in the 'testCase' variable.

		// Checking if the test case matches any of the permutations
		if testCase == perm1 || testCase == perm2 || testCase == perm3 || testCase == perm4 || testCase == perm5 || testCase == perm6 {
			// Printing 'ACC' if the test case matches any of the permutations
			fmt.Println("ACC")
		} else {
			// Printing 'WA' if the test case doesn't match any of the permutations
			fmt.Println("WA")
		}
	}
}

