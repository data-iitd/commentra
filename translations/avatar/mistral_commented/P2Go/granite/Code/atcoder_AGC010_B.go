
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Take input from the user
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	a := make([]int, n)
	for i, v := range strings.Split(reader.ReadLine()[2:], " ") {
		a[i], _ = strconv.Atoi(v)
	}

	// Check if the sum of the elements in the list is divisible by the formula
	if sum := 0; for _, v := range a {
		sum += v
	}; sum%(n*(n+1)/2)!= 0 {
		fmt.Println("NO")
		return
	}

	// Calculate the average of the elements in the list
	k := float64(sum) / float64(n*(n+1)/2)

	// Add the first element to the end of the list for simplification
	a = append(a, a[0])

	// Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
	if sum := 0; for i := 1; i <= n; i++ {
		if (k-float64(a[i])+(float64(a[i-1])))%float64(n)!= 0 {
			sum++
		}
	}; sum!= 0 {
		fmt.Println("NO")
		return
	}
	if sum := 0; for i := 1; i <= n; i++ {
		if (k-float64(a[i])+(float64(a[i-1])))/float64(n) < 0 {
			sum++
		}
	}; sum!= n {
		fmt.Println("NO")
		return
	}

	// If all checks pass, print YES
	fmt.Println("YES")
}
