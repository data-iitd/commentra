
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	n, _ := strconv.Atoi(sc.Text())
	k, _ := strconv.ParseInt(sc.Text(), 10, 64)

	arr := make([]int64, n)
	set := make(map[int64]bool)

	for i := 0; i < n; i++ {
		arr[i], _ = strconv.ParseInt(sc.Text(), 10, 64)
	}

	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	count := 0

	for i := 0; i < n; i++ {
		if arr[i]%k!= 0 {
			count++
			set[arr[i]] = true
		} else if _, ok := set[arr[i]/k];!ok {
			count++
			set[arr[i]] = true
		}
	}

	fmt.Println(count)
}

