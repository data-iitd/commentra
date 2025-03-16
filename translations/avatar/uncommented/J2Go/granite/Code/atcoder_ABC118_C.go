
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
	a := make([]int, n)
	if n == 1 {
		fmt.Println(reader.ReadLine()[2 : len(reader.ReadLine())-1])
		return
	}
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
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
			var min int
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							os.Exit(0)
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

