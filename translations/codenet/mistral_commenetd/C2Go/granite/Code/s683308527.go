

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < n; i++ {
		scanner.Scan()
		s := scanner.Text()
		for _, c := range strings.Split(s, "Hoshino") {
			s = strings.Replace(s, c, "aana", -1)
		}
		fmt.Println(s)
	}
}

