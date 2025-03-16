
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var n int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d\n", &n)
	for ; n > 0; n-- {
		s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
		s = strings.Replace(s, "Hoshino", "a", -1)
		fmt.Print(s)
	}
}

