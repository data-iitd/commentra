package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	firstline, _ := strconv.Atoi(strings.TrimSpace(line))
	
	total := 0
	memory := []string{}
	
	for x := 0; x < firstline; x++ {
		line, _ := reader.ReadString('\n')
		values := strings.Split(strings.TrimSpace(line), " ")
		A, _ := strconv.Atoi(values[0])
		G, _ := strconv.Atoi(values[1])
		
		if total + A <= 500 {
			total += A
			memory = append(memory, "A")
		} else {
			total -= G
			memory = append(memory, "G")
		}
	}
	
	fmt.Println(strings.Join(memory, ""))
}
