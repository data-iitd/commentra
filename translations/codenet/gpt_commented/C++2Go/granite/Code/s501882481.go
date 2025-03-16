
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
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)

	switch s {
	case "Sunny":
		fmt.Println("Cloudy")
	case "Cloudy":
		fmt.Println("Rainy")
	default:
		fmt.Println("Sunny")
	}
}

