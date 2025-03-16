
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const DAYS = 365
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	nyuyoku_ticket := make([]int, DAYS)
	pool_ticket := make([]int, DAYS)
	nyuyoku_member := make([]int, DAYS)
	pool_member := make([]int, DAYS)
	seiki_ryoukin := make([]int, DAYS)
	waribiki_ryoukin := make([]int, DAYS)
	saiya_sune := make([]int, DAYS)
	for i := 0; i < n; i++ {
		scanner.Scan()
		f, _ := strconv.Split(scanner.Text(), " ")
		nyuyoku_ticket[i], _ = strconv.Atoi(f[0])
		pool_ticket[i], _ = strconv.Atoi(f[1])
		nyuyoku_member[i], _ = strconv.Atoi(f[2])
		pool_member[i], _ = strconv.Atoi(f[3])
		if nyuyoku_member[i] >= 5 && pool_member[i] >= 2 {
			seiki_ryoukin[i] = (int((int((nyuyoku_ticket[i]*nyuyoku_member[i])+(pool_ticket[i]*pool_member[i]))*8)/10))
			saiya_sune[i] = seiki_ryoukin[i]
		} else if nyuyoku_member[i] >= 5 {
			seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i])
			waribiki_ryoukin[i] = (int((int((nyuyoku_ticket[i]*5)+(pool_ticket[i]*pool_member[i]))*8)/10))
			if seiki_ryoukin[i] >= waribiki_ryoukin[i] {
				saiya_sune[i] = waribiki_ryoukin[i]
			} else {
				saiya_sune[i] = seiki_ryoukin[i]
			}
		} else if pool_member[i] >= 2 {
			seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i])
			waribiki_ryoukin[i] = (int((int((nyuyoku_ticket[i]*5)+(pool_ticket[i]*pool_member[i]))*8)/10))
			if seiki_ryoukin[i] >= waribiki_ryoukin[i] {
				saiya_sune[i] = waribiki_ryoukin[i]
			} else {
				saiya_sune[i] = seiki_ryoukin[i]
			}
		} else {
			seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i])
			waribiki_ryoukin[i] = (int((int((nyuyoku_ticket[i]*5)+(pool_ticket[i]*2))*8)/10))
			if seiki_ryoukin[i] >= waribiki_ryoukin[i] {
				saiya_sune[i] = waribiki_ryoukin[i]
			} else {
				saiya_sune[i] = seiki_ryoukin[i]
			}
		}
	}
	for i := 0; i < n; i++ {
		fmt.Println(saiya_sune[i])
	}
}
