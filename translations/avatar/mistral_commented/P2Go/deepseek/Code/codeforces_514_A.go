package main

import (
	"fmt"
	"strconv"
)

func main() {
	var ip string
	fmt.Scan(&ip)

	st := ""

	if len(ip) != 1 {
		if ip[0] == '9' {
			st = "9"
			ip = ip[1:]
		}

		for _, i := range ip {
			if int(i-'0') > 4 {
				n := 9 - int(i-'0')
				st += strconv.Itoa(n)
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

