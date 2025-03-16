
// ACM-ICPCアジア地区予選2014 B. Miscalculation

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func mul(str string, idx *int) int {
	res, _ := strconv.Atoi(string(str[*idx]))
	for *idx+1 < len(str) && str[*idx+1] == '*' {
		*idx += 2
		res *= int(str[*idx]-'0')
	}
	return res
}

func add(str string, idx *int) int {
	res := mul(str, idx)
	for *idx+1 < len(str) && str[*idx+1] == '+' {
		*idx += 2
		res += mul(str, idx)
	}
	return res
}

func bob(str string, idx *int) int {
	res, _ := strconv.Atoi(string(str[*idx]))
	for *idx+1 < len(str) {
		if str[*idx+1] == '+' {
			*idx += 2
			res += int(str[*idx]-'0')
		} else {
			*idx += 2
			res *= int(str[*idx]-'0')
		}
	}
	return res
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialIdx = 0
	for scanner.Scan() {
		text := scanner.Text()
		fields := strings.Split(text, " ")
		if len(fields)!= 2 {
			continue
		}
		s, d := fields[0], fields[1]
		idx := initialIdx
		a := add(s, &idx)
		idx = initialIdx
		b := bob(s, &idx)
		if a == int(d[0]-'0') {
			fmt.Printf("%c\n", "UL"[b == int(d[0]-'0')])
		} else {
			fmt.Printf("%c\n", "IL"[b == int(d[0]-'0')])
		}
	}
}

