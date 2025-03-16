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
	var l [2001]int
	var i, j, k, cnt, tmp int

<<<<<<< HEAD
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)

	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &l[i])
=======
	fmt.Scanf("%d", &n)

	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &l[i])
>>>>>>> 98c87cb78a (data updated)
	}

	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			if l[j] < l[i] {
				tmp = l[i]
				l[i] = l[j]
				l[j] = tmp
			}
		}
	}

	for i := 0; i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			for k := j + 1; k < n; k++ {
				if l[i]+l[j] > l[k] {
					cnt++
				} else {
					break
				}
			}
		}
	}

<<<<<<< HEAD
	fmt.Println(cnt)
=======
	fmt.Printf("%d\n", cnt)
>>>>>>> 98c87cb78a (data updated)
}

