
package main

import "fmt"

func main() {
	soz := input()
	a := make([]int, len(soz)+1)
	for i := 1; i < len(soz); i++ {
		a[i] = a[i-1]
		if soz[i-1] == soz[i] {
			a[i] += 1
		}
	}
	n := input()
	arr := make([]int, 0)
	for i := 0; i < n; i++ {
		m, l := input()
		arr = append(arr, a[l-1]-a[m-1])
	}
	for _, v := range arr {
		fmt.Println(v)
	}
}

func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

