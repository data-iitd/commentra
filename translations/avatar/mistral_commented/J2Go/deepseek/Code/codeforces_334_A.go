package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initializing scanner for input and PrintWriter for output
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	pw := bufio.NewWriter(os.Stdout)

	// Reading the number 'n' from the user
	in.Scan()
	n := parseInt(in.Text())

	// Calculating the square of the number 'n'
	square := n * n

	// Creating empty slices for odd and even numbers
	odd := []int{}
	even := []int{}

	// Looping from 1 to square
	for i := 1; i <= square; i++ {
		if i%2 == 0 {
			// If the number is even, add it to the even slice
			even = append(even, i)
		} else {
			// If the number is odd, add it to the odd slice
			odd = append(odd, i)
		}
	}

	// Calculating the number of pairs to be printed
	loop := square / n
	div := loop / 2

	// Looping through each pair
	for i := 1; i <= loop; i++ {
		// Looping through half of the pair
		for j := 0; j < div; j++ {
			if i%2 == 1 {
				// If the current pair is odd, print the first and last numbers of the current pair
				fmt.Fprint(pw, odd[0], " ", even[len(even)-1], " ")
				odd = odd[1:]
				even = even[:len(even)-1]
			} else {
				// If the current pair is even, print the last and first numbers of the current pair
				fmt.Fprint(pw, even[0], " ", odd[len(odd)-1], " ")
				even = even[1:]
				odd = odd[:len(odd)-1]
			}
		}
		fmt.Fprintln(pw) // Printing a newline after each pair
	}

	pw.Flush() // Flushing the writer after printing all the pairs
}

// Helper function to parse string to int
func parseInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}
