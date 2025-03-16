
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
	k, _ := strconv.Atoi(reader.ReadString('\n'))
	arr := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(reader.ReadString('\n'))
	}
	res := ""
	o := 0
	e := 0
	for i := 0; i < n; i++ {
		if arr[i] == 1 {
			o++
		} else {
			e++
		}
	}
	for i := 0; i < k; i++ {
		fmt.Println("Enter the left index of the query")
		l, _ := strconv.Atoi(reader.ReadString('\n'))
		fmt.Println("Enter the right index of the query")
		r, _ := strconv.Atoi(reader.ReadString('\n'))
		if (r - l + 1) % 2 == 1 {
			res += "0\n"
		} else {
			if (r - l + 1) / 2 <= o {
				res += "1\n"
			} else {
				res += "0\n"
			}
		}
	}
	fmt.Print(res)
}

