
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := fmt.Fscanf(reader, "%d\n", &n)
	s := make([]byte, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%c", &s[i])
	}
	sort.Slice(s, func(i, j int) bool {
		return s[i] < s[j]
	})
	ans := 1
	for i := 1; i < n; i++ {
		if s[i] == s[i-1] {
			ans++
		} else {
			ans *= i
		}
	}
	fmt.Println(ans - 1)
}

