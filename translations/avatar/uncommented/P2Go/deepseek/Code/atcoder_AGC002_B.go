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
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	N, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	M, _ := strconv.Atoi(line)

	balls := make([][2]int, N)
	balls[0] = [2]int{0, 1}

	for i := 0; i < M; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		parts := strings.Split(line, " ")
		x, _ := strconv.Atoi(parts[0])
		y, _ := strconv.Atoi(parts[1])

		w_x, r_x := balls[x-1][0], balls[x-1][1]
		w_y, r_y := balls[y-1][0], balls[y-1][1]

		if w_x >= 1 && r_x >= 1 {
			balls[x-1][0]--
			balls[y-1][1]++
		} else if w_x == 0 {
			balls[x-1][1]--
			balls[y-1][1]++
		} else {
			balls[x-1][0]--
			balls[y-1][0]++
		}
	}

	ans := 0
	for i := 0; i < N; i++ {
		if balls[i][1] > 0 {
			ans++
		}
	}
	fmt.Println(ans)
}
