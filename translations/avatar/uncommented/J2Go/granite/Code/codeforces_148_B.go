
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var VP, VD, T, F, C float64
	VP, _ = strconv.ParseFloat(read(), 64)
	VD, _ = strconv.ParseFloat(read(), 64)
	T, _ = strconv.ParseFloat(read(), 64)
	F, _ = strconv.ParseFloat(read(), 64)
	C, _ = strconv.ParseFloat(read(), 64)
	if VD <= VP {
		fmt.Println("0")
		return
	}
	answer := 0
	start := T
	for {
		x := start * VP / (VD - VP)
		if (start+x)*VP >= C {
			break
		}
		start += 2*x + F
		answer++
	}
	fmt.Println(answer)
}

func read() string {
	buf := make([]byte, 0)
	for {
		line, prefix, err := in.ReadLine()
		if err!= nil {
			panic(err)
		}
		buf = append(buf, line...)
		if prefix == false {
			break
		}
	}
	return string(buf)
}

