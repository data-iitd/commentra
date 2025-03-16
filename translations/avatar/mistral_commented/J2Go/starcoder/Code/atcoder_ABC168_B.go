
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
	fmt.Println("Enter the length of the string")
	K, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the string")
	S := reader.ReadString('\n')
	if len(S) <= K {
		fmt.Println(S)
	} else {
		fmt.Println(S[:K] + "...")
	}
}

