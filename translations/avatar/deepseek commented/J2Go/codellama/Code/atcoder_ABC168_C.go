
package main

import (
    "fmt"
    "math"
    "math/big"
)

func main() {
    var A, B, H, M int
    var AA, BB, HH, MM big.Float
    var mkaku, hkaku, kaku big.Float
    var dkaku float64
    var AA2, BB2, CC, DD big.Float
    var ans2, ans big.Float
    var dans2 float64

    fmt.Scan(&A, &B, &H, &M)

    AA.SetInt64(int64(A))
    BB.SetInt64(int64(B))
    HH.SetInt64(int64(H))
    MM.SetInt64(int64(M))

    mkaku.Mul(&MM, big.NewFloat(6))
    hkaku.Mul(&HH, big.NewFloat(30))
    hkaku.Add(&hkaku, big.NewFloat((float64(M)/2)))

    kaku.Sub(&mkaku, &hkaku)

    dkaku = math.Abs(math.ToRadians(kaku.Float64()))

    AA2.Mul(&AA, &AA)
    BB2.Mul(&BB, &BB)
    CC.Add(&AA2, &BB2)
    DD.Mul(&AA, &BB)
    DD.Mul(&DD, big.NewFloat(2))
    DD.Mul(&DD, &BB)

    ans2.Sub(&CC, &DD)

    dans2 = ans2.Float64()

    ans.Sqrt(&ans2)

    fmt.Println(ans.Float64())
}

