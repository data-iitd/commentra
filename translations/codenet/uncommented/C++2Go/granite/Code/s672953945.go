
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
	N, L := readInt(), readInt()
	S := make([]string, N)
	for i := 0; i < N; i++ {
		S[i] = readString()
	}
	sort.Strings(S)
	for i := 0; i < N; i++ {
		fmt.Print(S[i])
	}
	fmt.Println()
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func readString() string {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	return sc.Text()
}

func readInt64() int64 {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	i, _ := strconv.ParseInt(sc.Text(), 10, 64)
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

func power(a, b int) int {
	r := 1
	for i := 0; i < b; i++ {
		r *= a
	}
	return r
}

func abs(a int) int {
	return max(a, -a)
}

func mod(a, b int) int {
	r := a % b
	if r < 0 {
		r += b
	}
	return r
}

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func nextPrime(n int) int {
	if n <= 1 {
		return 2
	}
	n++
	for!isPrime(n) {
		n++
	}
	return n
}

func minInt(a...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if res > a[i] {
			res = a[i]
		}
	}
	return res
}

func maxInt(a...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if res < a[i] {
			res = a[i]
		}
	}
	return res
}

func minInt64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if res > a[i] {
			res = a[i]
		}
	}
	return res
}

func maxInt64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if res < a[i] {
			res = a[i]
		}
	}
	return res
}

func debug(args...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugf(format string, args...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func debugln(args...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

