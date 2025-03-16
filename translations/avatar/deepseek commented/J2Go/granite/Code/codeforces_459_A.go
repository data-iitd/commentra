
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

	// Reading coordinates of two points
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	parts := strings.Split(input, " ")
	x1, _ := strconv.Atoi(parts[0])
	y1, _ := strconv.Atoi(parts[1])
	x2, _ := strconv.Atoi(parts[2])
	y2, _ := strconv.Atoi(parts[3])

	// Checking conditions to find the other two corners of a square or print -1
	if x1 == x2 {
		dif := int(math.Abs(float64(y1 - y2)))
		fmt.Fprintf(writer, "%d %d %d %d\n", x1+dif, y1, x1+dif, y2)
	} else if y1 == y2 {
		dif := int(math.Abs(float64(x1 - x2)))
		fmt.Fprintf(writer, "%d %d %d %d\n", x1, y1+dif, x2, y2+dif)
	} else if int(math.Abs(float64(x1 - x2))) == int(math.Abs(float64(y1 - y2))) {
		fmt.Fprintf(writer, "%d %d %d %d\n", x1, y2, x2, y1)
	} else {
		fmt.Fprintf(writer, "-1\n")
	}

	// Closing the writer to flush the output
	writer.Flush()
}

// Debugging method to print debug statements
func debug(obj...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

// END-OF-CODE