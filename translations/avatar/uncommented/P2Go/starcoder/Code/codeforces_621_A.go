n := 0
for i := 0; i < len ( lst ); i++ {
    if lst [ i ] & 1 == 1 {
        n += 1
    }
}
sum := 0
ok := false
for i := 0; i < len ( lst ); i++ {
    if lst [ i ] % 2 == 0 {
        sum += lst [ i ]
    } else {
        if ok || n > 1 {
            sum += lst [ i ]
            n -= 1
            ok =!ok
        }
    }
}
fmt.Println ( sum )

