package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		N float64
		d float64
		x float64
	)

	N, d, x = get_input()
	ans := big.NewFloat(0)
	for N > 0.5 {
		adnum := big.NewFloat(d + x*(N-0.5))
		ans.Add(ans, adnum)
		d = (N+1.0)*d/N + (5.0*x)/(2.0*N)
		x = (1.0+(2.0/N))*x
		N -= 1
	}
	fmt.Printf("%.20f\n", ans)
}

func get_input() (float64, float64, float64) {
	var (
		N float64
		d float64
		x float64
	)

	N, d, x = get_input_from_stdin()
	return N, d, x
}

func get_input_from_stdin() (float64, float64, float64) {
	var (
		N float64
		d float64
		x float64
	)

	fmt.Scanf("%f %f %f", &N, &d, &x)
	return N, d, x
}

func get_input_from_file(filename string) (float64, float64, float64) {
	var (
		N float64
		d float64
		x float64
	)

	f, err := os.Open(filename)
	if err!= nil {
		panic(err)
	}
	defer f.Close()

	scanner := bufio.NewScanner(f)
	scanner.Scan()
	N, err = strconv.ParseFloat(strings.TrimSpace(scanner.Text()), 64)
	if err!= nil {
		panic(err)
	}
	scanner.Scan()
	d, err = strconv.ParseFloat(strings.TrimSpace(scanner.Text()), 64)
	if err!= nil {
		panic(err)
	}
	scanner.Scan()
	x, err = strconv.ParseFloat(strings.TrimSpace(scanner.Text()), 64)
	if err!= nil {
		panic(err)
	}
	return N, d, x
}

