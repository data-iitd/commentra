
record_of_movements := input ( )
x , y := 0 , 0
d_movement := map [ string ] [ 2 ] int { "L" : [ 0 , - 1 ] , "R" : [ 0 , 1 ] , "U" : [ 1 , 0 ] , "D" : [ - 1 , 0 ] }
d := map [ 2 ] int { [ x , y ] : 0 }
bug := false
for move := range record_of_movements {
    temp := [ x , y ]
    x += d_movement [ move ] [ 0 ]
    y += d_movement [ move ] [ 1 ]
    if _, ok := d [ x , y ]; ! ok {
        for step := range d_movement {
            if ( x + d_movement [ step ] [ 0 ] , y + d_movement [ step ] [ 1 ] ) != temp && _, ok := d [ x + d_movement [ step ] [ 0 ] , y + d_movement [ step ] [ 1 ] ]; ok {
                bug = true
                break
            }
        }
    } else {
        bug = true
    }
    if bug {
        break
    }
    d [ x , y ] = 0
}
if bug {
    fmt.Println ( "BUG" )
} else {
    fmt.Println ( "OK" )
}



Translate the above Go code to C++ and end with comment "