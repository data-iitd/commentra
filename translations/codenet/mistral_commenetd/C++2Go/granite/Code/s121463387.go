
package main

import (
	"bufio"
	"fmt"
	"math"
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
		s := strconv.Itoa(x)

		if x%3 == 0 || s[len(s)-1:] == "3" {
			fmt.Print(" " + strconv.Itoa(i))
			continue
		}

		for k := len(s) - 1; k >= 0; k-- {
			j := int(math.Pow(10, float64(k)))
			if (x/j)%10 == 3 {
				fmt.Print(" " + strconv.Itoa(i))
				break
			}
		}
	}
	fmt.Println()
}

