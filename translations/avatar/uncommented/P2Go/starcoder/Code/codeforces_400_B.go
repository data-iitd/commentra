n, m := 0, 0
c := make ( map[int]bool )
for _, s := range ( input ( ) ) {
    n += 1
    c[s.find ( "S" ) - s.find ( "G" )] = true
}
fmt.Println ( - 1 )
if any ( a < 0 for a in c ) {
    fmt.Println ( - 1 )
} else {
    fmt.Println ( len ( c ) )
}

