package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func reverse(ch rune) rune {
	if ch >= 'a' && ch <= 'z' {
		return ch - 32
	} else if ch >= 'A' && ch <= 'Z' {
		return ch + 32
	}
	return ch
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s := strings.Builder{}
	s.WriteString(scanner.Text())
	scanner.Scan()
	t := scanner.Text()
	ura := 0
	opa := 0
	tmap := make(map[rune]int)
	for _, ch := range t {
		if _, ok := tmap[ch]; !ok {
			tmap[ch] = 1
		} else {
			tmap[ch]++
		}
	}
	length := len(s.String())
	for i := 0; i < length; i++ {
		ch := rune(s.String()[i])
		num, ok := tmap[ch]
		if !ok {
			continue
		}
		inum := num
		if inum == 1 {
			delete(tmap, ch)
		} else {
			tmap[ch] = inum - 1
		}
		s.WriteRune('Я')
		ura++
	}
	for i := 0; i < length; i++ {
		ch := rune(s.String()[i])
		rch := reverse(ch)
		num, ok := tmap[rch]
		if !ok {
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

