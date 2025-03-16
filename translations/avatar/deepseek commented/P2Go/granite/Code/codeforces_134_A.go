

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

	// Read the number of elements in the list `w`
	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	// Read `n` integers from the standard input and store them in the list `w`
	wTemp := strings.Split(readLine(reader), " ")
	var w []int32
	for i := 0; i < int(n); i++ {
		wItemTemp, err := strconv.ParseInt(wTemp[i], 10, 64)
		checkError(err)
		wItem := int32(wItemTemp)
		w = append(w, wItem)
	}

	// Calculate the sum of all elements in the list `w`
	x := int32(0)
	for _, wItem := range w {
		x += wItem
	}

	// Initialize an empty list `d` to store the indices of elements that satisfy the condition
	d := []int32{}

	// Iterate over each element in the list `w`
	for i := int32(0); i < int32(n); i++ {
		// Check if the current element `w[i]` is equal to the average of the total sum `x` and the number of elements `n` minus one
		if (x-w[i])/(n-1) == w[i] {
			// Append the 1-based index of the element to the list `d`
			d = append(d, i+1)
		}
	}

	// Print the length of the list `d`
	fmt.Println(len(d))

	// Print the indices in `d` separated by spaces
	fmt.Println(strings.TrimRight(fmt.Sprint(d), "[]"))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}
