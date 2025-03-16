<<<<<<< HEAD

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

=======
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	x, _ := strconv.Atoi(os.Args[1])
>>>>>>> 98c87cb78a (data updated)
	if x == 1 {
		fmt.Println("0")
	} else {
		fmt.Println("1")
	}
}

