
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

	// Take an integer input from the user
	y, _ := strconv.Atoi(readLine(reader))

	// Take a list of integers as input from the user
	arr := readLine(reader)
	arrItems := strings.Split(arr, " ")
	arrVar := make([]int32, len(arrItems))
	for i := 0; i < len(arrItems); i++ {
		arrTemp, _ := strconv.ParseInt(arrItems[i], 10, 64)
		arrVar[i] = int32(arrTemp)
	}

	// Iterate through each index 'i' in the list 'arr'
	for i := 0; i < len(arrVar); i++ {
		// Iterate through each index 'j' in the list 'arr' (excluding the current index 'i')
		for j := 0; j < len(arrVar); j++ {
			// Check if the current indices 'i' and 'j' are equal, if yes then skip the current iteration
			if i == j {
				continue
			}
			// Iterate through each index 'k' in the list 'arr' (excluding the indices 'i' and 'j')
			for k := 0; k < len(arrVar); k++ {
				// Check if the current indices 'i', 'j' and 'k' satisfy the given condition
				if arrVar[k]!= arrVar[j] && arrVar[k]!= arrVar[i] && arrVar[k] == arrVar[i]+arrVar[j] {
					// If the condition is true, print the indices 'i', 'j' and 'k' and exit the function
					fmt.Printf("%d %d %d\n", k+1, j+1, i+1)
					return
				}
			}
		}
	}
	// If no such indices are found, print -1
	fmt.Println(-1)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
}
