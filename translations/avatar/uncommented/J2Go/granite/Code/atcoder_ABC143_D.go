
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(reader.ReadLine()[2:])
	}
	sort.Ints(l)
	count := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			a := l[i]
			b := l[j]
			res := find(l, j+1, a+b)
			count += res
		}
	}
	fmt.Println(count)
}

func find(li []int, from int, target int) int {
	low := from
	upp := len(li) - 1
	mid := (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2
	if upp-low < 0 {
		return 0
	} else if li[from] >= target {
		return 0
	} else if li[upp] < target {
		return upp - low + 1
	}
	for upp-low > 1 {
		if li[mid] >= target {
			upp = mid
		} else {
			low = mid
		}
		mid = (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2
	}
	return low - from + 1
}

