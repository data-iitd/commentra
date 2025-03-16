
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
	fmt.Println("Enter the value of n:")
	n, _ := reader.ReadString('\n')
	n = strings.TrimSpace(n)
	nInt, _ := strconv.Atoi(n)

	fmt.Println("Enter the value of m:")
	m, _ := reader.ReadString('\n')
	m = strings.TrimSpace(m)
	mInt, _ := strconv.Atoi(m)

	a := make([]int, mInt)
	if nInt%mInt == 0 {
		for i := 0; i < len(a); i++ {
			a[i] = nInt / mInt
		}
	} else {
		sub := nInt / mInt
		for i := 0; i < len(a); i++ {
			a[i] = sub
		}
		test := nInt - (sub * mInt)
		count := 0
		for i := 0; i < test; i++ {
			a[count] = a[count] + 1
			count++
			if count > len(a) {
				count = 0
			}
		}
	}

	for i := len(a) - 1; i >= 0; i-- {
		fmt.Printf("%d ", a[i])
	}
	fmt.Println()
}

