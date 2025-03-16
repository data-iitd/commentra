<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

func search(A []int, n int, key int) int {
	A[n] = key
	i := 0
	for A[i]!= key {
		i++
	}
	return i!= n
}

func main() {
<<<<<<< HEAD
	var n int
	var A []int
	var q int
	var key int
	var sum int = 0
=======
	var n, q, key, sum int
	var A []int
>>>>>>> 98c87cb78a (data updated)
	var i int

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)
	A = make([]int, n)
	for i = 0; i < n; i++ {
		fmt.Fscan(reader, &A[i])
	}
	fmt.Fscan(reader, &q)
	for i = 0; i < q; i++ {
		fmt.Fscan(reader, &key)
		if search(A, n, key) {
			sum++
		}
	}
	fmt.Println(sum)
}

