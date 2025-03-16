package main

import (
	"bufio"
	"fmt"
	"sort"
)

func main() {
	scanner := bufio.NewScanner(bufio.NewReader(os.Stdin))
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	N := parseInt(scanner.Text())
	arr := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		arr[i] = parseInt(scanner.Text())
	}

	tsk := &Task{}
	fmt.Println(tsk.solve(arr))
}

func parseInt(s string) int {
	var res int
	for i := 0; i < len(s); i++ {
		res = res*10 + int(s[i]-'0')
	}
	return res
}

type Task struct{}

func (t *Task) solve(arr []int) int {
	n := len(arr)
	sorted := make([]int, n)
	copy(sorted, arr)
	sort.Ints(sorted)
	total := int64(n) * int64(n+1) / 2
	l, r := 0, n-1
	for l < r {
		mid := l + (r-l)/2
		target := sorted[mid]
		cur := 0
		cnt := int64(0)
		bit := make([]int64, 2*n+2)
		for x := n + 1; x < len(bit); x += x & -x {
			bit[x]++
		}
		for i := 0; i < n; i++ {
			if arr[i] <= target {
				cur++
			} else {
				cur--
			}
			for x := cur + n + 1; x < len(bit); x += x & -x {
				bit[x]++
			}
			for x := cur + n; x > 0; x -= x & -x {
				cnt += bit[x]
			}
		}
		if cnt >= total/2+1 {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return sorted[l]
}

