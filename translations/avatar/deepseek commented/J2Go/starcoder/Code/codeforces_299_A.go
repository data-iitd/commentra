
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	n, _ := strconv.Atoi(input)
	a := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		fmt.Printf("Enter the %d element: ", i+1)
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		a[i], _ = strconv.Atoi(input)
	}
	sort.Ints(a)
	min := a[0]
	for _, value := range a {
		if value%min!= 0 {
			fmt.Println(-1)
			return
		}
	}
	fmt.Println(min)
}

