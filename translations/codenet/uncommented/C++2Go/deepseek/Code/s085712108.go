package main

import (
	"fmt"
)

const MOD = 7007

type QUEUE struct {
	a, b, c, tot int
}

var F = [][3]int{
	{1, 1, 0},
	{1, 0, 1},
	{0, 1, 1},
	{2, 0, 0},
	{0, 2, 0},
	{0, 0, 2},
}

var Hash [MOD][]int

func HASH(n int) bool {
	for _, v := range Hash[n%MOD] {
		if n == v {
			return false
		}
	}
	Hash[n%MOD] = append(Hash[n%MOD], n)
	return true
}

func main() {
	var Push QUEUE
	Push.tot = 0
	queue := []QUEUE{Push}
	var Fro QUEUE

	fmt.Scan(&Push.a, &Push.b, &Push.c)
	queue = append(queue, Push)

	for len(queue) > 0 {
		Fro = queue[0]
		queue = queue[1:]

		if Fro.a == Fro.b && Fro.b == Fro.c {
			fmt.Println(Fro.tot)
			return
		}

		for _, v := range F {
			Push = Fro
			Push.tot++
			Push.a += v[0]
			Push.b += v[1]
			Push.c += v[2]
			n := Push.a*10000 + Push.b*100 + Push.c
			if !HASH(n) {
				continue
			}
			queue = append(queue, Push)
		}
	}
}

