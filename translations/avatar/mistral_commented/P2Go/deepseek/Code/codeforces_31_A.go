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
	arrStr, _ := reader.ReadString('\n')
	arrStr = strings.TrimSpace(arrStr)
	arrStrSlice := strings.Split(arrStr, " ")
	arr := make([]int, len(arrStrSlice))
	for i := 0; i < len(arrStrSlice); i++ {
		arr[i], _ = strconv.Atoi(arrStrSlice[i])
	}
	
	// Iterate through each index 'i' in the list 'arr'
	for i := 0; i < len(arr); i++ {
		// Iterate through each index 'j' in the list 'arr' (excluding the current index 'i')
		for j := 0; j < len(arr); j++ {
			// Check if the current indices 'i' and 'j' are equal, if yes then skip the current iteration
			if i == j {
				continue
			}
			// Iterate through each index 'k' in the list 'arr' (excluding the indices 'i' and 'j')
			for k := 0; k < len(arr); k++ {
				// Check if the current indices 'i', 'j' and 'k' satisfy the given condition
				if arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j] {
					// If the condition is true, print the indices 'i', 'j' and 'k' and exit the function
					fmt.Println(k + 1, j + 1, i + 1)
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
	if err != nil {
		panic(err)
	}
	return string(str)
}
