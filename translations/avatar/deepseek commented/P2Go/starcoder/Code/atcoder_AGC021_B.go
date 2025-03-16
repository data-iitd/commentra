package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n)
	xy := make([][2]int, n)
	for i := range xy {
		fmt.Scan(&xy[i][0], &xy[i][1])
	}
	for i := range xy {
		d := make([]float64, n)
		for j := range xy {
			if i == j {
				continue
			}
			d[j] = math.Atan2(float64(xy[i][0]-xy[j][0]), float64(xy[i][1]-xy[j][1]))
		}
		sort.Float64s(d)
		d = append(d, d[0]+2*math.Pi)
		ans := 0.0
		for j := 0; j < len(d)-1; j++ {
			if d[j+1]-d[j] >= math.Pi {
				ans += d[j+1] - d[j] - math.Pi
			}
		}
		fmt.Printf("%.10f\n", ans/(2*math.Pi))
	}
}

