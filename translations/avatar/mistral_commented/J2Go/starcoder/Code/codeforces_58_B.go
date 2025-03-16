
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
	fmt.Println("Enter the number")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	n, _ := strconv.Atoi(input)
	fmt.Println(n)
	m := n
	for i := n - 1; i > 0; i-- {
		if m%i == 0 {
			fmt.Println(i)
			m = i
		}
	}
}

