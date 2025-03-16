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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the number of queries")
	q, _ := strconv.Atoi(reader.ReadString('\n'))
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = i + 1
	}
	for i := 0; i < q; i++ {
		fmt.Println("Enter the left index")
		l, _ := strconv.Atoi(reader.ReadString('\n'))
		fmt.Println("Enter the right index")
		r, _ := strconv.Atoi(reader.ReadString('\n'))
		fmt.Println("Enter the winning index")
		w, _ := strconv.Atoi(reader.ReadString('\n'))
		for j := l - 1; j <= r-1; j++ {
			arr[j] = w
		}
		arr[w-1] = 0
	}
	fmt.Println(arr)
}

