package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	var sumA int
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		sumA += a[i]
	}

	if sumA%(n*(n+1)/2) != 0 {
		fmt.Println("NO")
		return
	}

	k := float64(sumA) / float64(n*(n+1)/2)
	a = append(a, a[0]) // Append the first element to the end

	var sum1, sum2 int
	for i := 1; i <= n; i++ {
		i1 := a[i]
		j := a[i-1]
		sum1 += int(int(k)-i1+j) % n
		if (int(k)-i1+j)/n < 0 {
			sum2++
		}
	}

	if sum1 != 0 || sum2 != n {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
	}
}

// <END-OF-CODE>
