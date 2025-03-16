<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Reading Input
	X, N := readInput()

	// If no values are excluded, print X and exit
	if N == 0 {
<<<<<<< HEAD
		fmt.Println(X)
=======
		fmt.Printf("%d\n", X)
>>>>>>> 98c87cb78a (data updated)
		os.Exit(0)
	}

	// Step 2: Initializing Arrays
	plus := make([]int, 256)
	minus := make([]int, 256)
	for i := 0; i < 256; i++ {
		plus[i] = i
		minus[i] = -i
	}

	// Step 3: Marking Excluded Values
	for i := 0; i < N; i++ {
		j := readInt()
		plus[j] = 0
	}

	// Step 4: Finding the Nearest Non-Zero Value
	i_min, min := 0, 1000
	for i := 255; i >= 0; i-- {
		if plus[i] == 0 && i > 0 {
			continue
		}
		k := X - plus[i]
		if k < 0 {
			k *= -1
		}
		if k <= min {
			min = k
			i_min = i
		}
	}

	// Step 5: Outputting the Result
<<<<<<< HEAD
	fmt.Println(i_min)
=======
	fmt.Printf("%d\n", i_min)
>>>>>>> 98c87cb78a (data updated)
}

func readInput() (int, int) {
	X := readInt()
	N := readInt()
	return X, N
}

func readInt() int {
	var i int
	fmt.Scanf("%d", &i)
	return i
}

