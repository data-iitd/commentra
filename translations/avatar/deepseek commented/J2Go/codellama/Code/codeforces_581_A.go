
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var a, b int
	fmt.Print("Enter two integers: ")
	scanner.Scan()
	a, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	b, _ = strconv.Atoi(scanner.Text())
	var count int
	for {
		if a > 0 && b > 0 {
			count++
			a--
			b--
		} else {
			break
		}
	}
	ans := a/2 + b/2
	fmt.Println(count, ans)
}

