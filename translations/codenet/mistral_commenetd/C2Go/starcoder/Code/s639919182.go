
<<<<<<< HEAD

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)
=======
package main

import "fmt"
>>>>>>> 98c87cb78a (data updated)

func main() {
	var v [10]int
	var sum int
	var i int

	for i = 0; i < 10; i++ {
		fmt.Printf("Enter the value for index %d: ", i)
<<<<<<< HEAD
		v[i], _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))
		// Read an integer value from the user and store it in the current index of the array 'v'.
=======
		fmt.Scanf("%d", &v[i])
>>>>>>> 98c87cb78a (data updated)
	}

	for i = 0; i < 10; i++ {
		sum += v[i]
<<<<<<< HEAD
		// Add the value of the current element in the array 'v' to the variable'sum'.
	}

	fmt.Printf("%d\n", sum)
	// Display the sum of all elements in the array 'v'.
=======
	}

	fmt.Printf("%d\n", sum)
>>>>>>> 98c87cb78a (data updated)
}

