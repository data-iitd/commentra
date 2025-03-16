n, x := 0, []int{}
a, b := []int{}, []int{}
var cnta, cntb []int
var vala, vala1, valb, valb1 int
var maxCnta, maxCnta1, maxCntb, maxCntb1 int
var res, resa, resa1, resb, resb1 int
fmt.Scanf("%d", &n)
x = make([]int, n)
for i := 0; i < n; i++ {
    fmt.Scanf("%d", &x[i])
}
a = make([]int, n/2)
b = make([]int, n/2)
cnta = make([]int, 100002+1)
cntb = make([]int, 100002+1)
for i := 0; i < n; i++ {
    if i%2 == 0 {
        a[i/2] = x[i]
    } else {
        b[i/2] = x[i]
    }
}
for i := 0; i < n/2; i++ {
    cnta[a[i]]++
}
for i := 0; i < n/2; i++ {
    if maxCnta < cnta[a[i]] {
        vala = a[i]
        maxCnta = cnta[a[i]]
    }
}
for i := 0; i < n/2; i++ {
    if maxCnta1 < cnta[a[i]] && vala!= a[i] {
        maxCnta1 = cnta[a[i]]
        vala1 = a[i]
    }
}
for i := 0; i < n/2; i++ {
    cntb[b[i]]++
}
for i := 0; i < n/2; i++ {
    if maxCntb < cntb[b[i]] {
        valb = b[i]
        maxCntb = cntb[b[i]]
    }
}
for i := 0; i < n/2; i++ {
    if maxCntb1 < cntb[b[i]] && valb!= b[i] {
        maxCntb1 = cntb[b[i]]
        valb1 = b[i]
    }
}
if valb!= vala {
    res = 0
    for i := 0; i < n/2; i++ {
        if a[i]!= vala {
            res++
        }
    }
    for i := 0; i < n/2; i++ {
        if b[i]!= valb {
            res++
        }
    }
    fmt.Println(res)
} else {
    resa = 0
    resb = 0
    resa1 = 0
    resb1 = 0
    for i := 0; i < n/2; i++ {
        if a[i]!= vala {
            resa++
        }
        if a[i]!= vala1 {
            resa1++
        }
    }
    for i := 0; i < n/2; i++ {
        if b[i]!= valb {
            resb++
        }
        if b[i]!= valb1 {
            resb1++
        }
    }
    fmt.Println(min(resa+resb1, resa1+resb))
}

