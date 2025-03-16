package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func readInt() int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	num, _ := strconv.Atoi(strings.TrimSpace(line))
	return num
}

func readInts() []int {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(line), " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

func main() {
	N := readInt()
	S := readInts()
	sort.Slice(S, func(i, j int) bool { return S[i] > S[j] })
	flag := make([]bool, len(S))
	cur := []int{S[0]}
	flag[0] = false
	for i := 0; i < N; i++ {
		j := 0
		jM := len(cur)
		for k := 0; k < len(S); k++ {
			if flag[k] && S[k] < cur[j] {
				cur = append(cur, S[k])
				j++
				flag[k] = false
				if j == jM {
					break
				}
			}
		}
		if j == jM {
			fmt.Println("No")
			return
		}
		sort.Slice(cur, func(i, j int) bool { return cur[i] > cur[j] })
	}
	fmt.Println("Yes")
}
