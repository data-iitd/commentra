package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func rs() string {
	sc.Scan()
	return sc.Text()
}

func ri() int {
	return mustParseInt(rs())
}

func rs_() []string {
	return strings.Split(rs(), " ")
}

func ri_() []int {
	ss := rs_()
	nis := make([]int, len(ss))
	for i, s := range ss {
		nis[i] = mustParseInt(s)
	}
	return nis
}

func mustParseInt(s string) int {
	i, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return i
}

func main() {
	sc.Split(bufio.ScanWords)
	N := ri()
	ans := 0
	for i := 1; i <= N; i++ {
		ans += i * (N / i) * (N/i + 1) / 2
	}
	fmt.Println(ans)
}
