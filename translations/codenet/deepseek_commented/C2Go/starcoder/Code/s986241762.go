<<<<<<< HEAD
import "fmt"
func main() {
	var n int // Step 1: Read the value of n, which represents the number of elements in the array.
  	var sum int // Initialize sum to store the total difference.
  	fmt.Scanf("%d",&n) // Read the number of elements.
  	a := make([]int,n) // Step 2: Dynamically allocate memory for an array 'a' of size n.
  	for i:=0;i<n;i++{ // Step 3: Read n elements into the array 'a'.
    	fmt.Scanf("%d",&a[i])
    }
  	for i:=1;i<n;i++{ // Step 4: Iterate through the array and calculate the sum of the differences between consecutive elements, updating the array 'a' to ensure each element is at least as large as the previous one.
    	if a[i-1]>a[i]{
          sum += a[i-1]-a[i] // Add the difference to the sum.
     	  a[i] = a[i-1] // Update the current element to be at least as large as the previous one.
        }
    }
  	fmt.Printf("%d\n",sum) // Step 5: Print the calculated sum.
}
=======
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var sum int64
	fmt.Scanf("%d", &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	for i := 1; i < n; i++ {
		if a[i-1] > a[i] {
			sum += int64(a[i-1] - a[i])
			a[i] = a[i-1]
		}
	}
	fmt.Printf("%d\n", sum)
}

>>>>>>> 98c87cb78a (data updated)
