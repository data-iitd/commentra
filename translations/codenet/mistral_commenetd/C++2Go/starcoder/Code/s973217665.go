
<<<<<<< HEAD

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)

	for ; n > 0; n-- {
		var p, q int
		fmt.Scanf("%d %d", &p, &q)

		l := int(math.Sqrt(float64(p*p + q*q)))

		isprime := true

		for i := 0; i < l; i++ {
			for j := 0; j < l; j++ {
				x := i*i + j*j
				if x <= 1 {
					continue
				}
				if x > p*p + q*q {
					continue
				}

				if (i*p + j*q) % x == 0 && (i*q - j*p) % x == 0 {
					isprime = false
					break
				}
			}
			if!isprime {
				break
			}
		}

		if isprime {
			fmt.Println("P")
		} else {
			fmt.Println("C")
		}
	}
=======
package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scanf("%d", &n)

    for ; n > 0; n-- {
        var p, q int
        fmt.Scanf("%d %d", &p, &q)

        l := int(math.Sqrt(float64(p*p + q*q)))

        isprime := true

        for i := 0; i < l; i++ {
            for j := 0; j < l; j++ {
                x := i*i + j*j

                if x <= 1 {
                    continue
                }

                if x > p*p + q*q {
                    continue
                }

                if (i*p + j*q) % x == 0 && (i*q - j*p) % x == 0 {
                    isprime = false
                    break
                }
            }
        }

        if isprime {
            fmt.Println("P")
        } else {
            fmt.Println("C")
        }
    }
>>>>>>> 98c87cb78a (data updated)
}

