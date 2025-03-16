
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	var N, L, R, QL, QR int
	fmt.Fscanf(in, "%d\n", &N)
	fmt.Fscanf(in, "%d\n", &L)
	fmt.Fscanf(in, "%d\n", &R)
	fmt.Fscanf(in, "%d\n", &QL)
	fmt.Fscanf(in, "%d\n", &QR)

	W := make([]int, N)
	sum := make([]int, N+1)

	for n := 0; n < N; n++ {
		fmt.Fscanf(in, "%d\n", &W[n])
		sum[n+1] = sum[n] + W[n]
	}

	min := int64(1e18)

	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount

		cand := int64(sum[lCount]*L + (sum[N]-sum[lCount])*R)

		llCount := int(max(0, int64(lCount-rCount-1)))
		rrCount := int(max(0, int64(rCount-lCount-1)))
		cand += int64(llCount * QL)
		cand += int64(rrCount * QR)

		min = min(cand, min)
	}

	fmt.Fprintf(out, "%d\n", min)
	out.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main2() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	var N, L, R, QL, QR int
	fmt.Fscanf(in, "%d\n", &N)
	fmt.Fscanf(in, "%d\n", &L)
	fmt.Fscanf(in, "%d\n", &R)
	fmt.Fscanf(in, "%d\n", &QL)
	fmt.Fscanf(in, "%d\n", &QR)

	W := make([]int, N)
	sum := make([]int, N+1)

	for n := 0; n < N; n++ {
		fmt.Fscanf(in, "%d\n", &W[n])
		sum[n+1] = sum[n] + W[n]
	}

	min := int64(1e18)

	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount

		cand := int64(sum[lCount]*L + (sum[N]-sum[lCount])*R)

		llCount := int(max(0, int64(lCount-rCount-1)))
		rrCount := int(max(0, int64(rCount-lCount-1)))
		cand += int64(llCount * QL)
		cand += int64(rrCount * QR)

		min = min(cand, min)
	}

	fmt.Fprintf(out, "%d\n", min)
	out.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main3() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	var N, L, R, QL, QR int
	fmt.Fscanf(in, "%d\n", &N)
	fmt.Fscanf(in, "%d\n", &L)
	fmt.Fscanf(in, "%d\n", &R)
	fmt.Fscanf(in, "%d\n", &QL)
	fmt.Fscanf(in, "%d\n", &QR)

	W := make([]int, N)
	sum := make([]int, N+1)

	for n := 0; n < N; n++ {
		fmt.Fscanf(in, "%d\n", &W[n])
		sum[n+1] = sum[n] + W[n]
	}

	min := int64(1e18)

	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount

		cand := int64(sum[lCount]*L + (sum[N]-sum[lCount])*R)

		llCount := int(max(0, int64(lCount-rCount-1)))
		rrCount := int(max(0, int64(rCount-lCount-1)))
		cand += int64(llCount * QL)
		cand += int64(rrCount * QR)

		min = min(cand, min)
	}

	fmt.Fprintf(out, "%d\n", min)
	out.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main4() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	var N, L, R, QL, QR int
	fmt.Fscanf(in, "%d\n", &N)
	fmt.Fscanf(in, "%d\n", &L)
	fmt.Fscanf(in, "%d\n", &R)
	fmt.Fscanf(in, "%d\n", &QL)
	fmt.Fscanf(in, "%d\n", &QR)

	W := make([]int, N)
	sum := make([]int, N+1)

	for n := 0; n < N; n++ {
		fmt.Fscanf(in, "%d\n", &W[n])
		sum[n+1] = sum[n] + W[n]
	}

	min := int64(1e18)

	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount

		cand := int64(sum[lCount]*L + (sum[N]-sum[lCount])*R)

		llCount := int(max(0, int64(lCount-rCount-1)))
		rrCount := int(max(0, int64(rCount-lCount-1)))
		cand += int64(llCount * QL)
		cand += int64(rrCount * QR)

		min = min(cand, min)
	}

	fmt.Fprintf(out, "%d\n", min)
	out.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main5() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	var N, L, R, QL, QR int
	fmt.Fscanf(in, "%d\n", &N)
	fmt.Fscanf(in, "%d\n", &L)
	fmt.Fscanf(in, "%d\n", &R)
	fmt.Fscanf(in, "%d\n", &QL)
	fmt.Fscanf(in, "%d\n", &QR)

	W := make([]int, N)
	sum := make([]int, N+1)

	for n := 0; n < N; n++ {
		fmt.Fscanf(in, "%d\n", &W[n])
		sum[n+1] = sum[n] + W[n]
	}

	min := int64(1e18)

	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount

		cand := int64(sum[lCount]*L + (sum[N]-sum[lCount])*R)

		llCount := int(max(0, int64(lCount-rCount-1)))
		rrCount := int(max(0, int64(rCount-lCount-1)))
		cand += int64(llCount * QL)
		cand += int64(rrCount * QR)

		min = min(cand, min)
	}

	fmt.Fprintf(out, "%d\n", min)
	out.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main6() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	var N, L, R, QL, QR int
	fmt.Fscanf(in, "%d\n", &N)
	fmt.Fscanf(in, "%d\n", &L)
	fmt.Fscanf(in, "%d\n", &R)
	fmt.Fscanf(in, "%d\n", &QL)
	fmt.Fscanf(in, "%d\n", &QR)

	W := make([]int, N)
	sum := make([]int, N+1)

	for n := 0; n < N; n++ {
		fmt.Fscanf(in, "%d\n", &W[n])
		sum[n+1] = sum[n] + W[n]
	}

	min := int64(1e18)

	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount

		cand := int64(sum[lCount]*L + (sum[N]-sum[lCount])*R)

		llCount := int(max(0, int64(lCount-rCount-1)))
		rrCount := int(max(0, int64(rCount-lCount-1)))
		cand += int64(llCount * QL)
		cand += int64(rrCount * QR)

		min = min(cand, min)
	}

	fmt.Fprintf(out, "%d\n", min)
	out.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main7() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	var N, L, R, QL, QR int
	fmt.Fscanf(in, "%d\n", &N)
	fmt.Fscanf(in, "%d\n", &L)
	fmt.Fscanf(in, "%d\n", &R)
	fmt.Fscanf(in, "%d\n", &QL)
	fmt.Fscanf(in, "%d\n", &QR)

	W := make([]int, N)
	sum := make([]int, N+1)

	for n := 0; n < N; n++ {
		fmt.Fscanf(in, "%d\n", &W[n])
		sum[n+1] = sum[n] + W[n]
	}

	min := int64(1e18)

	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount

		cand := int64(sum[lCount]*L + (sum[N]-sum[lCount])*R)

		llCount := int(max(0, int64(lCount-rCount-1)))
		rrCount := int(max(0, int64(rCount-lCount-1)))
		cand += int64(llCount * QL)
		cand += int64(rrCount * QR)

		min = min(cand, min)
	}

	fmt.Fprintf(out, "%d\n", min)
	out.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main8() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	var N, L, R, QL, QR int
	fmt.Fscanf(in, "%d\n", &N)
	fmt.Fscanf(in, "%d\n", &L)
	fmt.Fscanf(in, "%d\n", &R)
	fmt.Fscanf(in, "%d\n", &QL)
	fmt.Fscanf(in, "%d\n", &QR)

	W := make([]int, N)
	sum := make([]int, N+1)

	for n := 0; n < N; n++ {
		fmt.Fscanf(in, "%d\n", &W[n])
		sum[n+1] = sum[n] + W[n]
	}

	min := int64(1e18)

	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount

		cand := int64(sum[lCount]*L + (sum[N]-sum[lCount])*R)

		llCount := int(max(0, int64(lCount-rCount-1)))
		rrCount := int(max(0, int64(rCount-lCount-1)))
		cand += int64(llCount * QL)
		cand += int64(rrCount * QR)

		min = min(cand, min)
	}

	fmt.Fprintf(out, "%d\n", min)
	out.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main9() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	var N, L, R, QL, QR int
	fmt.Fscanf(in, "%d\n", &N)
	fmt.Fscanf(in, "%d\n", &L)
	fmt.Fscanf(in, "%d\n", &R)
	fmt.Fscanf(in, "%d\n", &QL)
	fmt.Fscanf(in, "%d\n", &QR)

	W := make([]int, N)
	sum := make([]int, N+1)

	for n := 0; n < N; n++ {
		fmt.Fscanf(in, "%d\n", &W[n])
		sum[n+1] = sum[n] + W[n]
	}

	min := int64(1e18)

	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount

		cand := int64(sum[lCount]*L + (sum[N]-sum[lCount])*R)

		llCount := int(max(0, int64(lCount-rCount-1)))
		rrCount := int(max(0, int64(rCount-lCount-1)))
		cand += int64(llCount * QL)
		cand += int64(rrCount * QR)

		min = min(cand, min)
	}

	fmt.Fprintf(out, "%d\n", min)
	out.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main10() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	var N, L, R, QL, QR int
	fmt.Fscanf(in, "%d\n", &N)
	fmt.Fscanf(in, "%d\n", &L)
	fmt.Fscanf(in, "%d\n", &R)
	fmt.Fscanf(in, "%d\n", &QL)
	fmt.Fscanf(in, "%d\n", &QR)

	W := make([]int, N)
	sum := make([]int, N+1)

	for n := 0; n < N; n++ {
		fmt.Fscanf(in, "%d\n", &W[n])
		sum[n+1] = sum[n] + W[n]
	}

	min := int64(1e18)

	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR
		rCount := N - lCount

		cand := int64(sum[lCount]*L + (sum[N]-sum[lCount])*R

		llCount := int(max(0, int64(lCount-rCount-1))
		rrCount := int(max(0, int64(rCount-lCount-1))
		cand += int64(llCount * QL)
		cand += int64(rrCount * QR)

		min = min(cand, min)
	}

	fmt.Fprintf(out, "%d\n", min)
	out.Flush()
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b