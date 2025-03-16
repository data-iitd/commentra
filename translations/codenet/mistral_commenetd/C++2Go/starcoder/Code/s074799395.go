
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	B, _ := reader.ReadByte()
	B = strings.ToUpper(string(B))
	var OUT string
	if B == "A" {
		OUT = "T"
	} else if B == "T" {
		OUT = "A"
	} else if B == "C" {
		OUT = "G"
	} else {
		OUT = "C"
	}
	fmt.Println(OUT)
}

