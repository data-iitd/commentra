
package main

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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	array := make([]int, 3*n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < len(array); i++ {
		array[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	sort.Ints(array)
	head := len(array) - 2
	res := 0
	for i := 0; i < n; i++ {
		res += array[head]
		head -= 2
	}
	fmt.Println(res)
}

