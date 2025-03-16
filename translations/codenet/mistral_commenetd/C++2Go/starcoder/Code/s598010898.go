
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
	fmt.Println("Enter the number of elements in the array")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	n, _ := strconv.Atoi(input)
	a := make([]int, n)
	b := make([]int, n)
	sum := 0
	fmt.Println("Enter the elements of the array a")
	for i := 0; i < n; i++ {
		fmt.Println("Enter the element a[", i, "]")
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		a[i], _ = strconv.Atoi(input)
	}
	fmt.Println("Enter the elements of the array b")
	for i := 0; i < n; i++ {
		fmt.Println("Enter the element b[", i, "]")
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		b[i], _ = strconv.Atoi(input)
		if a[i]-b[i] > 0 {
			sum += a[i] - b[i]
		}
	}
	fmt.Println("The sum of the differences is", sum)
}

