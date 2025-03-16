n, k := 0, 0
s := ""
count := make ( []int, 26 )
res := 0
fmt.Scan ( &n, &k )
fmt.Scan ( &s )
for i := 0 ; i < len ( s ) ; i++ {
    count [ int ( s [ i ] - 'A' ) ]++
}
sort.Slice ( count, func ( i, j int ) bool {
    return count [ i ] > count [ j ]
} )
for i := 0 ; i < 26 ; i++ {
    if count [ i ] >= k {
        res += k * k
        fmt.Println ( res )
        break
    }
    k -= count [ i ]
    res += count [ i ] * count [ i ]
}
fmt.Println ( res )

