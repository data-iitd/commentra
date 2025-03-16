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
	a := make([]int, n)
	if n == 1 {
		fmt.Println("Enter the element")
		a[0], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		fmt.Println(a[0])
		return
	}
	fmt.Println("Enter the elements")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	sort.Ints(a)
	if a[n-1] == 0 {
		fmt.Println(0)
		return
	}
	ans := 0
	for {
		if len(a) == 1 {
			ans = a[0]
			break
		}
		a = func(a []int) []int {
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
		}(a)
	}
	fmt.Println(ans)
}

