

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	sc = bufio.NewScanner(os.Stdin)
)

func main() {
	buf := make([]byte, 0)
	sc.Buffer(buf, 1010000)
	sc.Split(bufio.ScanWords)

	N := nextInt()

	min := int64(1 << 60)
	for i := 0; i < 5; i++ {
		a := nextInt64()
		if i == 0 {
			min = a
		} else {
			min = int64(math.Min(float64(min), float64(a)))
		}
	}

	ans := (N + min - 1) / min + 4
	fmt.Println(ans)
}

func nextString() string {
	sc.Scan()
	return sc.Text()
}

func nextNumber() float64 {
	sc.Scan()
	f, err := strconv.ParseFloat(sc.Text(), 32)
	if err!= nil {
		panic(err)
	}
	return f
}

func nextInt() int {
	sc.Scan()
	n, err := strconv.Atoi(sc.Text())
	if err!= nil {
		panic(err)
	}

	return n
}

func nextInt64() int64 {
	sc.Scan()
	n, err := strconv.ParseInt(sc.Text(), 10, 64)
	if err!= nil {
		panic(err)
	}

	return n
}

func print(args...interface{}) {
	fmt.Print(args...)
}

func println(args...interface{}) {
	fmt.Println(args...)
}

func printf(format string, args...interface{}) {
	fmt.Printf(format, args...)
}

