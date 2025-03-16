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

	N, _ := strconv.Atoi(readLine(reader))
	V := stringsToInts(strings.Split(readLine(reader), " "))
	C := stringsToInts(strings.Split(readLine(reader), " "))

	list := []int{0}
	ans := 0
	X := 0
	Y := 0

	for i := 0; i < N; i++ {
		if V[i] - C[i] > 0 {
			X = V[i]
			Y = C[i]
			list = append(list, X - Y)
		}
	}

	sum := 0
	for _, value := range list {
		sum += value
	}

	fmt.Println(sum)
}

func readLine(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return strings.TrimSpace(str)
}

func stringsToInts(strs []string) []int {
	ints := make([]int, len(strs))
	for i, str := range strs {
		val, _ := strconv.Atoi(str)
		ints[i] = val
	}
	return ints
}
