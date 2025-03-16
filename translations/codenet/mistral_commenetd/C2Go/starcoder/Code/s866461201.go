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
	var n int
	var fd [6]int
	var height float64
	var i, j int

	fmt.Scanf("%d", &n)
	for n > 0 {
<<<<<<< HEAD
		fmt.Scanf("%lf", &height)
=======
		fmt.Scanf("%f", &height)
>>>>>>> 98c87cb78a (data updated)
		if height >= 185.0 {
			fd[5]++
		} else if height >= 180.0 {
			fd[4]++
		} else if height >= 175.0 {
			fd[3]++
		} else if height >= 170.0 {
			fd[2]++
		} else if height >= 165.0 {
			fd[1]++
		} else {
			fd[0]++
		}
		n--
	}

	for i = 0; i < 6; i++ {
		fmt.Printf("%d:", i+1)
		for j = 0; j < fd[i]; j++ {
			fmt.Print("*")
		}
		fmt.Println("")
	}
}

