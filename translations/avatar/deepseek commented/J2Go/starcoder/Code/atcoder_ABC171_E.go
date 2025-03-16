
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
	fmt.Println("Enter the number of elements in the array:")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	a := make([]int, n)
	fmt.Println("Enter the elements of the array:")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	r := 0
	for i := 0; i < n; i++ {
		r ^= a[i]
	}
	fmt.Println("The result of XOR operation for each element in the array is:")
	for i := 0; i < n; i++ {
		if i!= 0 {
			fmt.Print(" ")
		}
		fmt.Print(r ^ a[i])
	}
}

