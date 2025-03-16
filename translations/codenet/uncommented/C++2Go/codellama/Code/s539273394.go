package main

import (
	"fmt"
)

func sosuubunnpu() {
	for i := 1; i <= 1000; i++ {
		prime_or_not[i] = 0
	}
	for i := 2; i <= 1000; i++ {
		for j := 2; j <= 1000/i; j++ {
			if prime_or_not[i] == 0 {
				prime_or_not[i*j] = 1
			}
		}
	}
	for i := 2; i <= 1000; i++ {
		if prime_or_not[i] == 0 {
			prime_list[prime_counter] = i
			prime_counter++
		}
	}
}

func innsuubunnkai(n, current_num int) {
	time := 0
	for {
		if n%current_num == 0 {
			n = n / current_num
			time++
		} else {
			break
		}
	}
	kekka[0] = time
	kekka[1] = n
}

func main() {
	sosuubunnpu()
	var N int
	fmt.Scan(&N)
	innsuu := make([]int, 11)
	A := make([][]int, N+1)
	for i := 0; i <= 1000; i++ {
		prime_num[i] = 0
	}
	result := 1
	for current_num := 2; current_num <= N; current_num++ {
		kekka[1] = current_num
		for i := 0; i < prime_counter; i++ {
			innsuubunnkai(kekka[1], prime_list[i])
			prime_num[i] += kekka[0]
		}
	}
	for current_num := 2; current_num <= N; current_num++ {
		for i := 0; i < 11; i++ {
			innsuu[i] += A[current_num][i]
		}
	}
	for i := 0; i < prime_counter; i++ {
		result = (result * (prime_num[i] + 1)) % 1000000007
	}
	fmt.Println(result)
}

