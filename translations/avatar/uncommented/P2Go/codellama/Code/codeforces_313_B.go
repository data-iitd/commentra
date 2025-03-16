
package main

import "fmt"

func main() {
	var soz string
	fmt.Scan(&soz)
	a := make([]int, len(soz)+1)
	for i := 1; i < len(soz); i++ {
		a[i] = a[i-1]
		if soz[i-1] == soz[i] {
			a[i] += 1
		}
	}
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		var m, l string
		fmt.Scan(&m, &l)
		arr[i] = a[int(l)-1] - a[int(m)-1]
	}
	for _, v := range arr {
		fmt.Println(v)
	}
}

