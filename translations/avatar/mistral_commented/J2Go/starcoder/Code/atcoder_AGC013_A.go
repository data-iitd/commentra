
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
	fmt.Println("Enter the number of elements in the array")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	N, _ := strconv.Atoi(input)
	A := make([]int, N)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < N; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		A[i], _ = strconv.Atoi(input)
	}
	count := 0
	for i := 0; i < N-1; i++ {
		if i == N-1 {
			count++
		} else if A[i] == A[i+1] {
			continue
		} else if A[i] < A[i+1] {
			for A[i] <= A[i+1] {
				i++
				if i == N-1 {
					break
				}
			}
			count++
		} else {
			for A[i] >= A[i+1] {
				i++
				if i == N-1 {
					break
				}
			}
			count++
		}
	}
	fmt.Println(count)
}

