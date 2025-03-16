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
	S, _ := reader.ReadString('\n')
	S = strings.TrimSpace(S)
	if S == "Sunny" {
		fmt.Println("Cloudy")
	} else if S == "Cloudy" {
		fmt.Println("Rainy")
	} else {
		fmt.Println("Sunny")
	}
}

