
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const N = 1000000
const Q = 50000

var n, S, T, c int

func binarySearch(key int) bool {
	left, right := 0, n
	for left < right {
		mid := (left + right) / 2
		if S[mid] == key {
			return true
		} else if key < S[mid] {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return false
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var err error
	n, err = strconv.Atoi(scanner.Text())
	if err!= nil {
		panic(err)
	}
	S = make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		S[i], err = strconv.Atoi(scanner.Text())
		if err!= nil {
			panic(err)
		}
	}
	q, err := strconv.Atoi(scanner.Text())
	if err!= nil {
		panic(err)
	}
	T = make([]int, q)
	for i := 0; i < q; i++ {
		scanner.Scan()
		T[i], err = strconv.Atoi(scanner.Text())
		if err!= nil {
			panic(err)
		}
	}
	for i := 0; i < q; i++ {
		if binarySearch(T[i]) {
			c++
		}
	}
	fmt.Println(c)
}

