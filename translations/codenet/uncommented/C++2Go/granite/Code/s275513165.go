
package main

import "fmt"

func main() {
	var str string
	fmt.Scanln(&str)
	if str[2] == str[3] && str[4] == str[5] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
