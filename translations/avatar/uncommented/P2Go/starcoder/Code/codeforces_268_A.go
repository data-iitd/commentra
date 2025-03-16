n := 0
q := make ( [] []string )
count := 0
for i := 0; i < n; i++ {
    a := strings.Split ( input ( ), " " )
    q = append ( q, a )
}
for j := 0; j < len ( q ); j++ {
    for k := 0; k < len ( q ); k++ {
        if k == j {
            continue
        } else if q [ j ] [ 0 ] == q [ k ] [ len ( q [ k ] ) - 1 ] {
            count++
        } else {
            continue
        }
    }
}
fmt.Println ( count )

