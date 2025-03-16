
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	nTemp, err := fmt.Fscanf(reader, "%d\n", &n)
	checkError(err)

	a := make([]int32, n)

	for i := 0; i < int(n); i++ {
		aTemp, err := fmt.Fscanf(reader, "%d", &aTemp)
		checkError(err)
		a[i] = int32(aTemp)
	}

	if n == 1 {
		fmt.Println(a[0])
		return
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})

	if a[n-1] == 0 {
		fmt.Println(0)
		return
	}

	ans := int32(0)

	for len(a) > 1 {
		a = func(a []int32) []int32 {
			var min int32 = 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
					} else {
						min = a[i]
					}
				}
			}
			sort.Slice(a, func(i, j int) bool {
				return a[i] < a[j]
			})
			return a
		}(a)
	}

	fmt.Println(a[0])
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

