
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
	fmt.Println("Enter two numbers: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	a, _ := strconv.Atoi(input)
	fmt.Println("Enter two numbers: ")
	input, _ = reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	b, _ := strconv.Atoi(input)
=======
	fmt.Println("Enter two integers a and b:")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	a, _ := strconv.Atoi(input)
	input, _ = reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	b, _ := strconv.Atoi(input)

>>>>>>> 98c87cb78a (data updated)
	if a <= 8 && b <= 8 {
		fmt.Println("Yay!")
	} else {
		fmt.Println(":(")
	}
}

