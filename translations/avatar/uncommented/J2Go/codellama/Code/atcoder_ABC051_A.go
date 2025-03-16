
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var a string
	scanner.Scan()
	a = scanner.Text()
	fmt.Println(strings.Replace(a, ",", " ", -1))
}

