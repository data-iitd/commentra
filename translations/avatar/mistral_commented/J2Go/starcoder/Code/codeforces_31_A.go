
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	a := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	k, j, i := 0, 0, 0
	for k = 0; k < n; k++ {
		t := a[k]
		for i = 0; i < n; i++ {
			if i!= k {
				for j = 0; j < n-1; j++ {
					if i!= j && t == (a[i] + a[j]) {
						fmt.Println(k+1, j+1, i+1)
						break
					}
				}
				if j!= n-1 {
					break
				}
			}
		}
	}
}

