package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	scan := bufio.NewScanner(os.Stdin)
	N, _ := strconv.Atoi(scan.Text())
	x := make([]int, N)
	y := make([]int, N)
	for i := 0; i < N; i++ {
		x[i], _ = strconv.Atoi(scan.Text())
		y[i], _ = strconv.Atoi(scan.Text())
	}
	for i := 0; i < N; i++ {
		thetas := make([]float64, 0)
		for j := 0; j < N; j++ {
			if i == j {
				continue
			}
			thetas = append(thetas, math.Atan2(float64(y[j]-y[i]), float64(x[j]-x[i])))
		}
		sort.Float64s(thetas)
		thetas = append(thetas, thetas[0]+2*math.Pi)
		ans := 0.0
		for k := 0; k < N-1; k++ {
			ans = math.Max(ans, thetas[k+1]-thetas[k]-math.Pi)
		}
		fmt.Println(ans/(math.Pi*2))
	}
}

