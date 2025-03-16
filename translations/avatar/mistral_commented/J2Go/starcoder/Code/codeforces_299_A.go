
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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	a := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	sort.Ints(a)
	min := a[0]
	for _, value := range a {
		if value%min!= 0 {
			fmt.Println(-1)
			return
		}
	}
	fmt.Println(min)
}

