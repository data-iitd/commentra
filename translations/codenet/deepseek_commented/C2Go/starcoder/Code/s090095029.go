<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
<<<<<<< HEAD
	fmt.Println("Enter two integers n and m:")
=======
	fmt.Println("Enter two integers n and m")
>>>>>>> 98c87cb78a (data updated)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	n, _ := strconv.Atoi(input)
	m, _ := strconv.Atoi(input)
	r0 := make([]bool, n)
	for i := 0; i < n; i++ {
		r0[i] = false
	}
	r1 := make([]int, 0)
	for i := 0; i < m; i++ {
<<<<<<< HEAD
		fmt.Println("Enter a pair of integers a and b:")
=======
		fmt.Println("Enter a pair of integers a and b")
>>>>>>> 98c87cb78a (data updated)
		input, _ := reader.ReadString('\n')
		input = strings.TrimSuffix(input, "\n")
		a, _ := strconv.Atoi(input)
		b, _ := strconv.Atoi(input)
		if a > b {
			a, b = b, a
		}
		if a == 1 {
			r0[b-1] = true
		}
		if b == n {
			r1 = append(r1, a-1)
		}
	}
	res := false
	for i := 0; i < len(r1); i++ {
		if r0[r1[i]] {
			res = true
		}
	}
	if res {
		fmt.Println("POSSIBLE")
	} else {
		fmt.Println("IMPOSSIBLE")
	}
}

