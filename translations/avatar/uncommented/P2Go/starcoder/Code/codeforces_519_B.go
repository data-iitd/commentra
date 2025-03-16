n := 0
a := []int{}
b := []int{}
c := []int{}
x := 0
y := 0
z := 0
for _, v := range strings.Fields(os.Args[1]) {
    n, _ = strconv.Atoi(v)
    a = append(a, n)
}
for _, v := range strings.Fields(os.Args[2]) {
    n, _ = strconv.Atoi(v)
    b = append(b, n)
}
for _, v := range strings.Fields(os.Args[3]) {
    n, _ = strconv.Atoi(v)
    c = append(c, n)
}
for _, v := range a {
    x += v
}
for _, v := range b {
    y += v
}
for _, v := range c {
    z += v
}
fmt.Printf("%d\n", abs(x-y))
fmt.Printf("%d\n", abs(y-z))

