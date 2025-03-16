
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

	// Read the number of elements
	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
	checkError(err)

	// Read the list of integers
	wTemp, err := reader.ReadString('\n')
	checkError(err)
	wTemp = strings.TrimSpace(wTemp)
	w := strings.Split(wTemp, " ")

	// Calculate the sum of the list
	x := 0
	for _, wTemp := range w {
		wTempInt, err := strconv.ParseInt(wTemp, 10, 64)
		checkError(err)
		x += int(wTempInt)
	}

	// Initialize an empty list to store indices
	d := []int{}

	// Iterate through each element in the list
	for i, wTemp := range w {
		wTempInt, err := strconv.ParseInt(wTemp, 10, 64)
		checkError(err)

		// Check if removing the current element results in an average equal to the current element
		if (x - int(wTempInt))/(n-1) == wTempInt {
			// If the condition is met, append the 1-based index to the list
			d = append(d, i+1)
		}
	}

	// Print the number of valid indices found
	fmt.Println(len(d))

	// Print the valid indices as a space-separated string
	fmt.Println(strings.Join(intSliceToStringSlice(d), " "))
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func intSliceToStringSlice(s []int) []string {
	ss := make([]string, len(s))
	for i, v := range s {
		ss[i] = strconv.Itoa(v)
	}
	return ss
}
