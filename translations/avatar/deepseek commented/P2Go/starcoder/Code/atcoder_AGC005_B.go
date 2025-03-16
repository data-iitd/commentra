// Define the root function to find the root of a given element in a disjoint set
func root ( x int ) int {
    if par [ x ] == x {
        return x
    }
    return root ( par [ x ] )
}

// Define the same function to check if two elements are in the same set
func same ( x, y int ) bool {
    return root ( x ) == root ( y )
}

// Define the unite function to merge two sets containing the given elements
func unite ( x, y int ) {
    if x!= y {
        if rank [ x ] < rank [ y ] {
            par [ x ] = y
            size [ y ] += size [ x ]
        } else {
            par [ y ] = x
            size [ x ] += size [ y ]
            if rank [ x ] == rank [ y ] {
                rank [ x ] += 1
            }
        }
    }
}

// Read the input, initialize the disjoint set, and process the array
var (
    n int
    a []int
    par, rank, size []int
)
fmt.Scan ( &n )
a = make ( []int, n )
par = make ( []int, n )
rank = make ( []int, n )
size = make ( []int, n )
for i := 0; i < n; i++ {
    fmt.Scan ( &a [ i ] )
    par [ i ] = i
    rank [ i ] = 1
    size [ i ] = 1
}

// Process the array in reverse order to calculate the result
var (
    c int
    b []int
)
b = make ( []int, n )
for i := 0; i < n; i++ {
    b [ a [ i ] - 1 ] = i
}
for k := n - 1; k >= 0; k-- {
    l, r := 1, 1
    if k > 0 && a [ k - 1 ] > a [ k ] {
        l += size [ root ( k - 1 ) ]
        unite ( k - 1, k )
    }
    if k + 1 < n && a [ k + 1 ] > a [ k ] {
        r += size [ root ( k + 1 ) ]
        unite ( k + 1, k )
    }
    c += l * r * a [ k ]
}

// Print the final result
fmt.Println ( c )

