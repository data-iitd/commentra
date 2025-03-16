package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	n, _ := strconv.Atoi(sc.Text())
	ans := 0

	for i := 1; i < n+1; i++ {
		ans += i * (n/i)*(n/i+1)/2
	}

	fmt.Println(ans)
}

