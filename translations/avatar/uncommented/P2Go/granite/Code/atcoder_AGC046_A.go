
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
	x, _ := strconv.Atoi(text)
	gcd := func(a, b int) int {
		for b!= 0 {
			a, b = b, a%b
		}
		return a
	}
	result := 360 / gcd(360, x)
	fmt.Println(result)
}

