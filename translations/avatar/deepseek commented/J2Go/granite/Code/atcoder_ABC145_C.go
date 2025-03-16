
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	pos := make([][]int, N)
	for i := 0; i < N; i++ {
		pos[i] = readNdArrayRow(reader, 2)
	}
	sum := 0.0
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			if i == j {
				continue
			}
			sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1])
		}
	}
	fmt.Println(sum / float64(N))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	panic(err)
}

func readNdArrayRow(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	row := readLine(reader)
	cols := strings.Split(row, " ")
	for i := 0; i < n; i++ {
		val, _ := strconv.Atoi(cols[i])
		res[i] = val
	}
	return res
}

func dist(x1 int, y1 int, x2 int, y2 int) float64 {
	return float64(
		int(
			float64(
				int(
					float64(
						int(
							float64(
								int(
									float64(
										int(
											float64(x1-x2)*(x1-x2) +
												int(float64(y1-y2)*(y1-y2))
										)
									)
								)
							)
						)
					)
				)
			)
		)
	)
}

