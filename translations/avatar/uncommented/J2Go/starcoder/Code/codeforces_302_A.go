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
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the number of queries")
	k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	arr := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
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
		fmt.Println("Enter the left and right indices of the subarray")
		l, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		r, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		if (r - l + 1) % 2 == 1 {
			res += "0\n"
		} else {
			if (r - l + 1) / 2 <= o && (r - l + 1) / 2 <= e {
				res += "1\n"
			} else {
				res += "0\n"
			}
		}
	}
	fmt.Print(res)
}

