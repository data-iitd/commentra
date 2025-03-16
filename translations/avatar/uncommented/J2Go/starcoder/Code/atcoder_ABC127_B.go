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
	writer := bufio.NewWriter(os.Stdout)
	r, _ := strconv.Atoi(scanner.Text())
	d, _ := strconv.Atoi(scanner.Text())
	x, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	for i := 0; i < 10; i++ {
		x = r*x - d
		fmt.Println(x)
	}
	writer.Flush()
}

