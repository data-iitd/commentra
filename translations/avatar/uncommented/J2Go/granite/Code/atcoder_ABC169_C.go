
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

	var a int64
	fmt.Fscanf(reader, "%d\n", &a)

	var b string
	fmt.Fscanf(reader, "%s\n", &b)

	b = strings.Replace(b, ".", "", -1)
	bInt, _ := strconv.Atoi(b)

	result := (a * int64(bInt)) / 100
	fmt.Println(result)
}

