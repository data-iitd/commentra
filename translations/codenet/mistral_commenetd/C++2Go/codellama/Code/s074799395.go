
package main

import "fmt"

func main() {
	var b byte
	var out byte

	fmt.Scan(&b)

	if b == 'A' {
		out = 'T'
	} else if b == 'T' {
		out = 'A'
	} else if b == 'C' {
		out = 'G'
	} else {
		out = b
	}

	fmt.Println(string(out))
}

