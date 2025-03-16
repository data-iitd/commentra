package main

import "fmt"

var c [26]int

func main() {
	str := make([]byte, 1200)
	for {
		n, err := fmt.Scanf("%s", str)
		if err != nil || n == 0 {
			break
		}
		for _, b := range str {
			if 'a' <= b && b <= 'z' {
				c[b-'a']++
			} else if 'A' <= b && b <= 'Z' {
				c[b-'A']++
			}
		}
	}
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+i, c[i])
	}
}

