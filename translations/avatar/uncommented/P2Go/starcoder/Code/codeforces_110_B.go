const LUCKY = "abcd"
func main() {
    var n int
    fmt.Scanf("%d", &n)
    s := ""
    for i := 0; i < n; i++ {
        s += LUCKY[i%4]
    }
    fmt.Println(s)
}
