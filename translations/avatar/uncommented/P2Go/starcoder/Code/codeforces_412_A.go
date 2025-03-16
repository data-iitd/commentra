n, k := 0, 0
v := ""
d := []string{ "LEFT", "RIGHT" }
f := false
m := 0
a := []string{}

func main() {
    fmt.Scanf("%d %d\n", &n, &k)
    v = strings.TrimSpace(fmt.Scanf("%s\n", &v))
    f = k-1 < n-k
    m = min(k-1, n-k)
    for i := 0; i < m; i++ {
        a = append(a, d[f])
    }
    for i := 0; i < len(v); i++ {
        a = append(a, "PRINT "+v[i])
        a = append(a, d[f])
    }
    fmt.Println(strings.Join(a[:len(a)-1], "\n"))
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

