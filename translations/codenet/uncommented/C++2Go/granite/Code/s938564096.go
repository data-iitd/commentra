
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := 0
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &r)
	fmt.Println(r * r)
}

