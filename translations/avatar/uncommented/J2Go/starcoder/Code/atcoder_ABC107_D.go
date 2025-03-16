package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	scan := bufio.NewScanner(bufio.NewReader(os.Stdin))
	N, _ := strconv.Atoi(scan.Text())
	arr := make([]int, N)
	for i := 0; i < N; i++ {
		arr[i], _ = strconv.Atoi(scan.Text())
	}
	tsk := Task{}
	fmt.Println(tsk.solve(arr))
}

type Task struct {
}

func (t Task) solve(arr []int) int {
	n := len(arr)
	sorted := make([]int, n)
	copy(sorted, arr)
	sort.Ints(sorted)
	total := int64(n) * (n + 1) / 2
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
			cur += arr[i] <= target
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

