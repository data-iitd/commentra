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
<<<<<<< HEAD
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err!= nil {
			break
		}
		line = strings.TrimSpace(line)
		a, _ := strconv.Atoi(line)
		if a < 3 {
			fmt.Println(0)
		} else {
			b := a
			c := 0
			k := 0
=======
	var a, c, k, b int
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		a, _ = strconv.Atoi(scanner.Text())
		c, k = 0, 0
		if a < 3 {
			fmt.Println(0)
		} else {
			b = a
>>>>>>> 98c87cb78a (data updated)
			for a > 0 {
				b--
				c++
				if c == 3 {
					k++
					c = 0
				}
<<<<<<< HEAD
				a--
=======
>>>>>>> 98c87cb78a (data updated)
			}
			fmt.Println(k)
		}
	}
}

