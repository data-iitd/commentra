
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	b, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	count := 0
	for a > 0 && b > 0 {
		count++
		a--
		b--
	}
	ans := a/2 + b/2
	fmt.Println(count, ans)
}

