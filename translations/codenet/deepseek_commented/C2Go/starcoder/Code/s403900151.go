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
	var n, r, p, c int
	var i, j, k, l int
	var a [51]int
	var b [51]int

	for {
		_, err := fmt.Scanf("%d %d", &n, &r)
		if err!= nil {
			break
		}
		if n == 0 && r == 0 {
			break
		}
		for i = 0; i < n; i++ {
			a[i] = i + 1
		}
		for i = 0; i < r; i++ {
			_, err := fmt.Scanf("%d %d", &p, &c)
			if err!= nil {
				break
			}
			for j = 0; j < c; j++ {
				b[j] = a[n-p-c+1+j]
			}
			for j = 0; j < p-1; j++ {
				a[n-p-c+1+j] = a[n-p+j+1]
			}
			for j = n-p-c+1+j; j < n-p-c+1+j+c; j++ {
				a[j] = b[j-n+p-c+1]
			}
			//fmt.Println(a)
		}
		fmt.Println(a[n-1])
	}
}

