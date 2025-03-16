
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
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	x, _ := strconv.Atoi(s)
	a := make(map[int]bool)
	a[x] = true
	d := 2
	for {
		if x%2 == 0 {
			x /= 2
		} else {
			x = 3*x + 1
		}
		if a[x] {
			fmt.Println(d)
			break
		}
		a[x] = true
		d++
	}
}

