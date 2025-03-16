package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scan := bufio.NewScanner(os.Stdin)
	s := strings.Builder{}
	scan.Scan()
	s.WriteString(scan.Text())
	t := scan.Text()
	ura := 0
	opa := 0
	tmap := make(map[rune]int)
	for i := 0; i < len(t); i++ {
		ch := rune(t[i])
		if _, ok := tmap[ch];!ok {
			tmap[ch] = 1
		} else {
			tmap[ch]++
		}
	}
	length := s.Len()
	for i := 0; i < length; i++ {
		ch := rune(s.String()[i])
		num, ok := tmap[ch]
		if!ok {
			continue
		}
		inum := num
		if inum == 1 {
			delete(tmap, ch)
		} else {
			tmap[ch] = inum - 1
		}
		s.SetChar(i, 'Я')
		ura++
	}
	for i := 0; i < length; i++ {
		ch := rune(s.String()[i])
		rch := reverse(ch)
		num, ok := tmap[rch]
		if!ok {
			continue
		}
		inum := num
		if inum == 1 {
			delete(tmap, rch)
		} else {
			tmap[rch] = inum - 1
		}
		opa++
	}
	fmt.Println(ura, opa)
}

func reverse(ch rune) rune {
	if ch >= 'a' && ch <= 'z' {
		return rune(ch - 32)
	} else if ch >= 'A' && ch <= 'Z' {
		return rune(ch + 32)
	}
	return ch
}

