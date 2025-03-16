package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	n, k := 0, 0
	fmt.Sscanf(strings.Join(os.Args[1:], ""), "%d%d", &n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Sscanf(strings.Join(os.Args[1:], ""), "%d", &a[i])
	}
	light := make([]int, n+2)
	for i := 0; i < n; i++ {
		r, l := i-a[i], i+a[i]
		light[r < 0? 0 : r]++
		light[l+1 > n? n+1 : l+1]--
	}
	for i := 0; i < k; i++ {
		sum := 0
		for j := 0; j < n; j++ {
			sum += light[j]
			a[j] = sum
		}
		for j := 0; j < n; j++ {
			r, l := j-a[j], j+a[j]
			light[r < 0? 0 : r]--
			light[l+1 > n? n+1 : l+1]++
			r, l = j-a[j], j+a[j]
			light[r < 0? 0 : r]++
			light[l+1 > n? n+1 : l+1]--
		}
		isSame := true
		for j := 0; j < n-1; j++ {
			if a[j]!= a[j+1] {
				isSame = false
				break
			}
		}
		if isSame && a[0] == n {
			break
		}
	}
	for j := 0; j < n; j++ {
		fmt.Printf("%d", a[j])
		if j!= n-1 {
			fmt.Printf(" ")
		}
	}
	fmt.Printf("\n")
}

