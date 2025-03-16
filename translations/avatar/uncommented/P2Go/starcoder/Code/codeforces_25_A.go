n := 0
for _, v := range strings.Fields(os.Args[1]) {
    n += int(v) % 2
}
if n == 1 {
    fmt.Println(strings.Fields(os.Args[1]).Index(fmt.Sprintf("%d", 1)) + 1)
} else {
    fmt.Println(strings.Fields(os.Args[1]).Index(fmt.Sprintf("%d", 0)) + 1)
}

