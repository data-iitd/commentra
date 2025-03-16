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
	fmt.Println("Enter the number of elements to be deleted")
	k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	l := 0
	c := 1
	for i := 0; i < n; i++ {
		a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		if a == l {
			c += 1
		} else {
			c = 1
		}
		l = a
	}
	if c+k > n {
		fmt.Println(n - c)
	} else {
		fmt.Println(-1)
	}
}

