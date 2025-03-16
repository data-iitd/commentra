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
	fmt.Println("Enter the number of points")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	pos := make([][]int, N)
	for i := 0; i < N; i++ {
		fmt.Println("Enter the coordinates of point", i+1)
		pos[i] = make([]int, 2)
		pos[i][0], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
		pos[i][1], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
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

func dist(x1, y1, x2, y2 int) float64 {
	return math.Sqrt(float64((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)))
}

