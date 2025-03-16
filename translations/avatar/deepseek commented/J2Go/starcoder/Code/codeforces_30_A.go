
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
	var A, B, n int
	fmt.Fscan(reader, &A, &B, &n)
	if A == 0 {
		if B == 0 {
			fmt.Println(1)
		} else {
			fmt.Println("No solution")
		}
		return
	}
	if B%A!= 0 {
		fmt.Println("No solution")
		return
	}
	B /= A
	neg := B < 0
	if neg && n%2 == 0 {
		fmt.Println("No solution")
		return
	}
	if neg {
		B = -B
	}
	for x := 0; x <= B; x++ {
		if int64(math.Pow(float64(x), float64(n))) == B {
			fmt.Println(neg*-x)
			return
		}
	}
	fmt.Println("No solution")
}

