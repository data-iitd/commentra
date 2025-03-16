package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	var x []float64
	var i int
	var s string
	var err error
	var f float64

	N, err = strconv.Atoi(strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString('\n')))
	if err!= nil {
		fmt.Println(err)
		return
	}

	x = make([]float64, N)
	for i = 0; i < N; i++ {
		s, err = bufio.NewReader(os.Stdin).ReadString('\n')
		if err!= nil {
			fmt.Println(err)
			return
		}
		s = strings.TrimSpace(s)
		s = strings.Replace(s, "JPY", "* 1.0", -1)
		s = strings.Replace(s, "BTC", "* 380000.0", -1)
		f, err = strconv.ParseFloat(s, 64)
		if err!= nil {
			fmt.Println(err)
			return
		}
		x[i] = f
	}

	fmt.Println(sum(x))
}

func sum(x []float64) float64 {
	var s float64
	for _, v := range x {
		s += v
	}
	return s
}

