
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		fmt.Scan(&b[i])
	}
	sort.Ints(a)
	sort.Ints(b)
	if n%2 == 1 {
		fmt.Println(b[n/2] - a[n/2] + 1)
	} else {
		fmt.Println(int(2 * (float64(b[n/2]) - float64(a[n/2]) + 0.0) + 1))
	}
}

