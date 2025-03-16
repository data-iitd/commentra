

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

	if s == "Sunny" {
		fmt.Println("Cloudy")
	} else if s == "Cloudy" {
		fmt.Println("Rainy")
	} else {
		fmt.Println("Sunny")
	}
}

