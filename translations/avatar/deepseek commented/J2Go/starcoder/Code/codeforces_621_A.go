
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
	fmt.Println("Enter the number of elements")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	list := make([]int, n)
	fmt.Println("Enter the elements")
	for i := 0; i < n; i++ {
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
	sort.Ints(odd)
	for i := 0; i < len(odd); i++ {
		sum += odd[i]
	}
	if len(odd)%2!= 0 {
		sum -= odd[0]
	}
	fmt.Println(sum)
}

