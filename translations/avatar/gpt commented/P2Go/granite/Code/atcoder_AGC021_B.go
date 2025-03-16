
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	var xy [][2]float64
	for i := 0; i < n; i++ {
		scanner.Scan()
		x, _ := strconv.ParseFloat(scanner.Text(), 64)
		scanner.Scan()
		y, _ := strconv.ParseFloat(scanner.Text(), 64)
		xy = append(xy, [2]float64{x, y})
	}
	for i, [x, y] := range xy {
		var D []float64
		for j, [X, Y] := range xy {
			if i == j {
				continue
			}
			D = append(D, math.Atan2(Y-y, X-x))
		}
		D = append(D, D[0]+2*math.Pi)
		var ans float64
		for a, b := range D {
			if b-a >= math.Pi {
				ans = math.Max(ans, b-a-math.Pi)
			}
		}
		fmt.Printf("%.12f\n", ans/(2*math.Pi))
	}
}

