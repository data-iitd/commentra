
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the value of n:")
	n, _ := reader.ReadString('\n')
	n, _ = strconv.Atoi(n)

	fmt.Println("Enter the value of p:")
	p, _ := reader.ReadString('\n')
	p, _ = strconv.Atoi(p)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Println("Enter the value of a[" + strconv.Itoa(i) + "]:")
		a[i], _ = reader.ReadString('\n')
		a[i], _ = strconv.Atoi(a[i])
	}

	b := 0
	c := 0
	for i := 0; i < n; i++ {
		if a[i]%2 == 0 {
			b++
		} else {
			c++
		}
	}

	bsum := int(math.Pow(float64(2), float64(b)))
	csum := 0

	if p == 0 {
		for i := 0; i <= c; i++ {
			if i%2 == 0 {
				csum += nCr(c, i)
			}
		}
	} else {
		for i := 0; i <= c; i++ {
			if i%2 == 1 {
				csum += nCr(c, i)
			}
		}
	}

	ans := bsum * csum
	fmt.Println("The answer is:", ans)
}

func nCr(n, r int) int {
	res := 1
	for i := 0; i < r; i++ {
		res *= (n - i)
	}
	for i := 0; i < r; i++ {
		res /= (i + 1)
	}
	return res
}

