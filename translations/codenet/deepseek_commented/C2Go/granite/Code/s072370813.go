
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements:")
	N, _ := strconv.Atoi(reader.ReadLine()[0:1])
	fmt.Println("Enter the elements of the array:")
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(reader.ReadLine()[0:1])
	}
	sum := 0
	wa := 0
	for i := 0; i < N; i++ {
		sum += A[i]
		wa += i + 1
	}
	if sum%wa!= 0 {
		fmt.Println("NO")
	} else {
		shou := sum / wa
		sa := make([]int, N)
		for i := 0; i < N; i++ {
			sa[i] = A[(i+1)%N] - A[i] - shou
		}
		ok := true
		for i := 0; i < N-1; i++ {
			if sa[i] <= 0 || sa[i]%N!= 0 {
				ok = false
				break
			}
		}
		if ok {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

