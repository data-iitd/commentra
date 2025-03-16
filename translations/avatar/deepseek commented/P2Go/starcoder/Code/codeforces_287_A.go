package main

import "fmt"

func main() {
	t := [][]string{}
	for i := 0; i < 4; i++ {
		l := []string{}
		for j := 0; j < 4; j++ {
			l = append(l, string(fmt.Scanf("%c", &l[j])))
		}
		t = append(t, l)
	}
	black := 0
	white := 0
	correct := 0
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if t[i][j] == "#" {
				black++
			} else {
				white++
			}
			if t[i][j+1] == "#" {
				black++
			} else {
				white++
			}
			if t[i+1][j] == "#" {
				black++
			} else {
				white++
			}
			if t[i+1][j+1] == "#" {
				black++
			} else {
				white++
			}
			if black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4 {
				correct = 1
				break
			}
			black = 0
			white = 0
		}
	}
	if correct == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

