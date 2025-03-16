
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter an integer: ")
	text, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(text)

	var aaa func(n int) int
	aaa = func(n int) int {
		if n > N {
			return 0
		}
		ans := 1
		for _, i := range "753" {
			ans += aaa(n*10 + int(i-'0'))
		}
		return ans
	}

	fmt.Println(aaa(0))
}

