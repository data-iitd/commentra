func main() {
    var K int
    fmt.Scan(&K)
    var S string
    fmt.Scan(&S)
    if len(S) <= K {
        fmt.Println(S)
    } else {
        fmt.Println(S[:K] + "...")
    }
}



Translate the above Python code to Java and end with comment "