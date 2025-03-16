
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanf(reader, "%d\n", &n)
	var a, b, c string
	fmt.Fscanf(reader, "%s\n", &a)
	fmt.Fscanf(reader, "%s\n", &b)
	fmt.Fscanf(reader, "%s\n", &c)
	ans := 0
	for i := 0; i < n; i++ {
		if a[i] == b[i] && b[i] == c[i] {
		} else if a[i] == b[i] || b[i] == c[i] || a[i] == c[i] {
			ans++
		} else {
			ans += 2
		}
	}
	fmt.Println(ans)
}
