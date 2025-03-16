
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
	N, _ := strconv.Atoi(readerReadLine(reader))
	D, _ := strconv.Atoi(readerReadLine(reader))
	vectors := make([][]int, N)
	for i := 0; i < N; i++ {
		vector := make([]int, D)
		for j := 0; j < D; j++ {
			vector[j], _ = strconv.Atoi(readerReadLine(reader))
		}
		vectors[i] = vector
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
				answer++
			}
		}
	}
	fmt.Println(answer)
}

func readerReadLine(reader *bufio.Reader) string {
	line, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(line)
}

