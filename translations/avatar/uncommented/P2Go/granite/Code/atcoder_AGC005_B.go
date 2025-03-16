
root := func(x int) int {
    if par[x] == x {
        return x
    }
    par[x] = root(par[x])
    return par[x]
}
same := func(x, y int) bool {
    return root(x) == root(y)
}
unite := func(z...int) {
    x, y := root(z[0]), root(z[1])
    if x!= y {
        if rank[x] < rank[y] {
            par[x] = y
            size[y] += size[x]
        } else {
            par[y] = x
            size[x] += size[y]
            if rank[x] == rank[y] {
                rank[x]++
            }
        }
    }
}
n, _ := fmt.Fscanf(os.Stdin, "%d\n", &n)
par := make([]int, n)
rank := make([]int, n)
size := make([]int, n)
b := make([]int, n)
for i := 0; i < n; i++ {
    fmt.Fscanf(os.Stdin, "%d", &a[i])
    b[a[i]-1] = i
}
c := 0
for k := n - 1; k >= 0; k-- {
    l, r := 1, 1
    if k > 0 && a[k-1] > a[k] {
        l += size[root(k-1)]
        unite(k-1, k)
    }
    if k+1 < n && a[k+1] > a[k] {
        r += size[root(k+1)]
        unite(k+1, k)
    }
    c += l * r * a[k]
}
fmt.Fprint(os.Stdout, c)
