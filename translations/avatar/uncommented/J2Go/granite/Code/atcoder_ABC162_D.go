
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
	fmt.Print("Enter the value of n: ")
	n, _ := strconv.Atoi(reader.ReadLine()[0 : len(reader.ReadLine())-1])
	fmt.Print("Enter the string s: ")
	s := reader.ReadLine()[0 : len(reader.ReadLine())-1]
	rc := int64(0)
	gc := int64(0)
	bc := int64(0)
	for i := 0; i < len(s); i++ {
		if string(s[i]) == "R" {
			rc++
		} else if string(s[i]) == "G" {
			gc++
		} else {
			bc++
		}
	}
	result := rc * gc * bc
	for i := 1; i <= n; i++ {
		for k := i + 1; k <= n; k++ {
			if (i+k)%2 == 0 {
				is := string(s[i-1])
				ks := string(s[k-1])
				js := string(s[((i+k)/2)-1])
				if is!= ks && ks!= js && js!= is {
					result--
				}
			}
		}
	}
	fmt.Println(result)
}

