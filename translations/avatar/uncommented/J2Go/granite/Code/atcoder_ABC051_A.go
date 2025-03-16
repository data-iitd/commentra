
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter a string: ")
	text, _ := reader.ReadString('\n')
	text = strings.Replace(text, ",", " ", -1)
	fmt.Println(text)
}

// END-OF-CODE