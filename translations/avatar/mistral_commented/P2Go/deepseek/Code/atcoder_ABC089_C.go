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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N int
	fmt.Fscan(reader, &N)

	S := make([][]string, N)
	for i := 0; i < N; i++ {
		line, _ := reader.ReadString('\n')
		S[i] = strings.Fields(line)
	}

	march := []string{"M", "A", "R", "C", "H"}
	march_lis := [5]int{0, 0, 0, 0, 0}
	var ans int

	for _, s := range S {
		firstChar := strings.ToUpper(s[0])
		for j, m := range march {
			if firstChar == m {
				march_lis[j]++
				break
			}
		}
	}

	for _, x := range march_lis {
		if x == 0 {
			continue
		}
		for _, y := range march_lis {
			if y == 0 {
				continue
			}
			for _, z := range march_lis {
				if z == 0 {
					continue
				}
				ans += x * y * z
			}
		}
	}

	fmt.Fprintln(writer, ans)
}
