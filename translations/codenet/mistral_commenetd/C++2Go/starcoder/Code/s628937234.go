<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scanln(&s)
	t = s[0:1]
	t += fmt.Sprint(len(s) - 2)
	t += s[len(s)-1:]
	fmt.Println(t)
}

