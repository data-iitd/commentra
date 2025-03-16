package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	input, _ := reader.ReadString('\n')
	input = input[:len(input)-1] // Remove newline character
	max := -1
	msgLength := make([]int, len(input)/2)
	count := 0
	idx := 0
	for i := 0; i < len(input); i++ {
		c := input[i]
		if c == '.' || c == '?' || c == '!' {
			msgLength[idx] = count + 1
			idx++
			if count+1 > max {
				max = count + 1
			}
			count = 0
			i++ // Skip the next character after the punctuation
		} else {
			count++
		}
	}
	if max > n {
		fmt.Println("Impossible")
	} else {
		ans := 0
		for i := 0; i < idx; i++ {
			l := msgLength[i]
			for i < idx-1 && l+msgLength[i+1]+1 <= n {
				l += msgLength[i+1] + 1
				i++
			}
			ans++
		}
		fmt.Println(ans)
	}
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1] // Remove newline character
}

