
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		m, _ := reader.ReadString(' ')
		f, _ := reader.ReadString(' ')
		r, _ := reader.ReadString('\n')
		m = m[:len(m)-1]
		f = f[:len(f)-1]
		r = r[:len(r)-1]
		if m == "-1" || f == "-1" {
			fmt.Println("F")
		} else if mInt, _ := strconv.Atoi(m); fInt, _ := strconv.Atoi(f); mInt+fInt >= 80 {
			fmt.Println("A")
		} else if mInt+fInt >= 65 {
			fmt.Println("B")
		} else if mInt+fInt >= 50 || rInt, _ := strconv.Atoi(r); rInt >= 50 {
			fmt.Println("C")
		} else if mInt+fInt >= 30 {
			fmt.Println("D")
		} else {
			fmt.Println("F")
		}
		if m == "-1" && f == "-1" && r == "-1" {
			break
		}
	}
}
