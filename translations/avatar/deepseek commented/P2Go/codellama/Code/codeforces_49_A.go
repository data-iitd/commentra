
package main

import "fmt"

func main() {
	var a string
	fmt.Scan(&a)
	vo := []string{"a", "e", "i", "o", "u", "y", "A", "E", "I", "O", "U", "Y"}

	for i := len(a) - 1; i >= 0; i-- {
		if a[i] == ' ' || a[i] == '?' {
			continue
		} else {
			for _, v := range vo {
				if a[i] == v {
					fmt.Println("YES")
					break
				} else {
					fmt.Println("NO")
				}
			}
			break
		}
	}
}

