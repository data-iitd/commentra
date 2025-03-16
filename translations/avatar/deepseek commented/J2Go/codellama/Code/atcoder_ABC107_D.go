
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	task := Task{}
	fmt.Println(task.Solve(arr))
}

type Task struct{}

func (task *Task) Solve(arr []int) int {
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
			cur += arr[i] <= target ? 1 : -1
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

