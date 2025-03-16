
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	const DAYS = 365 // Maximum number of days
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	nyuyoku_ticket := make([]int, DAYS)
	pool_ticket := make([]int, DAYS)
	nyuyoku_member := make([]int, DAYS)
	pool_member := make([]int, DAYS)
	seiki_ryoukin := make([]int, DAYS)
	waribiki_ryoukin := make([]int, DAYS)
	saiyasune := make([]int, DAYS)
	for i := 0; i < n; i++ {
		nyuyoku_ticket[i], pool_ticket[i], nyuyoku_member[i], pool_member[i] = read4Int(reader)
		if nyuyoku_member[i] >= 5 && pool_member[i] >= 2 {
			seiki_ryoukin[i] = (nyuyoku_ticket[i]*nyuyoku_member[i] + pool_ticket[i]*pool_member[i]) * 8 / 10
			saiyasune[i] = seiki_ryoukin[i]
		} else if nyuyoku_member[i] >= 5 {
			seiki_ryoukin[i] = nyuyoku_ticket[i]*nyuyoku_member[i] + pool_ticket[i]*pool_member[i]
			waribiki_ryoukin[i] = (nyuyoku_ticket[i]*nyuyoku_member[i] + pool_ticket[i]*2) * 8 / 10
			if seiki_ryoukin[i] >= waribiki_ryoukin[i] {
				saiyasune[i] = waribiki_ryoukin[i]
			} else {
				saiyasune[i] = seiki_ryoukin[i]
			}
		} else if pool_member[i] >= 2 {
			seiki_ryoukin[i] = nyuyoku_ticket[i]*nyuyoku_member[i] + pool_ticket[i]*pool_member[i]
			waribiki_ryoukin[i] = (nyuyoku_ticket[i]*5 + pool_ticket[i]*pool_member[i]) * 8 / 10
			if seiki_ryoukin[i] >= waribiki_ryoukin[i] {
				saiyasune[i] = waribiki_ryoukin[i]
			} else {
				saiyasune[i] = seiki_ryoukin[i]
			}
		} else {
			seiki_ryoukin[i] = nyuyoku_ticket[i]*nyuyoku_member[i] + pool_ticket[i]*pool_member[i]
			waribiki_ryoukin[i] = (nyuyoku_ticket[i]*5 + pool_ticket[i]*2) * 8 / 10
			if seiki_ryoukin[i] >= waribiki_ryoukin[i] {
				saiyasune[i] = waribiki_ryoukin[i]
			} else {
				saiyasune[i] = seiki_ryoukin[i]
			}
		}
	}
	for i := 0; i < n; i++ {
		fmt.Println(saiyasune[i])
	}
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

func read4Int(reader *bufio.Reader) (int, int, int, int) {
	str, _, _ := reader.ReadLine()
	split := strings.Split(string(str), " ")
	a, _ := strconv.Atoi(split[0])
	b, _ := strconv.Atoi(split[1])
	c, _ := strconv.Atoi(split[2])
	d, _ := strconv.Atoi(split[3])
	return a, b, c, d
}

