
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Function to read a single line of input and convert it to a tuple of integers
func value() (a int, b int) {
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d", &a, &b)
	return
}

// Function to read a single line of input from stdin and convert it to a tuple of integers
func values() (a int, b int) {
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d%d", &a, &b)
	return
}

// Function to read a single line of input and return a list of integers
func inlst() (a []int) {
	res := bytes.Split(bufio.NewReader(os.Stdin).ReadBytes('\n')[0], []byte{' '})
	for _, v := range res {
		num, _ := strconv.Atoi(string(v))
		a = append(a, num)
	}
	return
}

// Function to read a single line of input from stdin and return a list of integers
func inlsts() (a []int) {
	res := bytes.Split(bufio.NewReader(os.Stdin).ReadBytes('\n')[0], []byte{' '})
	for _, v := range res {
		num, _ := strconv.Atoi(string(v))
		a = append(a, num)
	}
	return
}

// Function to read a single integer from input
func inp() (a int) {
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &a)
	return
}

// Function to read a single integer from stdin
func inps() (a int) {
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &a)
	return
}

// Function to read a single line of input and return it as a string
func instr() string {
	return string(bufio.NewReader(os.Stdin).ReadBytes('\n')[0])
}

// Function to read a single line of input and return it as a list of strings
func stlst() (a []string) {
	res := bytes.Split(bufio.NewReader(os.Stdin).ReadBytes('\n')[0], []byte{' '})
	for _, v := range res {
		str := string(v)
		a = append(a, str)
	}
	return
}

// Helper function to determine if a specific arrangement is possible
func help(a int, b int, l []int) bool {
	tot := make([][]int, b)
	// Create sublists of length 'a' from the list 'l'
	for i := 0; i < b; i++ {
		tot[i] = l[i*a : i*a+a]
	}

	// Check if any combination of the sublists sums to 'b'
	for _, v := range bytes.Transpose(tot) {
		sum := 0
		for _, val := range v {
			sum += val
		}
		if sum == b {
			return true
		}
	}
	return false
}

// Main function to solve the problem
func solve() {
	tot := make([]string, 0)
	x := instr() // Read the input string
	s := make([]int, 0)

	// Convert the input string into a list of integers (0 for 'O', 1 for 'X')
	for _, v := range x {
		if v == 'O' {
			s = append(s, 0)
		} else {
			s = append(s, 1)
		}
	}

	// Check for all divisors of 12 to find valid arrangements
	for i := 1; i < 13; i++ {
		if 12%i == 0 { // Check if 'i' is a divisor of 12
			if help(i, 12/i, s) { // Use the helper function to check arrangements
				tot = append(tot, fmt.Sprintf("%dx%d", 12/i, i)) // Store valid arrangements as strings
			}
		}
	}

	// Print the number of valid arrangements
	fmt.Printf("%d ", len(tot))
	// Print each valid arrangement in sorted order
	for _, v := range tot {
		fmt.Printf("%s ", v)
	}
	fmt.Println() // Print a newline at the end
}

// Entry point of the program
func main() {
	// Read the number of test cases and solve each case
	for i := 0; i < inp(); i++ {
		solve()
	}
}

