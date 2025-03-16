package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var q int
	var n int
	var s int64
	var x int
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	q, _ = strconv.Atoi(sc.Text())
	for q > 0 {
		sc.Scan()
		n, _ = strconv.Atoi(sc.Text())
		x = int(math.Log(float64(n)) / math.Log(2))
		x++
		s = -1*int64(math.Pow(2, float64(x))) + 2 + int64(n*(n+1)/2) - int64(math.Pow(2, float64(x)))
		fmt.Println(s)
		q--
	}
}

