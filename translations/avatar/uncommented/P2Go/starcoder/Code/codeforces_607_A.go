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
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	l := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	if l[0] > 0 {
		l[0] = 1
	}
	mx := 0
	for i := 1; i < n; i++ {
		if l[i] == 0 {
			l[i] = l[i-1]
		} else {
			if l[i] >= i {
				l[i] = 1
			} else {
				l[i] = l[i-l[i]-1] + 1
			}
		}
		if l[i] > mx {
			mx = l[i]
	}
	fmt.Println(n - mx)
}

