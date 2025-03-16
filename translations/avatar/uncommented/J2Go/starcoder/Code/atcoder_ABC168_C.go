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
	fmt.Println("Enter the value of A")
	a, _ := reader.ReadString('\n')
	a = strings.TrimSpace(a)
	a = strings.Replace(a, "\n", "", -1)
	a = strings.Replace(a, "\r", "", -1)
	fmt.Println("Enter the value of B")
	b, _ := reader.ReadString('\n')
	b = strings.TrimSpace(b)
	b = strings.Replace(b, "\n", "", -1)
	b = strings.Replace(b, "\r", "", -1)
	fmt.Println("Enter the value of H")
	h, _ := reader.ReadString('\n')
	h = strings.TrimSpace(h)
	h = strings.Replace(h, "\n", "", -1)
	h = strings.Replace(h, "\r", "", -1)
	fmt.Println("Enter the value of M")
	m, _ := reader.ReadString('\n')
	m = strings.TrimSpace(m)
	m = strings.Replace(m, "\n", "", -1)
	m = strings.Replace(m, "\r", "", -1)
	a, _ = strconv.Atoi(a)
	b, _ = strconv.Atoi(b)
	h, _ = strconv.Atoi(h)
	m, _ = strconv.Atoi(m)
	a = float64(a)
	b = float64(b)
	h = float64(h)
	m = float64(m)
	a = a * a
	b = b * b
	h = h * 30
	h = h + (m / 2)
	m = m * 6
	kaku := m - h
	kaku = math.Abs(kaku)
	kaku = math.ToRadians(kaku)
	kaku = math.Cos(kaku)
	kaku = kaku * 2
	kaku = kaku * a
	kaku = kaku * b
	ans := math.Sqrt(kaku)
	fmt.Println(ans)
}

