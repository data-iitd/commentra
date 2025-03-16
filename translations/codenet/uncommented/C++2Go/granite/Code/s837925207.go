
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	x, _ := strconv.Atoi(reader.ReadLine())
	ans := x + x*x + x*x*x
	fmt.Println(ans)
}

