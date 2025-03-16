// Take the number of elements in the list from user input
n := int(input())

// Initialize an empty list 'x' to store the input elements
x := make([]int, n)

// Initialize two empty lists 'a' and 'b' to store even and odd elements respectively
a := make([]int, 0)
b := make([]int, 0)

// Iterate through the list 'x' and append even and odd elements to their respective lists
for i := 0; i < n; i++ {
    if i%2 == 0 {
        a = append(a, x[i])
    } else {
        b = append(b, x[i])
    }
}

// Initialize two lists 'cnta' and 'cntb' of size 100002+1 to store the count of each element in lists 'a' and 'b' respectively
cnta := make([]int, 100002+1)
cntb := make([]int, 100002+1)

// Initialize two variables 'vala' and 'valb' to store the elements with maximum count in lists 'a' and 'b' respectively
var vala, valb int

// Initialize two variables'maxCnta' and'maxCntb' to store the maximum count of an element in lists 'a' and 'b' respectively
var maxCnta, maxCntb int

// Iterate through list 'a' and update the count of each element in 'cnta'
for i := 0; i < len(a); i++ {
    cnta[a[i]] += 1
}

// Find the element with maximum count in list 'a' and update 'vala' and'maxCnta'
for i := 0; i < len(a); i++ {
    if maxCnta < cnta[a[i]] {
        vala = a[i]
        maxCnta = cnta[a[i]]
    }
}

// Find the second element with maximum count in list 'a' (different from 'vala') and update 'vala1' and'maxCnta1'
var vala1, maxCnta1 int
for i := 0; i < len(a); i++ {
    if maxCnta1 < cnta[a[i]] && a[i]!= vala {
        maxCnta1 = cnta[a[i]]
        vala1 = a[i]
    }
}

// Similar logic for list 'b'
for i := 0; i < len(b); i++ {
    cntb[b[i]] += 1
}

// Find the element with maximum count in list 'b' and update 'valb' and'maxCntb'
for i := 0; i < len(b); i++ {
    if maxCntb < cntb[b[i]] {
        valb = b[i]
        maxCntb = cntb[b[i]]
    }
}

// Find the second element with maximum count in list 'b' (different from 'valb') and update 'valb1' and'maxCntb1'
var valb1, maxCntb1 int
for i := 0; i < len(b); i++ {
    if maxCntb1 < cntb[b[i]] && b[i]!= valb {
        maxCntb1 = cntb[b[i]]
        valb1 = b[i]
    }
}

// Check if 'vala' and 'valb' are same or not
if valb!= vala {
    // If they are not same, calculate the sum of counts of all elements except 'vala' and 'valb' and print the result
    res := 0
    for i := 0; i < len(a); i++ {
        if a[i]!= vala {
            res += 1
        }
    }
    for i := 0; i < len(b); i++ {
        if b[i]!= valb {
            res += 1
        }
    }
    fmt.Println(res)
} else {
    // If 'vala' and 'valb' are same, calculate the sum of counts of all elements except 'vala' and the second element with maximum count in list 'a' and list 'b' respectively
    // and print the minimum of these two sums
    resa := 0
    resb := 0
    resa1 := 0
    resb1 := 0
    for i := 0; i < len(a); i++ {
        if a[i]!= vala {
            resa += 1
        }
        if a[i]!= vala1 {
            resa1 += 1
        }
    }
    for i := 0; i < len(b); i++ {
        if b[i]!= valb {
            resb += 1
        }
        if b[i]!= valb1 {
            resb1 += 1
        }
    }
    fmt.Println(min(resa+resb1, resa1+resb))
}

