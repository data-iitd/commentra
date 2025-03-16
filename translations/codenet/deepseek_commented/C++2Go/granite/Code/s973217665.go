
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
	fmt.Println("Enter the number of test cases:")
	n, _ := strconv.Atoi(reader.ReadLine())
	for i := 0; i < n; i++ {
		fmt.Println("Enter the values of p and q for test case", i+1, ":")
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		parts := strings.Split(input, " ")
		p, _ := strconv.Atoi(parts[0])
		q, _ := strconv.Atoi(parts[1])
		l := int(math.Sqrt(float64(p*p + q*q)))
		isPrime := true
		for i := 0; i < l; i++ {
			for j := 0; j < l; j++ {
				x := i*i + j*j
				if x <= 1 || x >= p*p+q*q {
					continue
				}
				if (i*p+j*q)%x == 0 && (i*q-j*p)%x == 0 {
					isPrime = false
					break
				}
			}
			if!isPrime {
				break
			}
		}
		if isPrime {
			fmt.Println("P")
		} else {
			fmt.Println("C")
		}
	}
}

