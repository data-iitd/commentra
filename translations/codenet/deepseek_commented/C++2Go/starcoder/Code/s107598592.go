<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array:")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	N, _ := strconv.Atoi(input)
	X := make([]int, N)
	Y := make([]int, N)
	fmt.Println("Enter the elements of the array:")
	for i := 0; i < N; i++ {
		fmt.Println("Enter element", i+1, ":")
		input, _ := reader.ReadString('\n')
		input = strings.Replace(input, "\n", "", -1)
		X[i], _ = strconv.Atoi(input)
		Y[i] = X[i]
	}
	sort.Ints(Y)
	y := Y[N/2]
	for i := 0; i < N; i++ {
		if X[i] < y {
			fmt.Println(y)
		} else {
			fmt.Println(y - 1)
		}
		fmt.Println("")
	}
}

