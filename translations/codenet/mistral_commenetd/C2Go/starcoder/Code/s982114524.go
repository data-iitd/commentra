
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var i, N, x int
	x = 0

	fmt.Print("Enter a number: ")
	N, _ = strconv.Atoi(os.Stdin.ReadString('\n'))

	for i = 1; i <= N; i++ {
		x += i
	}

	fmt.Printf("The sum of numbers from 1 to %d is: %d\n", N, x)
}

