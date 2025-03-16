package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s := scanner.Text()
	solver := BUnhappyHackingABCEdit{}
	solver.Solve(s)
}

type BUnhappyHackingABCEdit struct{}

func (b *BUnhappyHackingABCEdit) Solve(s string) {
	var d strings.Builder
	for _, c := range s {
		switch c {
		case '0':
			d.WriteRune('0')
		case '1':
			d.WriteRune('1')
		case 'B':
			if d.Len() > 0 {
				d.Truncate(d.Len() - 1)
			}
		}
	}
	fmt.Println(d.String())
}

// <END-OF-CODE>
