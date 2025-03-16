
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	kekka           [2]int
	prime_or_not    [1001]int
	prime_list      [1001]int
	prime_num       [1001]int
	prime_counter   int
	N                int
	innsuu          [11]int
	A                [100001][11]int
	result           uint64 = 1
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
	prime_counter = 0
	for i := 2; i <= 1000; i++ {
		if prime_or_not[i] == 0 {
			prime_list[prime_counter] = i
			prime_counter++
		}
	}
}

func innsuubunnkai(N int, n int) {
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
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

