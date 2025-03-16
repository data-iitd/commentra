package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	parts := strings.Split(line, " ")
	n := toInt(parts[0])
	m := toInt(parts[1])

	var differences []int

	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		sIndex := strings.Index(line, "S")
		gIndex := strings.Index(line, "G")
		if sIndex != -1 && gIndex != -1 {
			diff := gIndex - sIndex
			if diff >= 0 {
				differences = append(differences, diff)
			}
		}
	}

	uniqueDifferences := make(map[int]bool)
	for _, diff := range differences {
		uniqueDifferences[diff] = true
	}

	if len(uniqueDifferences) == 0 {
		fmt.Println(-1)
	} else {
		fmt.Println(len(uniqueDifferences))
	}
}

func toInt(s string) int {
	var num int
	fmt.Sscanf(s, "%d", &num)
	return num
}
