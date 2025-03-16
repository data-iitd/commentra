
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var a float64
	var ave float64
	var i int
	for i = 0; i < 5; i++ {
		text, _ := reader.ReadString('\n')
		a, _ = strconv.ParseFloat(text, 64)
		if a <= 40 {
			ave += 40
		} else {
			ave += a
		}
	}
	ave /= 5.0
	fmt.Printf("%.0f\n", ave)
}

