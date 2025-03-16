package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := fmt.Sscanf(scanner.Text(), "%d", &n)
	if n != 1 {
		fmt.Println("Invalid input")
		return
	}

	arr := make([]int, n)
	sum := 0
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &arr[i])
		sum += arr[i]
	}

	c := 0
	var sb []string
	for i := 0; i < n; i++ {
		if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] {
			c++
			sb = append(sb, fmt.Sprintf("%d", i+1))
		}
	}
	fmt.Println(c)
	fmt.Println(fmt.Sprintf("[%s]", strings.Join(sb, " ")))
}
