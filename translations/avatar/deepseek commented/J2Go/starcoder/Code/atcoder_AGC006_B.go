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
	fmt.Println("Enter the number of rows: ")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the number of columns: ")
	x, _ := strconv.Atoi(reader.ReadString('\n'))
	print(x, n)
}

// Method to print based on the value of x and n
func print(x, n int) {
	max := n * 2 - 1
	if x == 1 || x == max {
		fmt.Println("No")
		return
	}
	fmt.Println("Yes")
	sep := "\n"
	ans := strings.Builder{}
	for i := x + n - 1; i < x+n+max-1; i++ {
		ans.WriteString(fmt.Sprintf("%d%s", i%max+1, sep))
	}
	fmt.Println(ans.String())
}

