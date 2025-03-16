
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	k, _ := strconv.Atoi(read(reader))
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(read(reader))
	}
	sort.Ints(l)
	ans := 0
	for i := 0; i < k; i++ {
		ans += l[n-1-i]
	}
	fmt.Println(ans)
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

