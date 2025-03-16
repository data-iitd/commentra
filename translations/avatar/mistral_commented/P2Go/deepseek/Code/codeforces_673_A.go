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

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &arr[i])
	}

	if arr[0] > 15 {
		fmt.Fprintln(writer, 15)
	} else {
		for i := 1; i < n; i++ {
			if arr[i]-arr[i-1] > 15 {
				fmt.Fprintln(writer, arr[i-1]+15)
				break
			}
		}
		if arr[n-1] == 90 || arr[n-1]+15 >= 90 {
			fmt.Fprintln(writer, 90)
		} else {
			fmt.Fprintln(writer, arr[n-1]+15)
		}
	}
}

