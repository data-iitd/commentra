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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the array elements")
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	if arr[0] > 15 {
		fmt.Println(15)
	} else {
		for i := 1; i < len(arr); i++ {
			if arr[i] - arr[i-1] > 15 {
				fmt.Println(arr[i-1] + 15)
				break
			}
		}
		if arr[len(arr)-1] == 90 || arr[len(arr)-1] + 15 >= 90 {
			fmt.Println(90)
		} else {
			fmt.Println(arr[len(arr)-1] + 15)
		}
	}
}

