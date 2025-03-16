

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	n, _ := strconv.Atoi(reader.ReadLine()[2:])  // Read the number of elements
	l := make([]int, n)  // Create a slice of length n to store the integers

	for i := 0; i < n; i++ {
		s := reader.ReadLine()  // Read a line of input
		l[i], _ = strconv.Atoi(s[:len(s)-1])  // Convert the input to an integer and store it in the slice
	}

	sort.Ints(l)  // Sort the slice of integers

	for i := 0; i < n-2; i++ {  // Iterate over the slice of integers
		if l[i]+1 == l[i+1] && l[i+1]+1 == l[i+2] {  // Check if the current integer and the next two integers are consecutive
			fmt.Println("YES")  // If found, print 'YES' and break the loop
			return
		}
	}

	fmt.Println("NO")  // If no such integer is found, print 'NO'
}

