
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
			w++
			x /= 10
		}
		fmt.Println(w)
	}
}

// This is the translated Go code that performs the same functionality as the original C code.

