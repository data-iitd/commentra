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
	input, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(input))

	input, _ = reader.ReadString('\n')
	A := []int64{}
	for _, numStr := range strings.Split(strings.TrimSpace(input), " ") {
		num, _ := strconv.ParseInt(numStr, 10, 64)
		A = append(A, num)
	}

	result := int64(0)
	for b := 0; b < 60; b++ {
		var bs int64 = 0
		for _, a := range A {
			bs += (a >> int64(b)) & 1
		}
		result = (result + bs*(int64(N)-bs)*(1<<b)) % 1000000007
	}
	fmt.Println(result)
}
