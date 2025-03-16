
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
		s := scanner.Text()
		vs := strings.Split(s, " ")
		x, _ := strconv.ParseFloat(vs[0], 64)
		y, _ := strconv.ParseFloat(vs[1], 64)
		xy = append(xy, [2]float64{x, y})
	}
	var ans float64
	for i := 0; i < n; i++ {
		var d []float64
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			x1, y1 := xy[i][0], xy[i][1]
			x2, y2 := xy[j][0], xy[j][1]
			d = append(d, math.Atan2(y2-y1, x2-x1))
		}
		d = append(d, d[0]+2*math.Pi)
		for j := 0; j < n-1; j++ {
			if d[j+1]-d[j] >= math.Pi {
				ans += d[j+1] - d[j] - math.Pi
			}
		}
	}
	fmt.Println(ans / (2 * math.Pi))
}

