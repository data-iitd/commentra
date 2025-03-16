
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
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	a := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	sort.Ints(a)
	for i := 0; i < n-1; i++ {
		if a[i+1] < a[i]*2 && a[i]!= a[i+1] {
			fmt.Println("YES")
			return
		}
	}
	fmt.Println("NO")
}

