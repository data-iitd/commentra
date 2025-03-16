n := 0
for i := 1 ; i <= n ; i++ {
    if n % i == 0 {
        n = i
        fmt.Println(i)
    }
}

