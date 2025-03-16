
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter a number: ")
	ip, _ := reader.ReadString('\n')
	ip = ip[:len(ip)-1] // Remove the trailing newline character

	st := ""

	if len(ip)!= 1 {
		if ip[0] == "9" {
			st = "9"
			ip = ip[1:]
		}

		for _, i := range ip {
			if int(i-'0') > 4 {
				n := 9 - int(i-'0')
				st += string(n + '0')
			} else {
				st += string(i)
			}
		}
	} else {
		st = ip
	}

	result, _ := strconv.Atoi(st)
	fmt.Println(result)
}

