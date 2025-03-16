
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
	for {
		line, _, err := reader.ReadLine()
		if err!= nil {
			break
		}
		parts := strings.Split(string(line), " ")
		a, _ := strconv.Atoi(parts[0])
		b, _ := strconv.Atoi(parts[1])
		x := a + b
		w := 0
		for x > 0 {
			x /= 10
			w++
		}
		fmt.Println(w)
	}
}

