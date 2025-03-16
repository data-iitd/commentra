
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
	fmt.Print("Enter time 1 (hh:mm): ")
	text, _ := reader.ReadString('\n')
	h1, m1 := timeToMinutes(strings.TrimSpace(text))
	fmt.Print("Enter time 2 (hh:mm): ")
	text, _ = reader.ReadString('\n')
	h2, m2 := timeToMinutes(strings.TrimSpace(text))
	m2 = m1 - m2
	m2 %= 1440
	fmt.Printf("%02d:%02d\n", m2/60, m2%60)
}

func timeToMinutes(time string) (int, int) {
	parts := strings.Split(time, ":")
	h, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])
	return h*60 + m, m
}

