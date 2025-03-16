n := int ( input ( ) )
i, j := 1, n * n
for ; i < j ; {
    fmt.Println ( i, j )
    i += 1
    j -= 1
}

