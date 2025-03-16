// Read the number of elements
n := int(input())

// Read the elements into a list
x := make([]int, n)
for i := 0; i < n; i++ {
    x[i], _ = strconv.Atoi(input())
}

// Initialize two lists to hold elements at even and odd indices
a := make([]int, 0)
b := make([]int, 0)

// Distribute elements into lists based on their index (even or odd)
for i := 0; i < n; i++ {
    if i%2 == 0 {
        a = append(a, x[i])
    } else {
        b = append(b, x[i])
    }
}

// Initialize counters for occurrences of elements in lists 'a' and 'b'
cnta := make([]int, 100002)
cntb := make([]int, 100002)

// Variables to track the most frequent elements in list 'a'
vala := 0
vala1 := 0
maxCnta := 0
maxCnta1 := 0

// Count occurrences of each element in list 'a'
for i := 0; i < len(a); i++ {
    cnta[a[i]] += 1
}

// Find the most frequent element in list 'a'
for i := 0; i < len(a); i++ {
    if maxCnta < cnta[a[i]] {
        vala = a[i]
        maxCnta = cnta[a[i]]
    }
}

// Find the second most frequent element in list 'a'
for i := 0; i < len(a); i++ {
    if maxCnta1 < cnta[a[i]] && vala!= a[i] {
        maxCnta1 = cnta[a[i]]
        vala1 = a[i]
    }
}

// Variables to track the most frequent elements in list 'b'
valb := 0
valb1 := 0
maxCntb := 0
maxCntb1 := 0

// Count occurrences of each element in list 'b'
for i := 0; i < len(b); i++ {
    cntb[b[i]] += 1
}

// Find the most frequent element in list 'b'
for i := 0; i < len(b); i++ {
    if maxCntb < cntb[b[i]] {
        valb = b[i]
        maxCntb = cntb[b[i]]
    }
}

// Find the second most frequent element in list 'b'
for i := 0; i < len(b); i++ {
    if maxCntb1 < cntb[b[i]] && valb!= b[i] {
        maxCntb1 = cntb[b[i]]
        valb1 = b[i]
    }
}

// Check if the most frequent elements from both lists are different
if valb!= vala {
    res := 0
    // Count elements in 'a' that are not the most frequent element
    for i := 0; i < len(a); i++ {
        if a[i]!= vala {
            res += 1
    }
    // Count elements in 'b' that are not the most frequent element
    for i := 0; i < len(b); i++ {
        if b[i]!= valb {
            res += 1
    }
    // Print the total count of elements that are not the most frequent
    fmt.Println(res)
} else {
    // Initialize counters for elements not equal to the most frequent elements
    resa := 0
    resb := 0
    resa1 := 0
    resb1 := 0
    
    // Count elements in 'a' that are not the most frequent and second most frequent
    for i := 0; i < len(a); i++ {
        if a[i]!= vala {
            resa += 1
        }
        if a[i]!= vala1 {
            resa1 += 1
    }
            
    // Count elements in 'b' that are not the most frequent and second most frequent
    for i := 0; i < len(b); i++ {
        if b[i]!= valb {
            resb += 1
        }
        if b[i]!= valb1 {
            resb1 += 1
    }
            
    // Print the minimum of the two possible results
    fmt.Println(min(resa + resb1, resa1 + resb))
}

