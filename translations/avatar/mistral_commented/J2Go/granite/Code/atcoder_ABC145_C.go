
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
	checkError(err)
	n := int32(nTemp)

	pos := make([][]int32, n)

	for i := int32(0); i < n; i++ {
		pos[i] = make([]int32, 2)

		xTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		pos[i][0] = int32(xTemp)

		yTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
		checkError(err)
		pos[i][1] = int32(yTemp)
	}

	var sum float64

	for i := int32(0); i < n; i++ {
		for j := int32(0); j < n; j++ {
			if i == j {
				continue
			}

			sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1])
		}
	}

	fmt.Println(sum / float64(n))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}

	return ""
}

func checkError(err error) {
	if err!= nil {
		panic(err)
	}
}

func dist(x1 int32, y1 int32, x2 int32, y2 int32) float64 {
	return float64(
		((x1 - x2) * (x1 - x2)) +
			((y1 - y2) * (y1 - y2)),
	)
}

