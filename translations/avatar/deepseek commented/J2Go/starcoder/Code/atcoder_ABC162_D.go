
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
	fmt.Println("Enter the number of characters in the string s:")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the string s:")
	s := strings.TrimSpace(reader.ReadString('\n'))
	fmt.Println("Enter the number of characters in the string t:")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the string t:")
	t := strings.TrimSpace(reader.ReadString('\n'))

	var rc, gc, bc int
	for _, c := range s {
		if c == 'R' {
			rc++
		} else if c == 'G' {
			gc++
		} else {
			bc++
		}
	}

	result := rc * gc * bc
	for i := 0; i < n; i++ {
		for k := i + 1; k < n; k++ {
			if (i+k)%2 == 0 {
				is := s[i]
				ks := s[k]
				js := t[(i+k)/2]
				if is!= ks && ks!= js && js!= is {
					result--
				}
			}
		}
	}
	fmt.Println(result)
}

