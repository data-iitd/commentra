package main
import "fmt"

func main() {
    var N, K int
    var A [200100]int
    var B [200100]int
    var now int
    var cnt int
    fmt.Scan(&N, &K)
    for i := 0; i < N; i++ {
        fmt.Scan(&A[i+1])
    }
    for i := 0; i < 200100; i++ {
        B[i] = -1
    }
    //途中でどっかに合流したら抜ける
    j := 1
    B[1] = 0
    for j = 1; j <= K; j++ {
        //fmt.Println(now, " -> ", A[now])
        now = A[now]
        if B[now] == -1 {
            //fmt.Println("未到達だった")
            B[now] = j
        } else {
            //fmt.Println("到達済みだった")
            //fmt.Println("B[now] = ", B[now])
            cnt = j
            //fmt.Println("cnt = ", cnt)
            break
        }
    }
    if j < K {
        tmp := (K - B[now]) % (cnt - B[now])
        //fmt.Println("あと ", tmp, "回移動すればいい")
        //B[now]からtmp回ワープしたところが終着点
        for j := 0; j < tmp; j++ {
            now = A[now]
        }
    }
    fmt.Println(now)
}
