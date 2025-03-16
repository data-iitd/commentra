package main

import (
	"fmt"
)

func main() {
	var n int
	var s string
	fmt.Scan(&n)
	fmt.Scan(&s)

	var rc, gc, bc int64
	for i := 0; i < len(s); i++ {
		switch s[i] {
		case 'R':
			rc++
		case 'G':
			gc++
		case 'B':
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
				if is != ks && ks != js && js != is {
					result--
				}
			}
		}
	}

	fmt.Println(result)
}

// <END-OF-CODE>
