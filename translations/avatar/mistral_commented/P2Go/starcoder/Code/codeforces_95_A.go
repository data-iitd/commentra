// Initialize variables
var pya int
var arre []string

// Process strings input
for {
    fmt.Scanln(&pya)
    if pya == 0 {
        break
    }
    var x string
    fmt.Scanln(&x)
    arre = append(arre, x)
}

// Get the original string and its first letter
var oString string
var letter1 string
fmt.Scanln(&oString)
fmt.Scanln(&letter1)

// Determine the second letter based on the first letter
var letter2 string
if letter1!= "a" {
    letter2 = "b"
} else {
    letter2 = "a"
}

// Initialize a list of valid indices and a set to store the indices of the strings in the original string
var valid []int
valid = make([]int, len(oString))
var setcito = make(map[int]bool)

// Find the indices of the strings in the original string
for _, x := range arre {
    for i := strings.Index(oString, x); i!= -1; i = strings.Index(oString[i+1:], x) {
        setcito[i] = true
    }
}

// Replace the letters in the original string based on the indices of the strings
for i, x := range oString {
    if setcito[i] {
        if x >= 'a' && x <= 'z' {
            if x >= 'a' && x <= 'z' {
                x = letter1[0]
            } else {
                x = letter1[0] - 32
            }
        } else {
            if x >= 'A' && x <= 'Z' {
                x = letter2[0] - 32
            } else {
                x = letter2[0]
            }
        }
    }
    fmt.Printf("%c", x)
}

// Print a newline after the modified string
fmt.Println()

