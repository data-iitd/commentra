
package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    A, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    B, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    H, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    M, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    var ans float64

    // Calculating mkaku (M multiplied by 6) and hkaku (H multiplied by 30 and added half of M)
    mkaku := float64(M) * 6
    hkaku := float64(H) * 30 + float64(M)/2

    // Calculating kaku (difference between mkaku and hkaku)
    kaku := mkaku - hkaku

    // Calculating the absolute value of kaku in radians
    dkaku := math.Abs(math.ToRadians(kaku))

    // Calculating the squared values of A and B
    AA2 := float64(A) * float64(A)
    BB2 := float64(B) * float64(B)

    // Calculating CC (sum of squares of A and B) and DD (cosine of kaku multiplied by A and B)
    CC := AA2 + BB2
    DD := math.Cos(dkaku) * float64(A) * float64(B)

    // Calculating the answer (square root of the difference between CC and DD)
    ans = math.Sqrt(CC - DD)

    // Printing the answer
    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    panic(err)
}

