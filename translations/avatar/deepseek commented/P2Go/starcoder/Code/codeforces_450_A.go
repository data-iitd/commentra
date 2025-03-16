
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
	fmt.Println("Enter the length of the list")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the divisor")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the list")
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	l2 := make([]int, n)
	for i := 0; i < n; i++ {
		if l[i]%m == 0 {
			l2[i] = l[i] / m
		} else {
			l2[i] = l[i] / m + 1
		}
	}
	mx := 0
	for i := 0; i < n; i++ {
		if l2[i] > mx {
			mx = l2[i]
		}
	}
	for i := 0; i < n; i++ {
		if l2[i] == mx {
			fmt.Println(i + 1)
			break
		}
	}
}

