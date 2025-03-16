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
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var x1, y1, x2, y2 int
	fmt.Fscanf(reader, "%d %d %d %d", &x1, &y1, &x2, &y2)

	if x1 == x2 {
		dif := abs(y1 - y2)
		fmt.Fprintln(writer, x1+dif, " ", y1, " ", x1+dif, " ", y2)
	} else if y1 == y2 {
		dif := abs(x1 - x2)
		fmt.Fprintln(writer, x1, " ", y1+dif, " ", x2, " ", y2+dif)
	} else if abs(x1-x2) == abs(y1-y2) {
		fmt.Fprintln(writer, x1, " ", y2, " ", x2, " ", y1)
	} else {
		fmt.Fprintln(writer, -1)
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func debug(obj...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

