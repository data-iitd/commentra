package main

import (
	"fmt"
	"strconv"
)

func main() {
	var ip string
	fmt.Scan(&ip)

	var st string

	if len(ip) != 1 {
		if ip[0:1] == "9" {
			st = "9"
			ip = ip[1:]
		}

		for i := 0; i < len(ip); i++ {
			if int(ip[i]-'0') > 4 {
				n := 9 - int(ip[i]-'0')
				st += strconv.Itoa(n)
			} else {
				st += string(ip[i])
			}
		}
	} else {
		st = ip
	}

	result, _ := strconv.Atoi(st)
	fmt.Println(result)
}

