
const LUCKY = "abcd"

func main() {
    var n int
    fmt.Scan(&n)
    s := ""
    for i := 0; i < n; i++ {
        s += string(LUCKY[i%4])
    }
    fmt.Println(s)
}
