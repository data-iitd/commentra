package main

import "fmt"

func main() {
	const N = 1000
	su := make([]byte, N)
	susum := 0
	j := 0

	for {
		for j = 0; j <= N; j++ {
			fmt.Scanf("%c", &su[j])
			if su[j] == '\n' {
				break
			}
			susum = susum + int(su[j]-'0')
		}
		if su[0] == '0' {
			break
		}
		fmt.Println(susum)
		susum = 0
	}
}

