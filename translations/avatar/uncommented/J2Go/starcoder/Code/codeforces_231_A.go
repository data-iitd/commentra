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
	t, _ := strconv.Atoi(sc.Text())
	count := 0
	for t > 0 {
		a, _ := strconv.Atoi(sc.Text())
		b, _ := strconv.Atoi(sc.Text())
		c, _ := strconv.Atoi(sc.Text())
		if (a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1) {
			count++
		}
		t--
	}
	fmt.Println(count)
}

