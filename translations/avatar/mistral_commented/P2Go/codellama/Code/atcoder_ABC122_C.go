// Importing fmt package for using Println function
import "fmt"

// Taking input for number of strings 'n' and number of problems 'q'
var n, q int
fmt.Scan(&n, &q)

// Taking input for the string 's'
var s string
fmt.Scan(&s)

// List comprehension to create a list 'problems' of lists containing start and end indices of each problem
problems := make([][]int, q)
for i := 0; i < q; i++ {
	problems[i] = make([]int, 2)
	fmt.Scan(&problems[i][0], &problems[i][1])
}

// Function definition for counting the number of 'AC' substrings in the given string 's'
// The function takes two arguments: 'total' which is the current sum of 'AC' substrings and 'i' which is the index of the current character
func count(total int, i int) int {
	// Return the sum of 'total' and 1 if the substring from index 'i-1' to 'i+1' is 'AC'
	if s[i-1:i+1] == "AC" {
		return total + 1
	}
	return total
}

// Using accumulate function to calculate the cumulative sum of 'AC' substrings in the string 's'
cumsum := make([]int, n)
for i := 1; i < n; i++ {
	cumsum[i] = count(cumsum[i-1], i)
}

// Iterating through each problem in the list 'problems' and printing the difference between the cumulative sum at the end and start of the problem
for _, problem := range problems {
	// Print the difference between the cumulative sum at the end and start of the problem
	fmt.Println(cumsum[problem[1]-1] - cumsum[problem[0]-1])
}

