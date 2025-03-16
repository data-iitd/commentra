package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	array := make([]int, 1001)
	for i := 0; i < n; i++ {
		var index int
		fmt.Fscan(reader, &index)
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
			fmt.Fprintln(writer, "YES")
		} else {
			fmt.Fprintln(writer, "NO")
		}
	} else {
		if countMax <= n/2+1 {
			fmt.Fprintln(writer, "YES")
		} else {
			fmt.Fprintln(writer, "NO")
		}
	}
}

// <END-OF-CODE>
