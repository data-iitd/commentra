
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	// Read the elements into a slice and convert them to integers
	aTemp := strings.Split(readLine(reader), " ")
	var a []int32
	for i := 0; i < int(n); i++ {
		aTempItem, err := strconv.ParseInt(aTemp[i], 10, 64)
		checkError(err)
		aTempItem32 := int32(aTempItem)
		a = append(a, aTempItem32)
	}

	// Initialize a slice 'b' with zeros to store the positions of elements
	b := make([]int32, n)

	// Populate the slice 'b' with the indices of elements from slice 'a'
	for i := 0; i < int(n); i++ {
		b[a[i]-1] = int32(i)  // Store the index of each element in 'b' based on its value in 'a'
	}

	// Initialize the result variable to accumulate the total distance
	var res int32

	// Calculate the total distance between consecutive elements in 'b'
	for i := 1; i < int(n); i++ {
		res += int32(abs(int(b[i])-int(b[i-1])))  // Add the absolute difference of indices to the result
	}

	// Print the final result
	fmt.Println(res)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

