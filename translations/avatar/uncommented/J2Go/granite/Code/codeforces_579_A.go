
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a number: ")
	text, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(text)
	s := ""
	for n > 0 {
		x := n % 2
		n /= 2
		s += strconv.Itoa(x)
	}
	ans := 0
	for _, v := range s {
		if v == '1' {
			ans++
		}
	}
	fmt.Println(ans)
}

