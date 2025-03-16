
package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

const (
	INF = 1e9 + 228
	INFLL = 1e18
	MOD = 1e9 + 7
	dosz = 5e5
	SZ = (1<<18)
	PI = math.Atan2(0, -1)
)

func fast_io() {
	rand.Seed(time.Now().UnixNano())
	fmt.FastScanf = true
	fmt.Fscanf = func(a ...interface{}) (n int, err error) {
		n, err = fmt.Fscan(os.Stdin, a...)
		return
	}
	fmt.Fscanln = func(a ...interface{}) (n int, err error) {
		n, err = fmt.Fscan(os.Stdin, a...)
		return
	}
	fmt.Fprintf = func(w io.Writer, format string, a ...interface{}) (n int, err error) {
		n, err = fmt.Fprintf(w, format, a...)
		return
	}
	fmt.Fprintln = func(w io.Writer, a ...interface{}) (n int, err error) {
		n, err = fmt.Fprintln(w, a...)
		return
	}
	fmt.Print = func(a ...interface{}) (n int, err error) {
		n, err = fmt.Fprint(os.Stdout, a...)
		return
	}
	fmt.Println = func(a ...interface{}) (n int, err error) {
		n, err = fmt.Fprintln(os.Stdout, a...)
		return
	}
	fmt.Sprint = func(a ...interface{}) string {
		return fmt.Sprintf("%s", a...)
	}
	fmt.Sprintln = func(a ...interface{}) string {
		return fmt.Sprintf("%s\n", a...)
	}
	fmt.Sprintf = func(format string, a ...interface{}) string {
		return fmt.Sprintf(format, a...)
	}
	fmt.Errorf = func(format string, a ...interface{}) error {
		return fmt.Errorf(format, a...)
	}
}

func solve() {
	var n int
	fmt.Scan(&n)
	nums := make([]int, n)
	last := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}
	dp := make([]int, n+1)
	dp[0] = 1
	kek := make(map[int]int)
	prev := make(map[int]int)
	for i := 1; i <= n; i++ {
		dp[i] = dp[i-1] + (prev[nums[i-1]] != i-1 ? kek[nums[i-1]] : 0)
		dp[i] %= MOD
		kek[nums[i-1]] = dp[i]
		prev[nums[i-1]] = i
	}
	fmt.Println(dp[n])
}

func main() {
	fast_io()
	srand(time.Now().UnixNano())
	fmt.Fprintf = func(w io.Writer, format string, a ...interface{}) (n int, err error) {
		n, err = fmt.Fprintf(w, format, a...)
		return
	}
	fmt.Fprintln = func(w io.Writer, a ...interface{}) (n int, err error) {
		n, err = fmt.Fprintln(w, a...)
		return
	}
	fmt.Print = func(a ...interface{}) (n int, err error) {
		n, err = fmt.Fprint(os.Stdout, a...)
		return
	}
	fmt.Println = func(a ...interface{}) (n int, err error) {
		n, err = fmt.Fprintln(os.Stdout, a...)
		return
	}
	fmt.Sprint = func(a ...interface{}) string {
		return fmt.Sprintf("%s", a...)
	}
	fmt.Sprintln = func(a ...interface{}) string {
		return fmt.Sprintf("%s\n", a...)
	}
	fmt.Sprintf = func(format string, a ...interface{}) string {
		return fmt.Sprintf(format, a...)
	}
	fmt.Errorf = func(format string, a ...interface{}) error {
		return fmt.Errorf(format, a...)
	}
	q := 1
	// fmt.Scan(&q)
	for q--; q >= 0; q-- {
		solve()
	}
}

