<<<<<<< HEAD

import "fmt"

func main() {
	// Declare variables
	var n, fd [6]int
=======
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables
	var n int
	var fd [6]int
>>>>>>> 98c87cb78a (data updated)
	var i, j int
	var height float64

	// Read the number of heights
	fmt.Scanf("%d", &n)

	// Loop to read each height and categorize it
	for n > 0 {
		fmt.Scanf("%f", &height)
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

	// Loop to print the histogram
	for i = 0; i < 6; i++ {
		fmt.Printf("%d:", i+1)
		for j = 0; j < fd[i]; j++ {
			fmt.Printf("*")
		}
		fmt.Println("")
	}
}

