
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
	fmt.Println("Enter the number of characters in the string")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the string")
	s := strings.TrimSpace(reader.ReadString('\n'))
	var rc, gc, bc int
	for _, v := range s {
		if v == 'R' {
			rc++
		} else if v == 'G' {
			gc++
		} else {
			bc++
		}
	}
	result := rc * gc * bc
	for i := 1; i <= n; i++ {
		for k := i + 1; k <= n; k++ {
			if (i+k)%2 == 0 {
				is := s[i-1]
				ks := s[k-1]
				js := s[(i+k)/2-1]
				if is!= ks && ks!= js && js!= is {
					result--
				}
			}
		}
	}
	fmt.Println(result)
}

