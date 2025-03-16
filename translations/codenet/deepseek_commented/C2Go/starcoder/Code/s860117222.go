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
	fmt.Print("Enter three integers: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	a, _ := strconv.ParseInt(input[:len(input)/2], 10, 64)
	b, _ := strconv.ParseInt(input[len(input)/2:], 10, 64)
	c, _ := strconv.ParseInt(input, 10, 64)
	d := c - a - b
	if (d > 0) && ((4 * a * b) < d * d) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

