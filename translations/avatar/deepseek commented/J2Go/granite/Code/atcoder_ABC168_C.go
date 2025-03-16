

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
    scanner := bufio.NewScanner(os.Stdin)
    const initialCapacity = 4096
    const growthFactor = 1.6180339887498949
    const trimContents = true
    scanner.Buffer(make([]byte, initialCapacity), int(growthFactor))
    scanner.Split(bufio.ScanWords)
    var A int
    var B int
    fmt.Fscan(scanner, &A)
    fmt.Fscan(scanner, &B)
    fmt.Fscan(scanner, &H)
    fmt.Fscan(scanner, &M)
    var AA float64 = float64(A)
    var BB float64 = float64(B)
    var HH float64 = float64(H)
    var MM float64 = float64(M)
    var mkaku float64 = MM * 6
    var hkaku float64 = HH * 30
    hkaku += float64(M) / 2
    var kaku float64 = mkaku - hkaku
    var dkaku float64 = math.Abs(math.Cos(kaku))
    var AA2 float64 = AA * AA
    var BB2 float64 = BB * BB
    var CC float64 = AA2 + BB2
    var DD float64 = 2 * dkaku * AA * BB
    var ans2 float64 = CC - DD
    var dans2 float64 = ans2
    var ans float64 = math.Sqrt(dans2)
    fmt.Println(ans)
}

