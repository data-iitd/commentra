
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

var (
	r, d int
	x     int64
)

func main() {
	r = nextInt()
	d = nextInt()
	x = nextInt64()
	for i := 0; i < 10; i++ {
		x = r*x - int64(d)
		fmt.Println(x)
	}
}

func nextString() string {
	sc.Scan()
	return sc.Text()
}

func nextNumber() int {
	i, err := strconv.Atoi(nextString())
	if err!= nil {
		panic(err)
	}
	return i
}

func nextInt() int {
	return int(nextInt64())
}

func nextInt64() int64 {
	sc.Scan()
	i, err := strconv.ParseInt(sc.Text(), 10, 64)
	if err!= nil {
		panic(err)
	}
	return i
}

var sc = bufio.NewScanner(os.Stdin)

func init() {
	sc.Buffer(make([]byte, 1024000), int(1e+9))
	sc.Split(bufio.ScanWords)
}

// END-OF-CODE