package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(readLine(reader))
	S := make([]int, 1<<N)
	spawned := make([]bool, 1<<N)
	spawned[1<<N-1] = true
	for i := 0; i < 1<<N; i++ {
		S[i], _ = strconv.Atoi(readLine(reader))
	}
	sort.Ints(S)
	active := make([]int, 0)
	active = append(active, S[1<<N-1])
	spawned[1<<N-1] = true
	for i := 0; i < N; i++ {
		sort.Slice(active, func(i, j int) bool {
			return active[i] > active[j]
		})
		activated := make([]int, 0)
		next := 1<<N - 1
		for slime := range active {
			for next >= 0 && (S[next] >= active[slime] || spawned[next]) {
				next--
			}
			if next < 0 {
				fmt.Println("No")
				return
			}
			spawned[next] = true
			activated = append(activated, S[next])
		}
		active = append(active, activated...)
	}
	fmt.Println("Yes")
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

