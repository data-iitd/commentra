

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var x int
	fmt.Fscanf(reader, "%d\n", &x)
	ans := x + x*x + x*x*x
	fmt.Println(ans)
}

