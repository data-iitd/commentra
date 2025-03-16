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
	var a, c, k, b int
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		a, _ = strconv.Atoi(scanner.Text())
		if a < 3 {
			fmt.Println(0)
			break
		}
		b = a
		c = 0
		k = 0
		for a > 0 {
			b--
			c++
			if c == 3 {
				k++
				c = 0
			}
			a--
		}
		fmt.Println(k)
	}
}

