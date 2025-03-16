n, m := 0, 0
l := make ( [][]byte, n )
for i := 0 ; i < n ; i++ {
    s := make ( []byte, m )
    for j := 0 ; j < m ; j++ {
        if ( i + j ) & 1 {
            s [ j ] = 'W'
        } else {
            s [ j ] = 'B'
        }
    }
    l [ i ] = s
}
for _, c := range l {
    fmt.Println ( string ( c ) )
}

