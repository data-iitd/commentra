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
	fmt.Println("Enter the size of the array")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	n, _ := strconv.Atoi(input)
	a := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		fmt.Println("Enter the element", i+1)
		input, _ := reader.ReadString('\n')
		input = strings.Replace(input, "\n", "", -1)
		a[i], _ = strconv.Atoi(input)
	}
	fmt.Println("The last element of the array is", a[n-1])
	for i := 1; i < n; i++ {
		fmt.Print(" ", a[n-i-1])
	}
	fmt.Println()
}

