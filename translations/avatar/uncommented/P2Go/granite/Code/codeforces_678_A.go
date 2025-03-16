
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	vamshi, _ := strconv.Atoi(reader.String())
	z, _ := strconv.Atoi(reader.String())
	fmt.Println(((vamshi / z) + 1) * z)
}

