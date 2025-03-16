
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
	var soz string
	fmt.Fscanln(reader, &soz)
	a := make([]int, len(soz)+1)
	for i := 1; i < len(soz); i++ {
		a[i] = a[i-1]
		if soz[i-1] == soz[i] {
			a[i] += 1
		}
	}
	var n int
	fmt.Fscanln(reader, &n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		var m, l string
		fmt.Fscanln(reader, &m, &l)
		arr[i] = a[int(l)-1] - a[int(m)-1]
	}
	for i := 0; i < n; i++ {
		fmt.Println(arr[i])
	}
}

