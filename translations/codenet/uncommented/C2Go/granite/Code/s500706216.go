
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, k int
	fmt.Fscanf(reader, "%d%d\n", &n, &k)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}
	light := make([]int, n+1)
	for i := 0; i < n; i++ {
		r, l := i-a[i], i+a[i]
		if r < 0 {
			r = 0
		}
		if l > n {
			l = n + 1
		}
		light[r]++
		light[l]--
	}
	for i := 1; i <= n; i++ {
		light[i] += light[i-1]
	}
	for i := 0; i < k; i++ {
		tmpa := make([]int, n)
		copy(tmpa, a)
		for j := 0; j < n; j++ {
			a[j] = light[j] - a[j]
		}
		light = make([]int, n+1)
		for j := 0; j < n; j++ {
			r, l := j-a[j], j+a[j]
			if r < 0 {
				r = 0
			}
			if l > n {
				l = n + 1
			}
			light[r]++
			light[l]--
		}
		for j := 1; j <= n; j++ {
			light[j] += light[j-1]
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
	for i := 0; i < n; i++ {
		fmt.Printf("%d ", a[i])
	}
	fmt.Println()
}

