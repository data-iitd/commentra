
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	buf := make([]byte, 0)
	sc.Buffer(buf, 101000)
	sc.Split(bufio.ScanWords)

	N, L := nextInt(sc), nextInt(sc)
	S := make([]string, N)
	for i := 0; i < N; i++ {
		S[i] = nextString(sc)
	}
	sort.Strings(S)
	for i := 0; i < N; i++ {
		fmt.Print(S[i])
	}
	fmt.Println()
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func pow(a, b int) int {
	return int(math.Pow(float64(a), float64(b)))
}

func abs(a int) int {
	return int(math.Abs(float64(a)))
}

func mod(a, b int) int {
	return a - b * (a/b)
}

