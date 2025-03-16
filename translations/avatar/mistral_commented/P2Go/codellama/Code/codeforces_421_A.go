// Assigning the values of input variables to n, a, and b
n, a, b := [int(x) for x in input().split()]

// Creating two lists, lista and listb, from the input
lista := [int(x) for x in input().split()]
listb := [int(x) for x in input().split()]

// Iterating through the range of n
for k := range(n) {
    // Checking if k+1 is present in the lista list
    if k + 1 in lista {
        // Printing 1 if k+1 is present in the lista list
        print(1, end=" ")
    } else {
        // Printing 2 if k+1 is not present in the lista list
        print(2, end=" ")
    }
}
