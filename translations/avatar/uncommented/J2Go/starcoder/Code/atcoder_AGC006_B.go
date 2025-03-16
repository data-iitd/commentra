package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	x, _ := strconv.Atoi(scanner.Text())
	print(x, n)
}

func print(x, n int) {
	max := n * 2 - 1
	if x == 1 || x == max {
		fmt.Println("No")
		return
	}
	fmt.Println("Yes")
	sep := "\n"
	ans := strings.Builder{}
	for e := x + n - 1; e <= x+n+max-1; e++ {
		ans.WriteString(fmt.Sprintf("%d%s", e%max+1, sep))
	}
	fmt.Println(ans.String())
}

