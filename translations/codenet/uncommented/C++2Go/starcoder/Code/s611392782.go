
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		s := scanner.Text()
		d, _ := strconv.Atoi(s[:len(s)-1])
		s = s[len(s)-1:]
		a := 0
		b := 0
		for i := 0; i < len(s); i++ {
			if s[i] == '+' {
				a += int(s[i+1] - '0')
				i++
			} else {
				a *= int(s[i+1] - '0')
				i++
			}
		}
		for i := 0; i < len(s); i++ {
			if s[i] == '+' {
				b += int(s[i+1] - '0')
				i++
			} else {
				b *= int(s[i+1] - '0')
				i++
			}
		}
		if a == d {
			if b == d {
				fmt.Println("U")
			} else {
				fmt.Println("M")
			}
		} else {
			if b == d {
				fmt.Println("L")
			} else {
				fmt.Println("I")
			}
		}
	}
}

