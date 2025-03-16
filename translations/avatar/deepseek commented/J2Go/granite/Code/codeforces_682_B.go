
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
	list := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &list[i])
	}
	sort.Ints(list)
	c := 1
	for i := 0; i < n; i++ {
		if list[i] >= c {
			c++
		}
	}
	fmt.Println(c)
}

// Debug method for debugging purposes
func debug(args...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

// END-OF-CODE