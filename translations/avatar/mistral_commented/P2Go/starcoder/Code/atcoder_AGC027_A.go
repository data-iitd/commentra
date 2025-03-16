
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
	fmt.Println("Enter the number of elements in the list:")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString( )))
	fmt.Println("Enter the value of x:")
	x, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString( )))
	a := make([]int, n)
	fmt.Println("Enter the elements of the list:")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString( )))
	}
	sort.Ints(a)
	ans := 0
	if a[0] > x {
		fmt.Println(0)
		return
	}
	for i := 0; i < n; i++ {
		if a[i] > x {
			x = 0
			break
		}
		x -= a[i]
		ans += 1
	}
	if x!= 0 {
		ans -= 1
	}
	fmt.Println(ans)
}

