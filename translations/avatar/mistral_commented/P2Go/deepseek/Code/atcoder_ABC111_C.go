package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Take the number of elements in the list from user input
	n, _ := strconv.Atoi(readLine(reader))

	// Initialize an empty list 'x' to store the input elements
	x := readIntSlice(reader)

	// Initialize two empty lists 'a' and 'b' to store even and odd elements respectively
	a := []int{}
	b := []int{}

	// Iterate through the list 'x' and append even and odd elements to their respective lists
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			a = append(a, x[i])
		} else {
			b = append(b, x[i])
		}
	}

	// Initialize two lists 'cnta' and 'cntb' of size 100002+1 to store the count of each element in lists 'a' and 'b' respectively
	cnta := make([]int, 100003)
	cntb := make([]int, 100003)

	// Initialize two variables 'vala' and 'valb' to store the elements with maximum count in lists 'a' and 'b' respectively
	var vala, valb int
	var maxCnta, maxCntb int

	// Initialize two variables 'maxCnta1' and 'maxCntb1' to store the second maximum count of an element in lists 'a' and 'b' respectively
	var maxCnta1, maxCntb1 int

	// Iterate through list 'a' and update the count of each element in 'cnta'
	for _, i := range a {
		cnta[i]++
	}

	// Find the element with maximum count in list 'a' and update 'vala' and 'maxCnta'
	for _, i := range a {
		if maxCnta < cnta[i] {
			vala = i
			maxCnta = cnta[i]
		}
	}

	// Find the second element with maximum count in list 'a' (different from 'vala') and update 'vala1' and 'maxCnta1'
	for _, i := range a {
		if maxCnta1 < cnta[i] && i != vala {
			maxCnta1 = cnta[i]
			vala1 := i
		}
	}

	// Similar logic for list 'b'
	for _, i := range b {
		cntb[i]++
	}

	// Find the element with maximum count in list 'b' and update 'valb' and 'maxCntb'
	for _, i := range b {
		if maxCntb < cntb[i] {
			valb = i
			maxCntb = cntb[i]
		}
	}

	// Find the second element with maximum count in list 'b' (different from 'valb') and update 'valb1' and 'maxCntb1'
	for _, i := range b {
		if maxCntb1 < cntb[i] && i != valb {
			maxCntb1 = cntb[i]
			valb1 := i
		}
	}

	// Check if 'vala' and 'valb' are same or not
	if valb != vala {
		// If they are not same, calculate the sum of counts of all elements except 'vala' and 'valb' and print the result
		res := 0
		for _, i := range a {
			if i != vala {
				res++
			}
		}
		for _, i := range b {
			if i != valb {
				res++
			}
		}
		fmt.Println(res)
	} else {
		// If 'vala' and 'valb' are same, calculate the sum of counts of all elements except 'vala' and the second element with maximum count in list 'a' and list 'b' respectively
		// and print the minimum of these two sums
		resa := 0
		resa1 := 0
		resb := 0
		resb1 := 0
		for _, i := range a {
			if i != vala {
				resa++
			}
			if i != vala1 {
				resa1++
			}
		}
		for _, i := range b {
			if i != valb {
				resb++
			}
			if i != valb1 {
				resb1++
			}
		}
		fmt.Println(min(resa+resb1, resa1+resb))
	}
}

// Helper function to read a single line from the reader
func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return strings.TrimRight(string(str), "\r\n")
}

// Helper function to read a slice of integers from the reader
func readIntSlice(reader *bufio.Reader) []int {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	numbers := []int{}
	for _, numStr := range strings.Split(string(str), " ") {
		num, _ := strconv.Atoi(numStr)
		numbers = append(numbers, num)
	}
	return numbers
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

