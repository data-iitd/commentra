package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	var prime_list [1001]int
	var prime_or_not [1001]int
	var prime_num [1001]int
	var prime_counter int
	var kekka [2]int
	sosuubunnpu()
	for current_num := 2; current_num <= N; current_num++ {
		kekka[1] = current_num
		for i := 0; i < prime_counter; i++ {
			innsuubunnkai(kekka[1], prime_list[i])
			prime_num[i] += kekka[0]
		}
	}
	var innsuu [11]int
	for current_num := 2; current_num <= N; current_num++ {
		for i := 0; i < 11; i++ {
			innsuu[i] += A[current_num][i]
		}
	}
	var result uint64 = 1
	for i := 0; i < prime_counter; i++ {
		result = (result * (prime_num[i] + 1)) % 1000000007
	}
	fmt.Println(result)
}

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

