
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

	// Take the number of elements in the list as input
	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	// Initialize an empty list 'arr' to store the input elements
	arrTemp := strings.Split(readLine(reader), " ")
	var arr []int32
	for _, arrItem := range arrTemp {
		arrItemTemp, err := strconv.ParseInt(arrItem, 10, 64)
		checkError(err)
		arrItemTemp32 := int32(arrItemTemp)
		arr = append(arr, arrItemTemp32)
	}

	// Check if the first element of the list is greater than 15
	if arr[0] > 15 {
		// If it is, print 15
		fmt.Println(15)
	} else {
		// Else, iterate through the list starting from the second element
		for i := 1; i < len(arr); i++ {
			// Check if the difference between the current and previous elements is greater than 15
			if arr[i]-arr[i-1] > 15 {
				// If it is, print the index of the previous element and add 15 to it
				fmt.Println(arr[i-1] + 15)
				// Break the loop as we have found the answer
				break
			}
		}
		// Else, if we reach here, it means that no difference was greater than 15
		if arr[len(arr)-1] == 90 || arr[len(arr)-1]+15 >= 90 {
			// If it is, print 90
			fmt.Println(90)
		} else {
			// Else, print the last element plus 15
			fmt.Println(arr[len(arr)-1] + 15)
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), "\r\n")
	}
	return ""
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

