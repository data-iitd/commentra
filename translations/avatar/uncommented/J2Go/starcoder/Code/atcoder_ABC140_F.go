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
	fmt.Println("Enter the number of slimes")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString(make([]byte, 1024))))
	size := 1 << N
	S := make([]int, size)
	spawned := make([]bool, size)
	spawned[size-1] = true
	for i := 0; i < size; i++ {
		S[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString(make([]byte, 1024))))
	}
	sort.Ints(S)
	active := make([]int, 0)
	active = append(active, S[size-1])
	spawned[size-1] = true
	for i := 0; i < N; i++ {
		sort.Slice(active, func(i, j int) bool {
			return active[i] > active[j]
		})
		activated := make([]int, 0)
		next := size - 1
		for _, slime := range active {
			for next >= 0 && (S[next] >= slime || spawned[next]) {
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

