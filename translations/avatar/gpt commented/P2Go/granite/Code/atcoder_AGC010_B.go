
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements and the list of integers from input
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	a := readLine(reader)
	a = strings.Split(a, " ")
	a = a[:len(a)-1]
	for i := 0; i < len(a); i++ {
		a[i], _ = strconv.Atoi(a[i])
	}

	// Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
	if sum(a)%(n*(n+1)/2)!= 0 {
		// If not divisible, print "NO" and exit
		fmt.Println("NO")
		return
	}
	// Calculate the average value 'k' that each element should contribute
	k := sum(a) / (n * (n + 1) / 2)

	// Append the first element of 'a' to the end of the list to facilitate circular calculations
	a = append(a, a[0])

	// Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
	if sum([]int{((k-a[1]+a[0])%n + n)%n})!= 0 || sum([]int{((k-a[1]+a[0]) / n + n) / 2})!= n {
		// If either condition fails, print "NO"
		fmt.Println("NO")
		return
	}
	// If both conditions are satisfied, print "YES"
	fmt.Println("YES")
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
}

func sum(a []int) int {
	sum := 0
	for _, v := range a {
		sum += v
	}
	return sum
}

