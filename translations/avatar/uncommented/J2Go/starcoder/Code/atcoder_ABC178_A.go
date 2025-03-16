package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scan := bufio.NewScanner(os.Stdin)
	scan.Scan()
	x, _ := strconv.Atoi(scan.Text())
	bool := x == 1
	result := 0
	if!bool {
		result = 1
	}
	fmt.Println(result)
}

