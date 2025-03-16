
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

	// Reading the first line of input which contains the number of elements 'n' in the list 'w'
	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
	checkError(err)

	// Reading the second line of input which contains the elements of the list 'w' separated by spaces
	wTemp, err := reader.ReadString('\n')
	checkError(err)
	wTemp = strings.TrimSpace(wTemp)
	w := strings.Split(wTemp, " ")

	// Initializing an empty list 'd' to store the indices of the elements that satisfy the condition
	var d []int

	// Iterating through each element 'i' in the list 'w'
	for i := 0; i < int(n); i++ {
		// Converting the current element 'w[i]' to an integer
		w[i], err = strconv.Atoi(w[i])
		checkError(err)

		// Calculating the average of the remaining sum of elements after removing the current element 'w[i]'
		// and checking if it's equal to the current element 'w[i]'
		if (x-w[i])/(n-1) == w[i] {
			// If the condition is true, append the index 'i+1' to the list 'd'
			d = append(d, i+1)
		}
	}

	// Printing the length of the list 'd'
	fmt.Println(len(d))

	// Printing the elements of the list 'd' separated by a space
	fmt.Println(strings.Trim(fmt.Sprint(d), "[]"))
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

