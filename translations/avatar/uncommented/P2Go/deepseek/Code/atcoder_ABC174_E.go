package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func check(lis []int, k, mid int) bool {
	for _, i := range lis {
		if i%mid == 0 {
			k++
		}
		k -= (i / mid)
	}
	return k >= 0
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	line, _ := reader.ReadString('\n')
	line = line[:len(line)-1] // Remove the newline character
	parts := strings.Split(line, " ")
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])

	line, _ = reader.ReadString('\n')
	line = line[:len(line)-1] // Remove the newline character
	lisParts := strings.Split(line, " ")
	lis := make([]int, n)
	for i := 0; i < n; i++ {
		lis[i], _ = strconv.Atoi(lisParts[i])
	}

	a, b := 1, lis[0]
	for _, i := range lis {
		if i > b {
			b = i
		}
	}
	ans := b
	for a <= b {
		mid := (a + b) / 2
		if check(lis, k, mid) {
			ans = mid
			b = mid - 1
		} else {
			a = mid + 1
		}
	}
	fmt.Fprintln(writer, ans)
}
