
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
	fmt.Println("Enter the string")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	n, _ := strconv.Atoi(input)
	input, _ = reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	if input == (string(input[0:n/2]) + string(input[0:n/2])) {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

