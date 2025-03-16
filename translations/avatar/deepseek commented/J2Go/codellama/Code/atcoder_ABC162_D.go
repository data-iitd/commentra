
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	var s string

	fmt.Scan(&n)
	fmt.Scan(&s)

	var rc int64 = 0
	var gc int64 = 0
	var bc int64 = 0

	for i := 0; i < len(s); i++ {
		if s[i] == 'R' {
			rc++
		} else if s[i] == 'G' {
			gc++
		} else {
			bc++
		}
	}

	var result int64 = rc * gc * bc

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

// 