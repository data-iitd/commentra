package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the list")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	L := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Println("Enter the element")
		L[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	sort.Ints(L)
	count := 0
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			a := L[i]
			b := L[j]
			res := find(L, j+1, a+b)
			count = count + res
		}
	}
	fmt.Println(count)
}

func find(li []int, from int, target int) int {
	low := from
	upp := len(li) - 1
	mid := (upp - low + 1) % 2 == 0? (low+upp)/2 + 1 : (low+upp)/2
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
		mid = (upp - low + 1) % 2 == 0? (low+upp)/2 + 1 : (low+upp)/2
	}
	return low - from + 1
}

