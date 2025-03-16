
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
	fmt.Print("Enter a number: ")
	text, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(text))

	for i := 1; i <= n; i++ {
		x := i
		s := fmt.Sprint(x)
		if x%3 == 0 || x%10 == 3 {
			fmt.Print(" ", i)
			continue
		} else {
			k := len(s)
			for k > 0 {
				k = k - 1
				j := int(math.Pow(10, float64(k)))
				if (x/j)%10 == 3 {
					fmt.Print(" ", i)
					break
				}
			}
		}
	}
	fmt.Println()
}

