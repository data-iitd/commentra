
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
	fmt.Print("Enter the number of elements in the list: ")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Print("Enter the list elements: ")
	l1 := make([]int, n)
	for i := 0; i < n; i++ {
		l1[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	sort.Ints(l1)
	a := l1[n-1]
	b := l1[0]
	if a == b {
		fmt.Printf("%d\n", a-b)
		fmt.Printf("%d\n", (n*(n-1))/2)
	} else {
		ac := 0
		bc := 0
		for i := 0; i < n; i++ {
			if l1[i] == a {
				ac++
			}
			if l1[i] == b {
				bc++
			}
		}
		fmt.Printf("%d\n", a-b)
		fmt.Printf("%d\n", ac*bc)
	}
}

