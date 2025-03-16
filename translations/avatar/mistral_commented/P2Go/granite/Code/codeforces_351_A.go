
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

	// Take an integer input 'n' from the user
	nTemp, err := reader.ReadString('\n')
	checkError(err)
	n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
	checkError(err)

	// Take 'n' floating point numbers as input and store them in a list 'arr'
	arrTemp, err := reader.ReadString('\n')
	checkError(err)
	arrTemp = strings.TrimSpace(arrTemp)
	arrTempSplit := strings.Split(arrTemp, " ")
	var arr []float64
	for _, temp := range arrTempSplit {
		tempFloat, err := strconv.ParseFloat(temp, 64)
		checkError(err)
		arr = append(arr, tempFloat)
	}

	// Filter out the integers from the list 'arr' and sort the remaining floating point numbers
	var arr2 []float64
	for _, temp := range arr {
		if temp-float64(int(temp))!= 0 {
			arr2 = append(arr2, temp-float64(int(temp)))
		}
	}
	arr2 = append(arr2, make([]float64, n-int64(len(arr2)))...)
	arr2 = append(arr2, arr2...)
	arr2 = arr2[:n]

	// Calculate the length of the filtered list 'arr' and assign it to the variable 'o'
	o := 2 * int(n) - len(arr2)

	// Calculate the sum of all the floating point numbers in the list 'arr' and assign it to the variable 'arr_sum'
	arr_sum := 0.0
	for _, temp := range arr2 {
		arr_sum += temp
	}

	// Initialize the variable'res' with a large integer value
	res := int(2e9)

	// Iterate through the range from 0 to n+1
	for i := 0; i <= int(n); i++ {
		// Check if the index 'i' plus the offset 'o' is greater than or equal to 'n'
		if i+o >= int(n) {
			// Update the minimum value of'res' with the absolute difference between 'i' and 'arr_sum'
			res = int(min(float64(i), arr_sum))
		}
	}

	// Print the result with three decimal places
	fmt.Printf("%.3f\n", float64(res))
}

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

