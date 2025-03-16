
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read two integers N and P from input
	N, P := readTwoInt()

	// Function to calculate combinations C(N, K)
	combi := func(N, K int) float64 {
		a := 1.0
		// Calculate the numerator of the combination formula
		for i := 0; i < K; i++ {
			a *= float64(N - i)
		}
		// Calculate the denominator of the combination formula
		for j := 0; j < K; j++ {
			a /= float64(j + 1)
		}
		return a
	}

	// Initialize the answer variable
	ans := 0

	// Read a list of integers from input
	lis := readNInt()

	// Create a list to hold the parity (0 or 1) of each number
	ls := make([]int, 0)
	for _, a := range lis {
		// Append the remainder when divided by 2 (0 for even, 1 for odd)
		ls = append(ls, a%2)
	}

	// Count the number of 1s (odd numbers) and 0s (even numbers) in the list
	one := 0
	zero := 0
	for _, v := range ls {
		if v == 1 {
			one++
		} else {
			zero++
		}
	}

	// Initialize variables to count patterns
	patternA := 0
	patternB := 0

	// Calculate the total number of patterns for the even numbers
	for j := 0; j <= zero; j++ {
		patternB += int(combi(float64(zero), float64(j)))
	}

	// Initialize a variable to track the number of odd numbers used
	time := 0

	// Loop through all possible counts of odd numbers used
	for time <= one {
		// Check if the current count of odd numbers is congruent to P modulo 2
		if time%2 == P {
			// If it is, add the number of combinations to pattern_a
			patternA += int(combi(float64(one), float64(time)))
		}
		time++
	}

	// Print the final result, which is the product of pattern_a and pattern_b
	fmt.Println(patternA * patternB)
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	return n
}

func readTwoInt() (int, int) {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n1, n2 int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n1)
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n2)
	return n1, n2
}

func readNInt() []int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	res := make([]int, 0)
	for i := 0; i < n; i++ {
		sc.Scan()
		v, _ := strconv.Atoi(sc.Text())
		res = append(res, v)
	}
	return res
}

func readOneLine() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var str string
	sc.Scan()
	str = sc.Text()
	return str
}

