
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

	fmt.Print("Enter the value of n: ")
	n, _ := strconv.Atoi(reader.ReadLine()[0])

	fmt.Print("Enter the value of k: ")
	k, _ := strconv.Atoi(reader.ReadLine()[0])

	fmt.Print("Enter the string a: ")
	a := reader.ReadLine()[0]

	if k > n/2 {
		for k < n {
			fmt.Println("RIGHT")
			k++
		}
	} else {
		for k > 1 {
			fmt.Println("LEFT")
			k--
		}
	}

	if k == 1 {
		for i := 0; i < len(a); i++ {
			fmt.Println("PRINT " + string(a[i]))
			if i < len(a)-1 {
				fmt.Println("RIGHT")
			}
		}
	} else {
		for i := len(a) - 1; i >= 0; i-- {
			fmt.Println("PRINT " + string(a[i]))
			if i > 0 {
				fmt.Println("LEFT")
			}
		}
	}
}

