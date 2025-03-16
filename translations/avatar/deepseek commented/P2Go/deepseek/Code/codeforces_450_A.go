package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read two integers n and m from input
	line1, _ := reader.ReadString('\n')
	line1 = line1[:len(line1)-1] // Remove the newline character
	nAndM := strings.Split(line1, " ")
	n, _ := strconv.Atoi(nAndM[0])
	m, _ := strconv.Atoi(nAndM[1])
	
	// Read a list of integers
	line2, _ := reader.ReadString('\n')
	line2 = line2[:len(line2)-1] // Remove the newline character
	lStr := strings.Split(line2, " ")
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(lStr[i])
	}
	
	// Initialize an empty list to store the results
	l2 := make([]int, n)
	
	// Iterate over each element in the list l
	for _, i := range l {
		if i % m == 0 { // Check if the element is divisible by m
			l2 = append(l2, i / m) // Append the quotient to l2
		} else {
			l2 = append(l2, i / m + 1) // Append the quotient plus one to l2
		}
	}
	
	// Find the maximum value in l2
	mx := l2[0]
	for _, v := range l2 {
		if v > mx {
			mx = v
		}
	}
	
	// Iterate over l2 to find the index of the maximum value
	ind := 0
	for i, v := range l2 {
		if v == mx {
			ind = i
			break
		}
	}
	
	// Print the index of the maximum value plus one
	fmt.Println(ind + 1)
}
