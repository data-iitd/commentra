
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input which represents the number of elements in the lists
	reader := bufio.NewReader(os.Stdin)
	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
	checkError(err)

	// Read three lists of integers from input
	aTemp, err := reader.ReadString('\n')
	checkError(err)
	aTemp = strings.TrimSpace(aTemp)
	aTemp = strings.Replace(aTemp, "\n", " ", -1)
	a := strings.Split(aTemp, " ")

	bTemp, err := reader.ReadString('\n')
	checkError(err)
	bTemp = strings.TrimSpace(bTemp)
	bTemp = strings.Replace(bTemp, "\n", " ", -1)
	b := strings.Split(bTemp, " ")

	cTemp, err := reader.ReadString('\n')
	checkError(err)
	cTemp = strings.TrimSpace(cTemp)
	cTemp = strings.Replace(cTemp, "\n", " ", -1)
	c := strings.Split(cTemp, " ")

	// Initialize variables to hold the sum of each list
	x := int64(0)
	y := int64(0)
	z := int64(0)

	// Calculate the sum of elements in list 'a'
	for _, aI := range a {
		aI64, err := strconv.ParseInt(aI, 10, 64)
		checkError(err)
		x += aI64
	}

	// Calculate the sum of elements in list 'b'
	for _, bI := range b {
		bI64, err := strconv.ParseInt(bI, 10, 64)
		checkError(err)
		y += bI64
	}

	// Calculate the sum of elements in list 'c'
	for _, cI := range c {
		cI64, err := strconv.ParseInt(cI, 10, 64)
		checkError(err)
		z += cI64
	}

	// Print the absolute difference between the sums of list 'a' and list 'b'
	fmt.Println(int32(abs(x-y)))

	// Print the absolute difference between the sums of list 'b' and list 'c'
	fmt.Println(int32(abs(y-z)))
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}
