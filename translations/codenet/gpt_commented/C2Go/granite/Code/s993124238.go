
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	n, _ := strconv.Atoi(read(reader))
	d, _ := strconv.Atoi(read(reader))

	point := make([][]int, n+1)
	for i := 1; i <= n; i++ {
		point[i] = make([]int, d+1)
		for j := 1; j <= d; j++ {
			point[i][j], _ = strconv.Atoi(read(reader))
		}
	}

	count := 0
	for i := 1; i <= n-1; i++ {
		for j := i + 1; j <= n; j++ {
			sum := 0
			for k := 1; k <= d; k++ {
				sum = sum + (point[i][k]-point[j][k])*(point[i][k]-point[j][k])
			}
			kyori := math.Sqrt(float64(sum))
			if math.Ceil(kyori) == math.Floor(kyori) {
				count++
			}
		}
	}

	fmt.Println(count)
}

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}

	return string(str)
}

