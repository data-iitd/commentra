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
	line1, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(line1))

	if n == 1 {
		fmt.Println("Hello World")
	} else {
		line2, _ := reader.ReadString('\n')
		line3, _ := reader.ReadString('\n')
		nums := strings.Fields(line2 + line3)
		sum := 0
		for _, numStr := range nums {
			num, _ := strconv.Atoi(numStr)
			sum += num
		}
		fmt.Println(sum)
	}
}

