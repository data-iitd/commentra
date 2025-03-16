s := strings.TrimSpace ( input ( ) )
my_str := ""
for _, c := range s {
    if c == '0' || c == '1' {
        my_str += string ( c )
    } else if c == 'B' && len ( my_str )!= 0 {
        my_str = my_str [ : len ( my_str ) - 1 ]
    }
}
fmt.Println ( my_str )

