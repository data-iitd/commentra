

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
	fmt.Print("Enter the number of elements in the array: ")
	n, _ := strconv.Atoi(reader.ReadLine()[0])
	fmt.Println("Enter the elements of the array:")
	a := make([]int, n)
	for i := 0; i < n; i++ {
		input, _ := reader.ReadLine()
		a[i], _ = strconv.Atoi(strings.TrimSpace(string(input)))
	}
	k, j, i := 0, 0, 0
	found := false
	for k = 0; k < n; k++ {
		t := a[k]
		for i = 0; i < n; i++ {
			for j = 0; j < n-1; j++ {
				if i!= j && t == a[i]+a[j] {
					found = true
					break
				}
			}
			if found {
				break
			}
		}
		if found {
			break
		}
	}
	if found {
		fmt.Printf("Triplet found at indices %d, %d, %d\n", k+1, i+1, j+1)
	} else {
		fmt.Println("No triplet found")
	}
}

