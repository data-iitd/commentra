package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var num int = 998244353
	var n int
	var ai []int
	var bi []int
	var b float64
	var c float64
	var st []string
	var bf *bufio.Reader = bufio.NewReader(os.Stdin)
	var out *bufio.Writer = bufio.NewWriter(os.Stdout)
	n, _ = strconv.Atoi(strings.TrimSpace(bf.ReadString()))
	ai = make([]int, n)
	bi = make([]int, n)
	for i := 0; i < n; i++ {
		st = strings.Split(strings.TrimSpace(bf.ReadString()), " ")
		ai[i], _ = strconv.Atoi(st[0])
		bi[i], _ = strconv.Atoi(st[1])
	}
	sort.Ints(ai)
	sort.Ints(bi)
	if n%2 == 1 {
		fmt.Println(bi[len(bi)/2]-ai[len(ai)/2]+1)
	} else {
		b = (ai[len(ai)/2]+ai[len(ai)/2-1]+0.0)/2
		c = (bi[len(bi)/2]+bi[len(bi)/2-1]+0.0)/2
		fmt.Println((int)(2*(c-b)+1))
	}
	out.Flush()
}

