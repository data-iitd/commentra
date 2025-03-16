
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanln(reader, &n)
	array := make([]int, 1001)
	for i := 0; i < n; i++ {
		var index int
		fmt.Fscanln(reader, &index)
		array[index]++
	}
	countMax := -1
	for i := 1; i < len(array); i++ {
		if countMax < array[i] {
			countMax = array[i]
		}
	}
	if n%2 == 0 {
		if countMax <= n/2 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	} else {
		if countMax <= n/2+1 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

