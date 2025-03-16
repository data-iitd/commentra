
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
<<<<<<< HEAD
	fmt.Println("Enter two integers:")
=======
	fmt.Print("Enter two integers: ")
>>>>>>> 98c87cb78a (data updated)
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	a, _ := strconv.Atoi(input)
<<<<<<< HEAD
=======
	fmt.Print("Enter another two integers: ")
>>>>>>> 98c87cb78a (data updated)
	input, _ = reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	b, _ := strconv.Atoi(input)
	fmt.Println(a * b)
}

