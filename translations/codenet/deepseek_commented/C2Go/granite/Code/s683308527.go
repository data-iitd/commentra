
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
	for scanner.Scan() {
		line := scanner.Text()
		for _, s := range strings.Split(line, "Hoshino") {
			line = strings.Replace(line, s, "Hoshina", 1)
		}
		fmt.Println(line)
	}
	if err := scanner.Err(); err!= nil {
		fmt.Println(err)
	}
}

