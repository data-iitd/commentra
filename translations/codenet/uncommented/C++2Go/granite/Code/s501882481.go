
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	if s == "Sunny" {
		fmt.Println("Cloudy")
	} else if s == "Cloudy" {
		fmt.Println("Rainy")
	} else {
		fmt.Println("Sunny")
	}
}

