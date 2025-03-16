s := input ( )
result := ""
i := 0
for ; i < len ( s ) ; {
    if s [ i ] == "." {
        result += "0"
    } else {
        i++
        if s [ i ] == "." {
            result += "1"
        } else {
            result += "2"
        }
    }
    i++
}
print ( result )

