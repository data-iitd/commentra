
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var y int
	var arr []int
	var i, j, k int
	var sum int
	var found bool

	// Take an integer input for variable y
	fmt.Scanln(&y)

	// Take a list of integers as input and store it in arr
	reader := bufio.NewReader(os.Stdin)
	line, _, _ := reader.ReadLine()
	arr = make([]int, 0)
	for _, s := range strings.Split(string(line), " ") {
		i, _ = strconv.Atoi(s)
		arr = append(arr, i)
	}

	// Iterate through the list arr using three nested loops
	for i = 0; i < len(arr); i++ {
		for j = 0; j < len(arr); j++ {
			if i == j {
				continue
			}
			for k = 0; k < len(arr); k++ {
				if arr[k]!= arr[j] && arr[k]!= arr[i] && arr[k] == arr[i] + arr[j] {
					// Check if arr[k] is the sum of arr[i] and arr[j] and different from both
					fmt.Println(k+1, j+1, i+1)
					found = true
					break
				}
			}
			if found {
				break
			}
		}
		if found {
			break
		}
	}
	if!found {
		fmt.Println(-1)
	}
}

