
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		if line == "." {
			break
		}
		count := 0
		for p := 0; p < 3; p++ {
			for q := 0; q < 3; q++ {
				for r := 0; r < 3; r++ {
					input := strings.Replace(line, "P", strconv.Itoa(p), -1)
					input = strings.Replace(input, "Q", strconv.Itoa(q), -1)
					input = strings.Replace(input, "R", strconv.Itoa(r), -1)
					result, err := eval(input)
					if err!= nil {
						panic(err)
					}
					if result == 2 {
						count++
					}
				}
			}
		}
		fmt.Println(count)
	}
}

func eval(input string) (int, error) {
	tokens := []string{}
	for _, c := range input {
		if c =='' {
			continue
		}
		if c == '(' || c == ')' || c == '*' || c == '+' || c == '-' {
			tokens = append(tokens, string(c))
			continue
		}
		if c < '0' || c > '2' {
			return 0, fmt.Errorf("invalid character: %c", c)
		}
		tokens = append(tokens, string(c))
	}
	stack := []int{}
	for _, token := range tokens {
		if token == "(" {
			continue
		}
		if token == ")" {
			right := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			left := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			result := 0
			if token == "+" {
				result = left + right
			} else if token == "*" {
				result = left * right
			} else if token == "-" {
				result = left - right
			}
			stack = append(stack, result)
			continue
		}
		num, err := strconv.Atoi(token)
		if err!= nil {
			return 0, err
		}
		stack = append(stack, num)
	}
	if len(stack)!= 1 {
		return 0, fmt.Errorf("invalid expression")
	}
	return stack[0], nil
}

