
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the size of the array: ")
	size, _ := reader.ReadString('\n')
	size, _ = strconv.Atoi(size)
	array := make([]int, size)
	fmt.Println("Enter", size, "integers:")
	for i := 0; i < size; i++ {
		input, _ := reader.ReadString('\n')
		array[i], _ = strconv.Atoi(input)
	}
	maxDiff := 0
	minDiff := 0
	for i := 0; i < size; i++ {
		if i == 0 {
			minDiff = array[i+1] - array[i]
		} else if i == size-1 {
			minDiff = array[i] - array[i-1]
		} else {
			minDiff = int(math.Min(float64(array[i]-array[i-1]), float64(array[i+1]-array[i])))
		}
		maxDiff = int(math.Max(float64(array[i]-array[0]), float64(array[size-1]-array[i])))
		fmt.Println(minDiff, maxDiff)
	}
}
