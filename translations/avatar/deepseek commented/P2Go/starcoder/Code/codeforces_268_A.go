
package main

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
	var q []string
	for i := 0; i < n; i++ {
		var a []string
		fmt.Scanf("%s", &a)
		q = append(q, a[0])
	}
	var count int
	for j := 0; j < len(q); j++ {
		for k := 0; k < len(q); k++ {
			if j == k {
				continue
			}
			if q[j] == q[k][len(q[k])-1:len(q[k])] {
				count++
			}
		}
	}
	fmt.Println(count)
}

