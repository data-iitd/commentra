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
	fmt.Print("Enter a number: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	a, _ := strconv.Atoi(input)
<<<<<<< HEAD
	fmt.Println(a + (a * a) + (a * a * a))
=======
	fmt.Printf("The value of the expression (a + (a * a) + (a * a * a)) is %d\n", a+a*a+a*a*a)
>>>>>>> 98c87cb78a (data updated)
}

