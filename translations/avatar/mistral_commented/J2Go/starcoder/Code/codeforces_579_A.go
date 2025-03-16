
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
	fmt.Println("Enter a number: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	n, _ := strconv.Atoi(input)
	s := ""
	for n > 0 {
		x := n % 2
		n /= 2
		s += string(x)
	}
	ans := 0
	for i := 0; i < len(s); i++ {
		if s[i] == '1' {
			ans++
		}
	}
	fmt.Println(ans)
}

