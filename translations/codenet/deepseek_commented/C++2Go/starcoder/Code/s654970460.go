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
	fmt.Print("Enter the number of elements for the array: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	n, _ := strconv.Atoi(input)
	a := make([]int, n)
<<<<<<< HEAD
=======
	fmt.Print("Enter the elements of the array: ")
>>>>>>> 98c87cb78a (data updated)
	for i := 0; i < n; i++ {
		fmt.Print("Enter the element: ")
		input, _ := reader.ReadString('\n')
		input = strings.Replace(input, "\n", "", -1)
		a[i], _ = strconv.Atoi(input)
	}
	fmt.Print("The last element of the array is: ", a[n-1])
	for i := 1; i < n; i++ {
		fmt.Print(" ", a[n-i-1])
	}
	fmt.Println()
}

