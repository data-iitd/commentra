package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	N, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	D, _ := strconv.Atoi(sc.Text())
	vectors := make([][]int, N)
	for i := 0; i < N; i++ {
		vectors[i] = make([]int, D)
		for j := 0; j < D; j++ {
			sc.Scan()
			vectors[i][j], _ = strconv.Atoi(sc.Text())
		}
	}
	answer := 0
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			dist := 0
			for d := 0; d < D; d++ {
				x := vectors[i][d] - vectors[j][d]
				dist += x * x
			}
			sq := math.Sqrt(float64(dist))
			if math.Abs(sq-math.Floor(sq)) < 0.001 {
				answer += 1
			}
		}
	}
	fmt.Println(answer)
}

