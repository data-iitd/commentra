package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of test cases

	a := make([]int, n+1) // Creating an integer slice 'a' of size 'n+1'
	b := make([]int, n+1) // Creating an integer slice 'b' of size 'n+1'
	num := make([]int, n+1) // Creating an integer slice 'num' of size 'n+1'

	for i := 1; i <= n; i++ { // Loop to read the elements of slices 'a' and 'b'
		fmt.Scan(&a[i], &b[i])
	}

	ss := "" // Initializing an empty string 'ss' to store the final answer
	ans := 0 // Initializing an integer variable 'ans' to store the maximum length of the answer
	st := make([]bool, n+1) // Creating a boolean slice 'st' of size 'n+1'

	for i := 1; i <= n; i++ { // Loop to find the longest chain of numbers
		if a[i] == 1 { // If the current number 'i' in slice 'a' is 1
			st[i] = true // Mark the current number as visited
			sb := strings.Builder{} // Creating a strings.Builder object 'sb' to store the answer
			x := b[i] // Assigning the value of 'b[i]' to 'x'
			sss := strings.Builder{} // Creating a strings.Builder object 'sss' to store the current number 'i'
			sss.WriteString(fmt.Sprintf("%d", i)) // Appending the current number 'i' to 'sss'
			sb.WriteString(" " + reverse(sss.String())) // Appending the reversed string of 'sss' to 'sb'
			s := 1 // Initializing an integer variable 's' to 1

			for !st[x] && num[x] == 1 && x != 0 && a[x] != 1 { // Loop to traverse the graph
				sss = strings.Builder{} // Creating a new strings.Builder object 'sss' to store the current number
				sss.WriteString(fmt.Sprintf("%d", x)) // Appending the current number 'x' to 'sss'
				sb.WriteString(" " + reverse(sss.String())) // Appending the reversed string of 'sss' to 'sb'
				st[x] = true // Marking the current number 'x' as visited
				x = b[x] // Assigning the value of 'b[x]' to 'x'
				s++ // Incrementing the length of the current chain
			}

			if s > ans { // If the length of the current chain is greater than the current maximum length
				ans = s // Updating the maximum length
				ss = reverse(sb.String()) // Updating the final answer
			}
		}
	}

	fmt.Println(ans) // Printing the maximum length of the longest chain
	fmt.Println(ss) // Printing the longest chain as a string
}

// Function to reverse a string
func reverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}
