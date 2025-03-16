
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	n, _ := strconv.Atoi(sc.Text())

	if n == 1 {
		fmt.Println(sc.Text())
		return
	}

	a := make([]int, n)

	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(sc.Text())
	}

	sort.Ints(a)

	if a[len(a)-1] == 0 {
		fmt.Println(0)
		return
	}

	ans := 0

	for {
		if len(a) == 1 {
			ans = a[0]
			break
		}
		a = func(a)
	}

	fmt.Println(ans)
}

func func(A []int) []int {
	a := make([]int, len(A))
	copy(a, A)
	min := 0

	for i := 0; i < len(a); i++ {
		if a[i] == 0 {
			a = append(a[:i], a[i+1:]...)
			i--
		} else {
			if min!= 0 {
				a[i] = a[i] % min
				if a[i] == 1 {
					fmt.Println(1)
					return a
				}
			} else {
				min = a[i]
			}
		}
	}

	sort.Ints(a)
	return a
}

