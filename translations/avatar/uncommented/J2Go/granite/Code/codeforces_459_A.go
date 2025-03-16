
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

	var x1, y1, x2, y2 int
	fmt.Fscanf(reader, "%d %d %d %d\n", &x1, &y1, &x2, &y2)

	if x1 == x2 {
		dif := int(math.Abs(float64(y1 - y2)))
		fmt.Fprintf(writer, "%d %d %d %d\n", x1+dif, y1, x2+dif, y2)
	} else if y1 == y2 {
		dif := int(math.Abs(float64(x1 - x2)))
		fmt.Fprintf(writer, "%d %d %d %d\n", x1, y1+dif, x2, y2+dif)
	} else if int(math.Abs(float64(x1 - x2))) == int(math.Abs(float64(y1 - y2))) {
		fmt.Fprintf(writer, "%d %d %d %d\n", x1, y2, x2, y1)
	} else {
		fmt.Fprintf(writer, "-1\n")
	}

	writer.Flush()
}

// 