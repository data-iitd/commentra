
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

const (
	NUM = 100002
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readerReadLine(reader))
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(readerReadLine(reader))
	}
	sort.Ints(a)
	bin := 0
	diff := 0
	for _, num := range a {
		idx := sort.SearchInts(a, num)
		if (bin%2)!= (idx%2) {
			diff++
		}
		bin++
		bin %= 2
	}
	ans := diff / 2
	fmt.Println(ans)
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

