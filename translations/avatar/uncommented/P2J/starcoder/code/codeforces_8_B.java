record_of_movements = input ( )
x, y = 0, 0
d_movement = { 'L' : ( 0, - 1 ), 'R' : ( 0, 1 ), 'U' : ( 1, 0 ), 'D' : ( - 1, 0 ) }
d = new HashMap < > ( )
d. put ( x, y ), ""
bug = false
for move in record_of_movements :
    temp = new int [ 2 ]
    temp [ 0 ] = x
    temp [ 1 ] = y
    x += d_movement [ move ] [ 0 ]
    y += d_movement [ move ] [ 1 ]
    if ( x, y ) not in d :
        for step in d_movement :
            if ( x + d_movement [ step ] [ 0 ], y + d_movement [ step ] [ 1 ] )!= temp && ( x + d_movement [ step ] [ 0 ], y + d_movement [ step ] [ 1 ] ) in d :
                bug = true
                break
    else :
        bug = true
    if bug :
        break
    d. put ( x, y ), ""
if bug :
    print ( 'BUG' )
else :
    print ( 'OK' )

