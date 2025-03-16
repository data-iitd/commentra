
package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	fmt.Println(strings.Replace(os.Args[1], ",", " ", -1))
}

