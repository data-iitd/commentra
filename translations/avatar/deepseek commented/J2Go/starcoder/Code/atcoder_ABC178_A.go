
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
	fmt.Print("Enter an integer: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	x, _ := strconv.Atoi(input)
	bool := false
	if x == 1 {
		bool = true
	}
	result := 0
	if!bool {
		result = 1
	}
	fmt.Println(result)
}

