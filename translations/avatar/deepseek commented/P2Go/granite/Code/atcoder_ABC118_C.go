

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
	fmt.Print("Enter the number of elements in the list: ")
	N, _ := reader.ReadString('\n')
	N, _ = strconv.Atoi(strings.TrimSpace(N))
	fmt.Print("Enter the elements of the list separated by spaces: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	A := strings.Split(input, " ")
	var gcd int
	for _, v := range A {
		v, _ := strconv.Atoi(v)
		gcd = gcd(gcd, v)
	}
	fmt.Println(gcd)
}

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

