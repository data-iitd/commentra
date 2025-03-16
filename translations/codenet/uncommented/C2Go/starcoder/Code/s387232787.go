package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	c := make([]int, 26)
	for {
		s := strings.Split(strings.TrimSpace(readLine(os.Stdin)), " ")
		if len(s) == 0 {
			break
		}
		for _, v := range s {
			for _, r := range v {
				if 'a' <= r && r <= 'z' {
					c[r-'a']++
				} else if 'A' <= r && r <= 'Z' {
					c[r-'A']++
				}
			}
		}
	}
	for i := 0; i < 26; i++ {
		fmt.Printf("%c : %d\n", 'a'+i, c[i])
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

