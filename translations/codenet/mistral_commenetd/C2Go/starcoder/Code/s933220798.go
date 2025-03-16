
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
	var a float64
	var ave float64
	var i int

	for i = 0; i < 5; i++ {
		fmt.Println("Enter a number: ")
<<<<<<< HEAD
		fmt.Scanf("%lf", &a)
=======
		a, _ = strconv.ParseFloat(strings.TrimSpace(bufio.NewReader(os.Stdin).ReadString('\n')), 64)
>>>>>>> 98c87cb78a (data updated)

		if a <= 40 {
			ave += 40
			fmt.Printf("Number %d is less than or equal to 40. Adding 40 to the average.\n", i+1)
		} else {
			ave += a
			fmt.Printf("Number %d is greater than 40. Adding %f to the average.\n", i+1, a)
		}
	}

	ave /= 5.0
	fmt.Printf("The average of the 5 numbers is: %.0f\n", ave)
}

