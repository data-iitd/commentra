
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
	const MOD = 998244353
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	fmt.Fscanf(in, "%d\n", &n)

	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		s := strings.Split(strings.TrimSpace(readLine(in)), " ")
		a[i], _ = strconv.Atoi(s[0])
		b[i], _ = strconv.Atoi(s[1])
	}

	sort.Ints(a)
	sort.Ints(b)

	if n%2 == 1 {
		fmt.Fprintf(out, "%d\n", b[n/2]-a[n/2]+1)
	} else {
		fmt.Fprintf(out, "%d\n", (b[n/2]+b[n/2-1]+1)/2-((a[n/2]+a[n/2-1]+1)/2))
	}
}

func readLine(in *bufio.Reader) string {
	str, _, err := in.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

