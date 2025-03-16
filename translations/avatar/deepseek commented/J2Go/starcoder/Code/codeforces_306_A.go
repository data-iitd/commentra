
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
	fmt.Println("Enter the value of n and m")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	n, _ := strconv.Atoi(input)
	input, _ = reader.ReadString('\n')
	input = strings.TrimSpace(input)
	m, _ := strconv.Atoi(input)
	a := make([]int, m)
	if n%m == 0 {
		for i := 0; i < m; i++ {
			a[i] = n / m
		}
	} else {
		sub := n / m
		for i := 0; i < m; i++ {
			a[i] = sub
		}
		test := n - (sub * m)
		count := 0
		for i := 0; i < test; i++ {
			a[count] = a[count] + 1
			count++
			if count >= m {
				count = 0
			}
		}
	}
	for i := m - 1; i >= 0; i-- {
		fmt.Print(a[i], " ")
	}
}

