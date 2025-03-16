
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

// Main function starts here
func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the vector a")
	input, _ := reader.ReadString('\n')
<<<<<<< HEAD
	input = strings.TrimSpace(input)
	n, _ := strconv.Atoi(input)
=======
	n, _ := strconv.Atoi(strings.TrimSpace(input))
>>>>>>> 98c87cb78a (data updated)
	fmt.Println("Enter the elements of the vector a")
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Println("Enter the", i+1, "element of the vector a")
		input, _ := reader.ReadString('\n')
<<<<<<< HEAD
		input = strings.TrimSpace(input)
		a[i], _ = strconv.Atoi(input)
=======
		a[i], _ = strconv.Atoi(strings.TrimSpace(input))
>>>>>>> 98c87cb78a (data updated)
	}
	ans := 0
	ok := true
	for ok {
		for i := 0; i < n; i++ {
			if a[i]%2 == 1 {
				fmt.Println(ans)
				return
			}
			a[i] /= 2
		}
		ans++
		ok = false
	}
	fmt.Println(ans)
}

