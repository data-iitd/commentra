<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	a := make([]int, n)
	count := make([]int, n)
	for i := 1; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	for i := 0; i < n; i++ {
		count[i] = 0
	}
	for i := 1; i < n; i++ {
		count[a[i]-1]++
	}
	for i := 0; i < n; i++ {
		fmt.Printf("%d\n", count[i])
	}
}

