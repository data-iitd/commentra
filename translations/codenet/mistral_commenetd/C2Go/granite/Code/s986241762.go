

package main

import "fmt"

func main() {
	var n int
	fmt.Print("Enter the number of elements in the array: ")
	fmt.Scan(&n)

	a := make([]int, n)

	fmt.Println("Enter", n, "integers:")
	for i := 0; i < n; i++ {
		fmt.Printf("Enter element number %d: ", i+1)
		fmt.Scan(&a[i])
	}

	sum := int64(0)
	for i := 1; i < n; i++ {
		if a[i-1] > a[i] {
			diff := a[i-1] - a[i]
			sum += int64(diff)
			a[i] = a[i-1]
		}
	}

	fmt.Printf("The sum of the differences is: %d\n", sum)
}

