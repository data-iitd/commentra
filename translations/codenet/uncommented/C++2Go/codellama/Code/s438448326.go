package main

import (
	"fmt"
)

func main() {
	var A, B, C, D, E, F int
	fmt.Scan(&A, &B, &C, &D, &E, &F)

	m1 := 0
	m2 := 0
	maxD := 0.0
	for i := 0; 100*A*i <= F; i++ {
		mA := 100 * A * i
		for j := 0; mA+100*B*j <= F; j++ {
			mB := 100 * B * j
			for k := 0; mA+mB+C*k <= F; k++ {
				mC := C * k
				for l := 0; mA+mB+mC+D*l <= F; l++ {
					mD := D * l
					if (mA + mB)*E/100 < mD+mC {
						break
					}
					d := float64(mD+mC) / float64(mA+mB+mC+mD)
					if d > maxD {
						m1 = mA + mB + mC + mD
						m2 = mC + mD
						maxD = d
					}
				}

			}
		}

	}
	if m1 == 0 {
		m1 = 100 * A
	}
	fmt.Println(m1, m2)
}

