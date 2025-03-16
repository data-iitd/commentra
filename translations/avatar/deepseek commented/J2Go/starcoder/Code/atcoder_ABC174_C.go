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
	K, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	if K%2 == 0 || K%5 == 0 {
		fmt.Println(-1)
		return
	}
	if K%7 == 0 {
		K /= 7
	}
	K *= 9
	ans := 1
	remainder := 10 % K
	for remainder!= 1 {
		ans++
		remainder = remainder*10 % K
	}
	fmt.Println(ans)
}

