
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	n, d := readInt(), readInt()
	point := make([][]int, n+1)
	for i := 1; i <= n; i++ {
		point[i] = make([]int, d+1)
		for j := 1; j <= d; j++ {
			point[i][j] = readInt()
		}
	}
	count := 0
	for i := 1; i <= n-1; i++ {
		for j := i + 1; j <= n; j++ {
			sum := 0
			for k := 1; k <= d; k++ {
				sum += (point[i][k] - point[j][k]) * (point[i][k] - point[j][k])
			}
			kyori := math.Sqrt(float64(sum))
			if math.Ceil(kyori) == math.Floor(kyori) {
				count++
			}
		}
	}
	fmt.Println(count)
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

