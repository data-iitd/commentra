<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

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
		line = strings.TrimSpace(string(line))
		if line == "?" {
			break
		}
		a, b, s := line[0:1], line[2:3], line[3:4]
		a, b = strconv.Atoi(a)
		if s == "+" {
			fmt.Println(a + b)
		} else if s == "-" {
			fmt.Println(a - b)
		} else if s == "*" {
			fmt.Println(a * b)
		} else if s == "/" {
			fmt.Println(a / b)
		}
	}
}

