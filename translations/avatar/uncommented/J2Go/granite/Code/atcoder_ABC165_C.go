
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	n, m, q int
	a, b, c, d []int
	ans int64 = -100
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var err error
	n, err = scanner.nextInt()
	if err!= nil {
		panic(err)
	}
	m, err = scanner.nextInt()
	if err!= nil {
		panic(err)
	}
	q, err = scanner.nextInt()
	if err!= nil {
		panic(err)
	}
	a = make([]int, q)
	b = make([]int, q)
	c = make([]int, q)
	d = make([]int, q)
	for i := 0; i < q; i++ {
		a[i], err = scanner.nextInt()
		if err!= nil {
			panic(err)
		}
		a[i]--
		b[i], err = scanner.nextInt()
		if err!= nil {
			panic(err)
		}
		b[i]--
		c[i], err = scanner.nextInt()
		if err!= nil {
			panic(err)
		}
		d[i], err = scanner.nextInt()
		if err!= nil {
			panic(err)
		}
	}
	dfs(make([]int, 0))
	fmt.Println(ans)
}

func dfs(list []int) {
	if len(list) == n {
		score := int64(0)
		for i := 0; i < q; i++ {
			if list[b[i]]-list[a[i]] == c[i] {
				score += int64(d[i])
			}
		}
		if ans < score {
			ans = score
		}
		return
	}
	if len(list)!= 0 {
		for num := list[len(list)-1]; num <= m; num++ {
			list = append(list, num)
			dfs(list)
			list = list[:len(list)-1]
		}
	} else {
		for num := 1; num <= m; num++ {
			list = append(list, num)
			dfs(list)
			list = list[:len(list)-1]
		}
	}
}

func (scanner *bufio.Scanner) nextInt() (int, error) {
	scanner.Scan()
	num, err := strconv.Atoi(scanner.Text())
	if err!= nil {
		return -1, err
	}
	return num, nil
}

