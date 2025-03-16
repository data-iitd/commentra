
package main

import "fmt"

func main() {
	var L []int
	fmt.Scanln(&L)
	var r int = 1
	for _, k := range L {
		for i := 0; i < int(k); i++ {
			L = append(L, r)
			r++
		}
	}
	fmt.Scanln(&L)
	for _, j := range L {
		fmt.Println(L[int(j)-1])
	}
}

