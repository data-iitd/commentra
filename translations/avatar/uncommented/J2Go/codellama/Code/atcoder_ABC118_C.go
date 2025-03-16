
package main

import (
	"fmt"
	"os"
	"sort"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	a := make([]int, n)
	if n == 1 {
		sc.Scan()
		fmt.Println(sc.Text())
		os.Exit(0)
	}
	for i := 0; i < n; i++ {
		sc.Scan()
		a[i], _ = strconv.Atoi(sc.Text())
	}
	sort.Ints(a)
	if a[len(a)-1] == 0 {
		fmt.Println(0)
		os.Exit(0)
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
					if min != 0 {
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

func func(a []int) []int {
	min := 0
	for i := 0; i < len(a); i++ {
		if a[i] == 0 {
			a = append(a[:i], a[i+1:]...)
			i--
		} else {
			if min != 0 {
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
}

