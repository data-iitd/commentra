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
	var X, A, B, C int
	var i, j, k int
	var kosu int

<<<<<<< HEAD
	// Input values for A, B, C, and X from the user
=======
>>>>>>> 98c87cb78a (data updated)
	fmt.Scanf("%d", &A)
	fmt.Scanf("%d", &B)
	fmt.Scanf("%d", &C)
	fmt.Scanf("%d", &X)

<<<<<<< HEAD
	// Divide X by 50 and assign the quotient to X
	X = X / 50

	// Three nested for loops to check if X can be represented as 10*i + 2*j + k
=======
	X = X / 50

>>>>>>> 98c87cb78a (data updated)
	for i = 0; i <= A; i++ {
		for j = 0; j <= B; j++ {
			for k = 0; k <= C; k++ {
				if X == (10*i) + (2*j) + k {
					kosu++
				}
			}
		}
	}

<<<<<<< HEAD
	// Print the result, which is the number of ways X can be represented as 10*i + 2*j + k
=======
>>>>>>> 98c87cb78a (data updated)
	fmt.Printf("%d\n", kosu)
}

