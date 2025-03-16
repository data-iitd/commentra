<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	s := ""

/*
<<<<<<< HEAD
2. If `n` is 0, it immediately outputs '0' and terminates. Otherwise, it proceeds to convert the integer `n` to a base -2 representation.
=======
1. If `n` is 0, it immediately outputs '0' and terminates. Otherwise, it proceeds to convert the integer `n` to a base -2 representation.
>>>>>>> 98c87cb78a (data updated)
*/
	if n == 0 {
		fmt.Println("0")
		return
	}

	i := 1
	for n!= 0 {
		if n%2 == 0 {
			s += "0"
		} else {
			s += "1"
		}

		n -= n % 2
		n /= -2
	}

	for i := len(s) - 1; i >= 0; i-- {
		fmt.Print(s[i])
	}
	fmt.Println()

/*
<<<<<<< HEAD
3. Inside the `main` function, a string `s` is initialized as an empty string. The function then enters a loop that continues until `n` becomes 0. Inside the loop, it checks if `n` is even or odd. If `n` is even, it appends '0' to the string `s`; if `n` is odd, it appends '1' to the string `s`. The function then adjusts `n` by subtracting its remainder when divided by 2 (which is 0 for even numbers and 1 for odd numbers) and dividing `n` by -2.
*/

/*
4. After the loop, the string `s` is reversed to correct the order of the digits in the base -2 representation. Finally, the function outputs the resulting string.
=======
2. Inside the `main` function, a string `s` is initialized as an empty string. The function then enters a loop that continues until `n` becomes 0. Inside the loop, it checks if `n` is even or odd. If `n` is even, it appends '0' to the string `s`; if `n` is odd, it appends '1' to the string `s`. The function then adjusts `n` by subtracting its remainder when divided by 2 (which is 0 for even numbers and 1 for odd numbers) and dividing `n` by -2.
*/

/*
3. After the loop, the string `s` is reversed to correct the order of the digits in the base -2 representation. Finally, the function outputs the resulting string.
>>>>>>> 98c87cb78a (data updated)
*/

}

