package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	k := readInt(reader)
	t := 0
	for i := 1; i <= k; i++ {
		t = (t % k * 10 + 7) % k
		if t == 0 {
			fmt.Println(i)
			return
		}
	}
	fmt.Println(-1)
}

func readInt(reader *bufio.Reader) int {
	numStr, _ := reader.ReadString('\n')
	num, _ := strconv.Atoi(numStr[:len(numStr)-1])
	return num
}
