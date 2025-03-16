
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

// Function to check if the given indices (i, j) are within the bounds of a grid of size n x m
func valid(i, j, n, m int) bool {
	if i < n && i >= 0 && j >= 0 && j < m {
		return true
	}
	return false
}

// Function to calculate the sum of integers from i to n using the formula for the sum of an arithmetic series
func sumn(i, n int) int {
	return (n - i) * (i + n) / 2
}

// Function to solve a quadratic equation ax^2 + bx + c = 0 and return one of its roots
func sqfun(a, b, c int) float64 {
	return (-b + math.Sqrt(float64(b*b-4*a*c))) / (2 * float64(a))
}

// Function to read a single line of input and return it as a tuple of integers
func value() (int, int) {
	temp := bufio.NewScanner(os.Stdin)
	temp.Scan()
	line := temp.Text()
	x, y := 0, 0
	fmt.Sscanf(line, "%d %d", &x, &y)
	return x, y
}

// Function to read a single line of input from stdin and return it as a tuple of integers
func values() (int, int) {
	temp := bufio.NewScanner(os.Stdin)
	temp.Scan()
	line := temp.Text()
	x, y := 0, 0
	fmt.Sscanf(line, "%d %d", &x, &y)
	return x, y
}

// Function to read a single line of input and return it as a list of integers
func inlst() []int {
	temp := bufio.NewScanner(os.Stdin)
	temp.Scan()
	line := temp.Text()
	var a []int
	for _, x := range bytes.Split([]byte(line), []byte{' '}) {
		a = append(a, int(x[0]-'0'))
	}
	return a
}

// Function to read a single line of input from stdin and return it as a list of integers
func inlsts() []int {
	temp := bufio.NewScanner(os.Stdin)
	temp.Scan()
	line := temp.Text()
	var a []int
	for _, x := range bytes.Split([]byte(line), []byte{' '}) {
		a = append(a, int(x[0]-'0'))
	}
	return a
}

// Function to read a single integer from input
func inp() int {
	temp := bufio.NewScanner(os.Stdin)
	temp.Scan()
	line := temp.Text()
	x := 0
	fmt.Sscanf(line, "%d", &x)
	return x
}

// Function to read a single integer from stdin
func inps() int {
	temp := bufio.NewScanner(os.Stdin)
	temp.Scan()
	line := temp.Text()
	x := 0
	fmt.Sscanf(line, "%d", &x)
	return x
}

// Function to read a single line of input and return it as a string
func instr() string {
	temp := bufio.NewScanner(os.Stdin)
	temp.Scan()
	return temp.Text()
}

// Function to read a single line of input and return it as a list of strings
func stlst() []string {
	temp := bufio.NewScanner(os.Stdin)
	temp.Scan()
	line := temp.Text()
	var a []string
	for _, x := range bytes.Split([]byte(line), []byte{' '}) {
		a = append(a, string(x))
	}
	return a
}

// Main function to solve the problem
func solve() {
	l := make([]string, 3)
	// Read three lines of input, process them, and store the results in a list
	for i := 0; i < 3; i++ {
		l[i] = instr()
	}

	// Generate all permutations of the processed strings
	t := bytes.NewBufferString("")
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if i!= j {
				for k := 0; k < 3; k++ {
					if k!= i && k!= j {
						t.WriteString(l[i])
						t.WriteString(l[j])
						t.WriteString(l[k])
					}
				}
			}
		}
	}

	// Read the number of test cases and check if the processed input is in the list of permutations
	for i := 0; i < inp(); i++ {
		if instr() == t.String() {
			fmt.Println("ACC") // Accepted
		} else {
			fmt.Println("WA") // Wrong Answer
		}
	}
}

// Entry point of the program
func main() {
	solve()
}

