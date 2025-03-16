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
	fmt.Println("Enter the number of elements in the list")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	list := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Println("Enter the element")
		list[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	odd := make([]int, 0)
	sum := 0
	for i := 0; i < n; i++ {
		if list[i]%2 == 0 {
			sum += list[i]
		} else {
			odd = append(odd, list[i])
		}
	}
	sort.Slice(odd, func(i, j int) bool { return odd[i] < odd[j] })
	for i := 0; i < len(odd); i++ {
		sum += odd[i]
	}
	if len(odd)%2!= 0 {
		sum -= odd[0]
	}
	fmt.Println(sum)
}

