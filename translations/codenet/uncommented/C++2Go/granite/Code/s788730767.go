
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	reader = bufio.NewReader(os.Stdin)
)

func main() {
	n, p := readInt(), readInt()
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = readInt()
	}

	b, c := 0, 0
	for _, v := range a {
		if v%2 == 0 {
			b++
		} else {
			c++
		}
	}

	bsum := 1 << uint(b)
	var csum int64
	for i := 0; i <= c; i++ {
		if i%2 == p {
			csum += nCr(int64(c), int64(i))
		}
	}

	ans := bsum * csum
	fmt.Println(ans)
}

func readInt() int {
	i, _ := strconv.Atoi(readWord())
	return i
}

func readWord() string {
	rst := ""
	for {
		c, err := reader.ReadByte()
		if err!= nil {
			panic(err)
		}

		if c =='' {
			break
		}

		rst += string(c)
	}
	return rst
}

func nPr(n, r int64) int64 {
	res := int64(1)
	for i := int64(0); i < r; i++ {
		res *= (n - i)
	}

	return res
}

func nCr(n, r int64) int64 {
	//ll res = nPr(n, r) / nPr(r, r);
	res := int64(1)
	for i := int64(0); i < r; i++ {
		res *= (n - i)
		res /= (i + 1)
	}
	return res
}

