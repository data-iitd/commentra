
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

const (
	NUM_MAX  = 1000
	NUM2_MAX = NUM_MAX * NUM_MAX
	RANK_MAX = 3000
)

var (
	maxSum int64 = 1e+10
	minSum int64 = 1e+11
)

func main() {
	var (
		x, y, z, rank int
		err            error
	)
	var (
		xrr, yrr, zrr []int64
		pair            []int64
		cache           []int
		cntMap          []int
		ans             []int64
	)
	reader := bufio.NewReader(os.Stdin)
	xrr = make([]int64, NUM_MAX)
	yrr = make([]int64, NUM_MAX)
	zrr = make([]int64, NUM_MAX)
	pair = make([]int64, NUM2_MAX)
	cache = make([]int, NUM_MAX)
	cntMap = make([]int, NUM_MAX)
	ans = make([]int64, RANK_MAX)
	if x, err = strconv.Atoi(readLine(reader)); err!= nil {
		panic(err)
	}
	if y, err = strconv.Atoi(readLine(reader)); err!= nil {
		panic(err)
	}
	if z, err = strconv.Atoi(readLine(reader)); err!= nil {
		panic(err)
	}
	if rank, err = strconv.Atoi(readLine(reader)); err!= nil {
		panic(err)
	}
	for i := 0; i < x; i++ {
		if xrr[i], err = strconv.ParseInt(readLine(reader), 10, 64); err!= nil {
			panic(err)
		}
	}
	for i := 0; i < y; i++ {
		if yrr[i], err = strconv.ParseInt(readLine(reader), 10, 64); err!= nil {
			panic(err)
		}
	}
	for i := 0; i < z; i++ {
		if zrr[i], err = strconv.ParseInt(readLine(reader), 10, 64); err!= nil {
			panic(err)
		}
		if zrr[i] < minSum {
			minSum = zrr[i]
		}
		if zrr[i] > maxSum {
			maxSum = zrr[i]
		}
	}
	idx := 0
	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			pair[idx] = xrr[i] + yrr[j]
			idx++
		}
	}
	sort.Slice(pair, func(i, j int) bool {
		return pair[i] < pair[j]
	})
	minSum += pair[0]
	maxSum += pair[NUM2_MAX-1]
	for i := 0; i < z; i++ {
		cache[i] = i
	}
	prev := minSum
	for r := rank; r >= 1; r-- {
		low := prev - 1
		high := maxSum + 1
		for low+1 < high {
			mid := (low + high) / 2
			cnt := 0
			for i := 0; i < z; i++ {
				pivot := zrr[i]
				cache[i] = lowerBound(pair, cache[i]-1, mid-pivot)
				cnt += cache[i]
			}
			if cnt <= (x * y * z) - r {
				low = mid
			} else {
				high = mid
			}
		}
		ans[r-1] = low
		if low == maxSum {
			break
		}
		prev = low
	}
	for i := 0; i < rank; i++ {
		fmt.Println(ans[i])
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

func lowerBound(arr []int64, left, right int) int {
	for left < right {
		mid := (left + right) / 2
		if arr[mid] < arr[left] {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}

