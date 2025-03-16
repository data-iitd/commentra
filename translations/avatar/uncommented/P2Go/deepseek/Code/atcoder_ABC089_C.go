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
	N, _ := strconv.Atoi(strings.TrimSpace(line))
	S := make([]string, N)
	for i := 0; i < N; i++ {
		S[i], _ = reader.ReadString('\n')
		S[i] = strings.TrimSpace(S[i])
	}

	march := []string{"M", "A", "R", "C", "H"}
	march_lis := [5]int{0, 0, 0, 0, 0}
	for _, s := range S {
		firstChar := strings.ToUpper(string(s[0]))
		for j, m := range march {
			if firstChar == m {
				march_lis[j]++
				break
			}
		}
	}

	var ans int
	for i := 0; i < 3; i++ {
		for j := i + 1; j < 4; j++ {
			for k := j + 1; k < 5; k++ {
				ans += march_lis[i] * march_lis[j] * march_lis[k]
			}
		}
	}
	fmt.Println(ans)
}
