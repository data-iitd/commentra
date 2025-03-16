

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	var r int
	fmt.Fscanf(reader, "%d\n", &r)

	fmt.Fprintf(writer, "%d\n", r*r)
	writer.Flush()
}

// 