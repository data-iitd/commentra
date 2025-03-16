<<<<<<< HEAD

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var a, b int
    fmt.Scanf("%d %d", &a, &b)

    if a == 1 {
        a = 14
    }

    if b == 1 {
        b = 14
    }

    if a < b {
        fmt.Println("Bob")
    } else if a > b {
        fmt.Println("Alice")
    } else {
        fmt.Println("Draw")
    }
=======
package main

import "fmt"

func main() {
	var a, b int
	fmt.Scanf("%d %d", &a, &b)

	if a == 1 {
		a = 14
	}

	if b == 1 {
		b = 14
	}

	if a < b {
		fmt.Println("Bob")
	} else if a > b {
		fmt.Println("Alice")
	} else {
		fmt.Println("Draw")
	}
>>>>>>> 98c87cb78a (data updated)
}

