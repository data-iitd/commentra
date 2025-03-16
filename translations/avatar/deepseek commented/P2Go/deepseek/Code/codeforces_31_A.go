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
	
	// Read integer input for variable y
	y, _ := strconv.Atoi(readLine(reader))
	
	// Read list of integers as input and store it in arr
	arrStr, _ := reader.ReadString('\n')
	arrStr = strings.TrimSpace(arrStr)
	arrStrSlice := strings.Split(arrStr, " ")
	arr := make([]int, len(arrStrSlice))
	for i := 0; i < len(arrStrSlice); i++ {
		arr[i], _ = strconv.Atoi(arrStrSlice[i])
	}
	
	// Iterate through the list arr using three nested loops
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr); j++ {
			if i == j {
				continue // Skip if i and j are the same index
			}
			for k := 0; k < len(arr); k++ {
				if arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j] {
					// Check if arr[k] is the sum of arr[i] and arr[j] and different from both
					fmt.Println(k + 1, j + 1, i + 1) // Print the positions of arr[k], arr[j], and arr[i] (1-indexed)
					return // Exit the program
				}
			}
		}
	}
	fmt.Println(-1) // Print -1 if no such element is found
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return string(str)
}
