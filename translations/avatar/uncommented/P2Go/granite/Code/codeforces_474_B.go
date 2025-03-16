
var L []int
fmt.Scanln ( )
r := 1
for _, k := range strings.Split ( bufio.NewReader ( os.Stdin ).Text ( ), " " ) {
    L = append ( L, r )
    r += 1
}
fmt.Scanln ( )
for _, j := range strings.Split ( bufio.NewReader ( os.Stdin ).Text ( ), " " ) {
    fmt.Println ( L [ int ( j ) - 1 ] )
}
