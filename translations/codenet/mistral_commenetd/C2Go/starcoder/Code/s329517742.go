
<<<<<<< HEAD

import "fmt"

func main() {
	var a, b int
	fmt.Scanf("%d %d", &a, &b)

=======
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a, b int
	fmt.Fscan(os.Stdin, &a, &b)
>>>>>>> 98c87cb78a (data updated)
	if 500*a >= b {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

