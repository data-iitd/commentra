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
	input, _ := reader.ReadString('\n')
	parts := strings.Fields(input)
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])

	input, _ = reader.ReadString('\n')
	s := strings.TrimSpace(input)

	count := make([]int, 26)
	for _, c := range s {
		count[c-'A']++
	}

	sort.Slice(count, func(i, j int) bool {
		return count[i] > count[j]
	})

	res := 0
	for i := 0; i < 26; i++ {
		if count[i] >= k {
			res += k * k
			fmt.Println(res)
			return
		}
		k -= count[i]
		res += count[i] * count[i]
	}

	fmt.Println(res)
}

