package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	input := bufio.NewReader(os.Stdin)
	output := bufio.NewWriter(os.Stdout)
	defer output.Flush()

	var n, k int
	fmt.Fscan(input, &n, &k)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(input, &a[i])
	}

	sort.Ints(a)

	ans := 0
	for i := 0; i < k; i++ {
		ans += a[i]
	}

	fmt.Fprintln(output, ans)
}

// <END-OF-CODE>
