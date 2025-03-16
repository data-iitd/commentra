
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, levels int
	fmt.Fscanf(reader, "%d %d\n", &n, &levels)

	arr := make([]int, levels)
	for i := 0; i < levels; i++ {
		fmt.Fscanf(reader, "%d", &arr[i])
	}

	var level2 int
	fmt.Fscanf(reader, "%d\n", &level2)

	level3 := levels + level2
	arr2 := make([]int, level3)
	copy(arr2, arr)

	for i := levels; i < level3; i++ {
		fmt.Fscanf(reader, "%d", &arr2[i])
	}

	arr3 := make([]int, n)
	j := 0
	for i := 0; i < n; i++ {
		j++
		arr3[i] = j
	}

	count := 0
	for i := 0; i < n; i++ {
		for x := 0; x < level3; x++ {
			if arr3[i] == arr2[x] {
				count++
				break
			}
		}
	}

	if count == n {
		fmt.Println("I become the guy.")
	} else {
		fmt.Println("Oh, my keyboard!")
	}
}
