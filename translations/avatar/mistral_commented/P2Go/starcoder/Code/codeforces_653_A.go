
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
	fmt.Print("Enter the number of elements in the list: ")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Print("Enter the list of integers: ")
	l := make([]int, n)
	for i := 0; i < n; i++ {
		l[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	sort.Ints(l)
	for i := 0; i < n; i++ {
		if l[i]+1 < n && l[i]+2 < n {
			fmt.Println("YES")
			break
		}
	}
	if i == n-1 {
		fmt.Println("NO")
	}
}

