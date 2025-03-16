
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

func main() {
	const (
		ioBufSize = 1 * 1024 * 1024 // 1 MB
	)
	var (
		r   = bufio.NewReaderSize(os.Stdin, ioBufSize)
		w   = bufio.NewWriterSize(os.Stdout, ioBufSize)
		n   int
		xy  [][2]int
		ans []float64
	)
	fmt.Fscanf(r, "%d\n", &n)
	xy = make([][2]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(r, "%d %d\n", &xy[i][0], &xy[i][1])
	}
	for i := 0; i < n; i++ {
		d := make([]float64, n-1)
		for j, p := range xy {
			if i == j {
				continue
			}
			d[j-1] = math.Atan2(float64(p[0]-xy[i][0]), float64(p[1]-xy[i][1]))
		}
		sort.Float64s(d)
		d = append(d, d[0]+2*math.Pi)
		a := 0.0
		for j := 0; j < n-1; j++ {
			if d[j+1]-d[j] >= math.Pi {
				a = math.Max(a, d[j+1]-d[j]-math.Pi)
			}
		}
		ans = append(ans, a/(2*math.Pi))
	}
	for _, a := range ans {
		fmt.Fprintf(w, "%.12f\n", a)
	}
	w.Flush()
}

