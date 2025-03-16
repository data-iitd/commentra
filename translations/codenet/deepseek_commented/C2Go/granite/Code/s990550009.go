
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(reader.ReadLine())
	}
	cnt := 1
	isup := a[0] < a[1]
	issame := false
	for i := 1; i < n-1; i++ {
		if issame {
			if a[i]!= a[i+1] {
				issame = false
				if a[i] < a[i+1] {
					isup = true
				} else {
					isup = false
				}
			}
		} else {
			if isup && a[i] <= a[i+1] {
				continue
			} else if!isup && a[i] >= a[i+1] {
				continue
			} else {
				if i+2 < n {
					if a[i+1] < a[i+2] {
						isup = true
					} else if a[i+1] > a[i+2] {
						isup = false
					} else {
						issame = true
					}
					cnt++
				} else {
					cnt++
					break
				}
			}
		}
	}
	fmt.Println(cnt)
}

