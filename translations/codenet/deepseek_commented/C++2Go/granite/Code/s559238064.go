
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
	z, _ := reader.ReadString('\n')
	z = strings.TrimSpace(z)
	a := len(z)
	for i := 0; i < a-1; i++ {
		if string(z[i]) == string(z[i+1]) {
			fmt.Println("Bad")
			return
		}
	}
	fmt.Println("Good")
}

