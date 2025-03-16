package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n := len(scanner.Text())
	scanner.Scan()
	s := scanner.Text()

	var rc, gc, bc int64

	for i := 0; i < n; i++ {
		if s[i] == 'R' {
			rc++
		} else if s[i] == 'G' {
			gc++
		} else {
			bc++
		}
	}

	var result int64 = rc * gc * bc

	for i := 1; i < n; i++ {
		for k := i + 1; k <= n; k++ {
			if (i+k)%2 == 0 {
				is := s[i]
				ks := s[k-1]
				js := s[(i+k)/2-1]

				if is != ks && ks != js && js != is {
					result--
				}
			}
		}
	}

	fmt.Println(result)
}

