package main

import (
	"fmt"
)

const MOD = 1000000007

var kekka [2]int
var primeOrNot [1001]int
var primeList [1001]int
var primeNum [1001]int
var primeCounter int

func sosuubunnpu() {
	for i := 1; i <= 1000; i++ {
		primeOrNot[i] = 0
	}
	for i := 2; i <= 1000; i++ {
		for j := 2; j <= 1000/i; j++ {
			if primeOrNot[i] == 0 {
				primeOrNot[i*j] = 1
			}
		}
	}
	for i := 2; i <= 1000; i++ {
		if primeOrNot[i] == 0 {
			primeList[primeCounter] = i
			primeCounter++
		}
	}
}

func innsuubunnkai(N, n int) {
	time := 0
	for {
		if N%n == 0 {
			N = N / n
			time++
		} else {
			break
		}
	}
	kekka[0] = time
	kekka[1] = N
}

func main() {
	sosuubunnpu()
	var N int
	fmt.Scan(&N)
	inssuu := [11]int{}
	A := [N+1][11]int{}
	for i := 0; i <= 1000; i++ {
		primeNum[i] = 0
	}
	var result int64 = 1
	for currentNum := 2; currentNum <= N; currentNum++ {
		kekka[1] = currentNum
		for i := 0; i < primeCounter; i++ {
			innsuubunnkai(kekka[1], primeList[i])
			primeNum[i] += kekka[0]
		}
	}
	for currentNum := 2; currentNum <= N; currentNum++ {
		for i := 0; i < 11; i++ {
			inssuu[i] += A[currentNum][i]
		}
	}
	for i := 0; i < primeCounter; i++ {
		result = (result * int64(primeNum[i]+1)) % MOD
	}
	fmt.Println(result)
}

