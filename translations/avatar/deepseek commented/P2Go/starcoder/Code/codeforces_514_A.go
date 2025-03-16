
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	ip := os.Args[1]
	st := ""
	if len(ip)!= 1 {
		if ip[0] == "9" {
			st = "9"
			ip = ip[1:]
		}
		for i := 0; i < len(ip); i++ {
			if n, _ := strconv.Atoi(string(ip[i])); n > 4 {
				n = 9 - n
				st += string(n)
			} else {
				st += string(ip[i])
			}
		}
	} else {
		st = ip
	}
	fmt.Println(st)
}

