
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Step 1: Reading Input
    reader := bufio.NewReader(os.Stdin)
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    values := strings.Split(input, " ")
    A, _ := strconv.Atoi(values[0])
    B, _ := strconv.Atoi(values[1])
    C, _ := strconv.Atoi(values[2])
    D, _ := strconv.Atoi(values[3])
    E, _ := strconv.Atoi(values[4])
    F, _ := strconv.Atoi(values[5])

    // Step 2: Initializing Variables
    m1 := 0
    m2 := 0
    maxD := 0.0

    // Step 3: Nested Loops to Iterate Over Possible Combinations
    for i := 0; 100*A*i <= F; i++ {
        mA := 100 * A * i
        for j := 0; mA+100*B*j <= F; j++ {
            mB := 100 * B * j
            for k := 0; mA+mB+C*k <= F; k++ {
                mC := C * k
                for l := 0; mA+mB+mC+D*l <= F; l++ {
                    mD := D * l
                    // Step 4: Calculating Density and Updating Results
                    if (mA+mB)*E/100 < mD+mC {
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

    // Step 5: Handling Edge Cases
    if m1 == 0 {
        m1 = 100 * A
    }

    // Step 6: Output the Results
    fmt.Println(m1, m2)
}

