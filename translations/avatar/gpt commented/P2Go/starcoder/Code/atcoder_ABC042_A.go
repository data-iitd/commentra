// Read a line of input, split it into components, and convert each component to an integer, storing them in a tuple
ABC := strings.Split(bufio.NewReader(os.Stdin).ReadString(), " ")
ABC = make([]int, len(ABC))
for i := 0; i < len(ABC); i++ {
    ABC[i], _ = strconv.Atoi(ABC[i])
}

// Check if the number 5 appears exactly twice in the tuple
if ABC.count(5) == 2 {
    // If 5 appears twice, check if the sum of the numbers in the tuple equals 17
    fmt.Println("YES" if sum(ABC) == 17 else "NO")
} else {
    // If 5 does not appear exactly twice, print 'NO'
    fmt.Println("NO")
}

