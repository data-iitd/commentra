
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
	fmt.Print("Enter the number of elements: ")
	fmt.Scanf("%d", &n)
	a := make([]int, n)
	count := make([]int, n)
	fmt.Print("Enter ", n, " numbers:\n")
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	fmt.Print("Initializing count array with zeros:\n")
	for i := 0; i < n; i++ {
		count[i] = 0
	}
	fmt.Print("Counting occurrences:\n")
	for i := 0; i < n; i++ {
		count[a[i]-1]++
	}
	fmt.Print("Printing the contents of the count array:\n")
	for i := 0; i < n; i++ {
		fmt.Printf("%d\n", count[i])
	}
	fmt.Print("Program completed successfully.\n")
}

