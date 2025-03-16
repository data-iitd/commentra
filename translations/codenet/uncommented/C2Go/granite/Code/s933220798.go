
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var a float64
	var ave float64 = 0
	var i int

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		a, _ = strconv.ParseFloat(scanner.Text(), 64)
		if a <= 40 {
			ave += 40
		} else {
			ave += a
		}
		i++
	}
	ave /= 5.0
	fmt.Println(int(ave))
}

