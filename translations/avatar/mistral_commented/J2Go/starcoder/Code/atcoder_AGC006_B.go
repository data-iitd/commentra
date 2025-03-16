
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
	fmt.Println("Enter the number of elements in the sequence:")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the index of the element to be found:")
	x, _ := strconv.Atoi(reader.ReadString('\n'))
	print(x, n)
}

func print(x, n int) {
	max := n * 2 - 1
	if x == 1 || x == max {
		fmt.Println("No")
		return
	}
	fmt.Println("Yes")
	sep := "\n"
	ans := strings.Builder{}
	for e := x + n - 1; e < x+n+max-1; e++ {
		ans.WriteString(fmt.Sprintf("%d%s", (e%max+1), sep))
	}
	fmt.Println(ans.String())
}

