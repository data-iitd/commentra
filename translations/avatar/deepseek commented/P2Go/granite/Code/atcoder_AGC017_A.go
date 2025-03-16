
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Read the values of N and P from input
	N, P := readIntPair()

	// Define a function to calculate the binomial coefficient
	combi := func(N, K int) int {
		a := 1
		// Calculate the product part of the binomial coefficient
		for i := 0; i < K; i++ {
			a *= N - i
		}
		// Calculate the division part of the binomial coefficient
		for j := 0; j < K; j++ {
			a /= j + 1
		}
		return a
	}

	// Read a list of integers from input
	ans := 0
	lis := readIntList()

	// Create a new list where each element is the remainder when divided by 2
	ls := make([]int, 0)
	for _, a := range lis {
		ls = append(ls, a%2)
	}

	// Count the number of 1s and 0s in the list
	one := 0
	zero := 0
	for _, a := range ls {
		if a == 1 {
			one++
		} else {
			zero++
		}
	}

	// Initialize variables to store the number of patterns
	patternA := 0
	patternB := 0

	// Calculate the number of patterns with `j` zeros using the combi function
	for j := 0; j <= zero; j++ {
		patternB += combi(zero, j)
	}

	// Initialize time to 0 for the while loop
	time := 0

	// Calculate the number of patterns with `time` ones, considering the parity with P
	for time <= one {
		if time%2 == P {
			patternA += combi(one, time)
		}
		time++
	}

	// Print the result as an integer by multiplying patternA and patternB
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

func readIntPair() (int, int) {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n1, n2 int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n1)
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n2)
	return n1, n2
}

func readIntList() []int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var nList []int
	for sc.Scan() {
		n, _ := strconv.Atoi(sc.Text())
		nList = append(nList, n)
	}
	return nList
}

func readString() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var str string
	sc.Scan()
	str = sc.Text()
	return str
}

func readStringList() []string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var strList []string
	for sc.Scan() {
		strList = append(strList, sc.Text())
	}
	return strList
}

