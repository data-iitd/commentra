package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initialize an empty list `L`
	L := []int{}

	// Read the first input, which is the number of elements to add to the list
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &r)

	// Use a for loop to iterate through each integer in the input
	for _, k := range strings.Split(readLine(reader), " ") {
		// Add `r` elements to the list `L` with the value `r`
		num, _ := strconv.Atoi(k)
		L = append(L, r*num)
		// Increment the value of `r` by 1 to prepare for the next iteration
		r += 1
	}

	// Read the second input, which represents the indices of the elements to print from the list
	fmt.Fscanln(reader, &r)

	// Use another for loop to iterate through each integer in the input
	for _, j := range strings.Split(readLine(reader), " ") {
		// Print the element at the given index using the index as an offset from the beginning of the list
		index, _ := strconv.Atoi(j)
		fmt.Println(L[index-1])
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}
