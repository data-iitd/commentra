n := 0
input_array := [ ]
for i := 0 ; i < n ; i++ {
    S, R, H, C := 0, 0, 0, 0
    fmt.Scanf ( "%d %d %d %d", &S, &R, &H, &C )
    input_array = append ( input_array, [ S, R, H, C ] )
}
outdated := [ ]
for i := 0 ; i < n ; i++ {
    for j := 0 ; j < n ; j++ {
        if ( input_array [ i ] [ 0 ] < input_array [ j ] [ 0 ] && input_array [ i ] [ 1 ] < input_array [ j ] [ 1 ] && input_array [ i ] [ 2 ] < input_array [ j ] [ 2 ] ) {
            outdated = append ( outdated, input_array [ i ] )
        }
    }
}
outdated = append ( outdated, input_array [ i ] )
minimum_cost := 100000
input_number := 0
for i := 0 ; i < n ; i++ {
    current_item := input_array [ i ]
    cost := current_item [ 3 ]
    if ( current_item not in outdated && cost < minimum_cost ) {
        minimum_cost = current_item [ 3 ]
        input_number = i + 1
}
fmt.Printf ( "%d", input_number )

