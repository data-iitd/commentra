<<<<<<< HEAD

import (
	"fmt"
	"os"
=======
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
>>>>>>> 98c87cb78a (data updated)
)

func main() {
	var a int
	var z string
	fmt.Scanf("%s", &z)
	a = len(z)
	for i := 0; i < a-1; i++ {
		if z[i] == z[i+1] {
			fmt.Println("Bad")
			os.Exit(0)
		}
	}
	fmt.Println("Good")
}

