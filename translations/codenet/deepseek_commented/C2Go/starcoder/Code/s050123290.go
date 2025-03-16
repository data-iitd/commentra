<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
	// 1. Define the array and variables
	var su [1000]byte
	var susum int
	var j int

	for {
		// 2. Read input and calculate sum
		for j = 0; j <= 1000; j++ {
<<<<<<< HEAD
			fmt.Scanf("%c", &su[j])
			if su[j] == '\n' {
				break
			}
			susum += int(su[j] - '0')
=======
			_, err := fmt.Scanf("%c", &su[j])
			if err!= nil {
				break
			}
>>>>>>> 98c87cb78a (data updated)
		}
		if su[0] == '0' {
			break
		}
		// 3. Print the sum
		fmt.Printf("%d\n", susum)
		susum = 0
<<<<<<< HEAD
	}
	// 4. Check for termination condition
=======
		// 4. Check for termination condition
	}
>>>>>>> 98c87cb78a (data updated)
}

