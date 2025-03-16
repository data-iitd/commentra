package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())

	var elems []int
	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		elems = append(elems, num)
	}

	allSame := func(arr []int) bool {
		for i := 1; i < len(arr); i++ {
			if arr[i] != arr[0] {
				return false
			}
		}
		return true
	}

	if allSame(elems) {
		fmt.Println(0)
		return
	}

	if k == 1 {
		fmt.Println(-1)
		return
	}

	if !allSame(elems[k-1:]) {
		fmt.Println(-1)
		return
	}

	target := elems[len(elems)-1]
	toDelete := elems[:k-1]
	for len(toDelete) > 0 && toDelete[len(toDelete)-1] == target {
		toDelete = toDelete[:len(toDelete)-1]
	}
	fmt.Println(len(toDelete))
}
