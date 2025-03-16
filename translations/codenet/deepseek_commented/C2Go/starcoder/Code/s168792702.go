<<<<<<< HEAD

import "fmt"

func main() {
	var a, b, c int
	fmt.Scanf("%d %d %d", &a, &b, &c)

=======
_
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
	fmt.Print("Enter three integers: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	a, _ := strconv.Atoi(input[:len(input)/3])
	b, _ := strconv.Atoi(input[len(input)/3:2*len(input)/3])
	c, _ := strconv.Atoi(input[2*len(input)/3:])
>>>>>>> 98c87cb78a (data updated)
	if a < b && b < c {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

