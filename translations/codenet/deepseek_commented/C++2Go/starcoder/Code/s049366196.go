<<<<<<< HEAD

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to check if a number is prime
func isPrime(x int) bool {
	for i := 2; i*i <= x; i++ { // Iterates from 2 to the square root of x
		if x%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var N int
	fmt.Scanf("%d\n", &N) // Reads an integer N from standard input

	ans := 1 // Initializes the answer variable to 1
	for i := 2; i <= N; i++ { // Iterates from 2 to N
		if isPrime(i) { // Checks if the current number i is prime
			NN := N
			cnt := 0 // Initializes a counter to count the power of the prime
			for NN > 0 { // While loop to calculate the power of the prime in N
				cnt += NN / i // Adds the quotient of NN divided by i to cnt
				NN /= i // Divides NN by i
			}
			ans *= cnt + 1 // Multiplies ans by cnt+1
			ans %= 1000000007 // Takes modulo 1000000007 to prevent overflow
		}
	}

	fmt.Println(ans) // Prints the final answer
=======
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to check if a number is prime
func is_prime(x int) bool {
    for i := 2; i*i <= x; i++ { // Iterates from 2 to the square root of x
        if x%i == 0 {
            return false
        }
    }
    return true
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    ans := 1
    for i := 2; i <= N; i++ { // Iterates from 2 to N
        if is_prime(i) { // Checks if the current number i is prime
            NN := N
            cnt := 0
            for NN > 0 { // While loop to calculate the power of the prime in N
                cnt += NN / i
                NN /= i
            }
            ans *= cnt + 1
            ans %= 1e9 + 7
        }
    }

    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
>>>>>>> 98c87cb78a (data updated)
}

