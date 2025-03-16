n, m = 0, 0
out := make ( []int, 0 )
comp := make ( []int, 0 )
func main ( ) {
    n, m = 0, 0
    out := make ( []int, 0 )
    comp := make ( []int, 0 )
    fmt.Scanf ( "%d %d", &n, &m )
    out = make ( []int, n )
    comp = make ( []int, n )
    for i := 0 ; i < n ; i++ {
        comp [ i ] = i + 2
    }
    for i := 0 ; i < m ; i++ {
        l, r, x := 0, 0, 0
        fmt.Scanf ( "%d %d %d", &l, &r, &x )
        t := l
        for t <= r {
            next_val := comp [ t - 1 ]
            if out [ t - 1 ] == 0 && t!= x {
                out [ t - 1 ] = x
            }
            comp [ t - 1 ] = r + 1 if t >= x else x
            t = next_val
    }
    fmt.Printf ( "%v\n", out )
}
