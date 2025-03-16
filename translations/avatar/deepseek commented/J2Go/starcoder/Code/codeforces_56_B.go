
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
	fmt.Println("Enter the length of the array")
	length, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the elements of the array")
	arr := make([]int, length)
	for i := 0; i < length; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	l := 0
	r := 0
	flag := false
	isTrue := false
	for i := 0; i < length; i++ {
		if arr[i]!= i+1 &&!flag {
			l = i + 1
			flag = true
			continue
		}
		if arr[i]!= i+1 && flag {
			r = i + 1
			if arr[r-1]-arr[r-2] > 0 {
				isTrue = true
				break
			}
		}
	}
	fmt.Println((!isTrue) && (l!= 0) && (r!= 0))
	fmt.Println(l, r)
}

