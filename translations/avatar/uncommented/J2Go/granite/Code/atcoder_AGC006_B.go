
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	x, _ := strconv.Atoi(reader.ReadLine()[2:])
	print(x, n)
}

func print(x, n int) {
	max := n*2 - 1
	if x == 1 || x == max {
		fmt.Println("No")
		return
	}
	fmt.Println("Yes")
	sep := "\n"
	ans := ""
	for i := x + n - 1; i < x+n+max-1; i++ {
		ans += strconv.Itoa((i%max+1)) + sep
	}
	fmt.Println(ans)
}

