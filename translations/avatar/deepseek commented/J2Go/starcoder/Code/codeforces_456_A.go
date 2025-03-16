
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
	fmt.Println("Enter the number of elements in the array:")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	a := make([]int, n)
	b := make([]int, n)
	temp := 0
	q := 0
	w := 0
	e := 0
	f := false
	for i := 0; i < n; i++ {
		fmt.Printf("Enter the value for a[%d]: ", i)
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		fmt.Printf("Enter the value for b[%d]: ", i)
		b[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		if temp < a[i] {
			if q > b[i] {
				f = true
			}
			q = b[i]
			temp = a[i]
		}
		if temp > a[i] {
			if q < b[i] {
				f = true
			}
			q = b[i]
			temp = a[i]
		}
		if a[i] > w {
			w = a[i]
			if b[i] < e {
				f = true
			}
			e = b[i]
		}
		if a[i] < w {
			if b[i] > e {
				f = true
			}
		}
	}
	if f == true {
		fmt.Println("Happy Alex")
	} else {
		fmt.Println("Poor Alex")
	}
}

