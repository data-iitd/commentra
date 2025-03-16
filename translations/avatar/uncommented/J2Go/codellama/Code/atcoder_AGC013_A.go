
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var N int
	var A []int
	var count int
	var i int
	var j int
	var temp int

	N, _ = strconv.Atoi(os.Args[1])
	A = make([]int, N)
	for i = 0; i < N; i++ {
		A[i], _ = strconv.Atoi(os.Args[i+2])
	}
	count = 0
	for i = 0; i < N; i++ {
		if i == N-1 {
			count++
		} else if A[i] == A[i+1] {
		} else if A[i] < A[i+1] {
			for j = i + 1; j < N; j++ {
				if A[i] <= A[j] {
					i = j
					if i == N-1 {
						break
					}
				} else {
					break
				}
			}
			count++
		} else {
			for j = i + 1; j < N; j++ {
				if A[i] >= A[j] {
					i = j
					if i == N-1 {
						break
					}
				} else {
					break
				}
			}
			count++
		}
	}
	fmt.Println(count)
}

