
package main

import "fmt"

func main() {
	var ip string
	fmt.Scan(&ip)
	st := ""
	if len(ip) != 1 {
		if ip[0] == "9" {
			st = "9"
			ip = ip[1:]
		}
		for i := 0; i < len(ip); i++ {
			if int(ip[i]) > 4 {
				n := 9 - int(ip[i])
				st += string(n)
			} else {
				st += string(ip[i])
			}
		}
	} else {
		st = ip
	}
	fmt.Println(int(st))
}

