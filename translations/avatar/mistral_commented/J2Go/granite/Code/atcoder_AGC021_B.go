
// Importing necessary Go utility packages
import (
    "bufio"
    "fmt"
    "math"
    "os"
    "sort"
)

// Main function where the program starts
func main() {
    // Creating a scanner object for reading input from the console
    scan := bufio.NewScanner(os.Stdin)

    // Reading the number of points (N) from the input
    scan.Scan()
    N := int(mustParseInt(scan.Text()))

    // Creating two arrays, x and y, of size N for storing the x and y coordinates of the points respectively
    x := make([]int, N)
    y := make([]int, N)

    // Reading the x and y coordinates of each point and storing them in the respective arrays
    for i := 0; i < N; i++ {
        scan.Scan()
        parts := mustParseStringSlice(scan.Text(), " ")
        x[i] = mustParseInt(parts[0])
        y[i] = mustParseInt(parts[1])
    }

    // Calculating the angles between each pair of points and storing them in a list called thetas
    thetas := make([]float64, N)
    for i := 0; i < N; i++ {
        thetas[i] = 0.0
        for j := 0; j < N; j++ {
            if i == j {
                continue
            }
            // Calculating the angle using the atan2 function
            thetas[i] += math.Atan2(float64(y[j]-y[i]), float64(x[j]-x[i]))
        }
        // Sorting the list of angles in ascending order
        sort.Float64s(thetas)
        // Adding the angle between the last point and the first point (wrapped around 2π) to the list
        thetas[i] += 2 * math.Pi
    }

    // Finding the maximum angle between consecutive angles and calculating the answer
    ans := 0.0
    for k := 0; k < N-1; k++ {
        ans = math.Max(ans, thetas[k+1]-thetas[k]-math.Pi)
    }

    // Printing the answer
    fmt.Printf("%.10f\n", ans/(2*math.Pi))
}

// Function to parse a string into an integer
func mustParseInt(s string) int {
    i, err := strconv.Atoi(s)
    if err!= nil {
        panic(err)
    }
    return i
}

// Function to parse a string into a slice of strings
func mustParseStringSlice(s, sep string) []string {
    parts := strings.Split(s, sep)
    if len(parts) == 1 && parts[0] == "" {
        return []string{}
    }
    return parts
}

// Function to parse a string into a slice of integers
func mustParseIntSlice(s, sep string) []int {
    parts := mustParseStringSlice(s, sep)
    var i []int
    for _, part := range parts {
        i = append(i, mustParseInt(part))
    }
    return i
}

// Function to parse a string into a slice of floats
func mustParseFloat64Slice(s, sep string) []float64 {
    parts := mustParseStringSlice(s, sep)
    var f []float64
    for _, part := range parts {
        f = append(f, mustParseFloat64(part))
    }
    return f
}

// Function to parse a string into a float64
func mustParseFloat64(s string) float64 {
    f, err := strconv.ParseFloat(s, 64)
    if err!= nil {
        panic(err)
    }
    return f
}

// Function to parse a string into a bool
func mustParseBool(s string) bool {
    b, err := strconv.ParseBool(s)
    if err!= nil {
        panic(err)
    }
    return b
}

// Function to parse a string into a complex number
func mustParseComplex(s string) complex128 {
    c, err := strconv.ParseComplex(s, 64)
    if err!= nil {
        panic(err)
    }
    return c
}

// Function to parse a string into a rune
func mustParseRune(s string) rune {
    r, size := utf8.DecodeRuneInString(s)
    if size!= len(s) {
        panic("rune size mismatch")
    }
    return r
}

// Function to parse a string into a byte slice
func mustParseByteSlice(s string) []byte {
    return []byte(s)
}

// Function to parse a string into a time.Time
func mustParseTime(s string, layout string) time.Time {
    t, err := time.Parse(layout, s)
    if err!= nil {
        panic(err)
    }
    return t
}

// Function to parse a string into a duration
func mustParseDuration(s string) time.Duration {
    d, err := time.ParseDuration(s)
    if err!= nil {
        panic(err)
    }
    return d
}

// Function to parse a string into a uuid.UUID
func mustParseUUID(s string) uuid.UUID {
    u, err := uuid.Parse(s)
    if err!= nil {
        panic(err)
    }
    return u
}

// Function to parse a string into a url.URL
func mustParseURL(s string) *url.URL {
    u, err := url.Parse(s)
    if err!= nil {
        panic(err)
    }
    return u
}

// Function to parse a string into a net.IP
func mustParseIP(s string) net.IP {
    ip := net.ParseIP(s)
    if ip == nil {
        panic("invalid IP address")
    }
    return ip
}

// Function to parse a string into a net.TCPAddr
func mustParseTCPAddr(s string) *net.TCPAddr {
    addr, err := net.ResolveTCPAddr("tcp", s)
    if err!= nil {
        panic(err)
    }
    return addr
}

// Function to parse a string into a net.UDPAddr
func mustParseUDPAddr(s string) *net.UDPAddr {
    addr, err := net.ResolveUDPAddr("udp", s)
    if err!= nil {
        panic(err)
    }
    return addr
}

// Function to parse a string into a net.IPNet
func mustParseIPNet(s string) *net.IPNet {
    _, ipnet, err := net.ParseCIDR(s)
    if err!= nil {
        panic(err)
    }
    return ipnet
}

// Function to parse a string into a net.HardwareAddr
func mustParseHardwareAddr(s string) net.HardwareAddr {
    addr, err := net.ParseMAC(s)
    if err!= nil {
        panic(err)
    }
    return addr
}

// Function to parse a string into a mail.Address
func mustParseMailAddress(s string) *mail.Address {
    addr, err := mail.ParseAddress(s)
    if err!= nil {
        panic(err)
    }
    return addr
}

// Function to parse a string into a mail.AddressList
func mustParseMailAddressList(s string) []*mail.Address {
    addrList, err := mail.ParseAddressList(s)
    if err!= nil {
        panic(err)
    }
    return addrList
}

// Function to parse a string into a syscall.Signal
func mustParseSignal(s string) syscall.Signal {
    signal, err := syscall.SignalFromString(s)
    if err!= nil {
        panic(err)
    }
    return signal
}

// Function to parse a string into a syscall.RawConn
func mustParseRawConn(s string) syscall.RawConn {
    // Implement the parsing logic for syscall.RawConn
    //...
    return nil
}

// Function to parse a string into a syscall.Socket
func mustParseSocket(s string) syscall.Socket {
    // Implement the parsing logic for syscall.Socket
    //...
    return 0
}

// Function to parse a string into a syscall.Stat_t
func mustParseStat_t(s string) syscall.Stat_t {
    // Implement the parsing logic for syscall.Stat_t
    //...
    return syscall.Stat_t{}
}

// Function to parse a string into a syscall.Timespec
func mustParseTimespec(s string) syscall.Timespec {
    // Implement the parsing logic for syscall.Timespec
    //...
    return syscall.Timespec{}
}

// Function to parse a string into a syscall.Timeval
func mustParseTimeval(s string) syscall.Timeval {
    // Implement the parsing logic for syscall.Timeval
    //...
    return syscall.Timeval{}
}

// Function to parse a string into a syscall.Rusage
func mustParseRusage(s string) syscall.Rusage {
    // Implement the parsing logic for syscall.Rusage
    //...
    return syscall.Rusage{}
}

// Function to parse a string into a syscall.PtraceRegset
func mustParsePtraceRegset(s string) syscall.PtraceRegset {
    // Implement the parsing logic for syscall.PtraceRegset
    //...
    return syscall.PtraceRegset{}
}

// Function to parse a string into a syscall.PtraceRegset
func mustParsePtraceRegset(s string) syscall.PtraceRegset {
    // Implement the parsing logic for syscall.PtraceRegset
    //...
    return syscall.PtraceRegset{}
}

// Function to parse a string into a syscall.Fsid
func mustParseFsid(s string) syscall.Fsid {
    // Implement the parsing logic for syscall.Fsid
    //...
    return syscall.Fsid{}
}

// Function to parse a string into a syscall.Statfs_t
func mustParseStatfs_t(s string) syscall.Statfs_t {
    // Implement the parsing logic for syscall.Statfs_t
    //...
    return syscall.Statfs_t{}
}

// Function to parse a string into a syscall.Flock_t
func mustParseFlock_t(s string) syscall.Flock_t {
    // Implement the parsing logic for syscall.Flock_t
    //...
    return syscall.Flock_t{}
}

// Function to parse a string into a syscall.EpollEvent
func mustParseEpollEvent(s string) syscall.EpollEvent {
    // Implement the parsing logic for syscall.EpollEvent
    //...
    return syscall.EpollEvent{}
}

// Function to parse a string into a syscall.InotifyEvent
func mustParseInotifyEvent(s string) syscall.InotifyEvent {
    // Implement the parsing logic for syscall.InotifyEvent
    //...
    return syscall.InotifyEvent{}
}

// Function to parse a string into a syscall.Timex
func mustParseTimex(s string) syscall.Timex {
    // Implement the parsing logic for syscall.Timex
    //...
    return syscall.Timex{}
}

// Function to parse a string into a syscall.Timespec
func mustParseTimespec(s string) syscall.Timespec {
    // Implement the parsing logic for syscall.Timespec
    //...
    return syscall.Timespec{}
}

// Function to parse a string into a syscall.Timeval
func mustParseTimeval(s string) syscall.Timeval {
    // Implement the parsing logic for syscall.Timeval
    //...
    return syscall.Timeval{}
}

// Function to parse a string into a syscall.Itimerval
func mustParseItimerval(s string) syscall.Itimerval {
    // Implement the parsing logic for syscall.Itimerval
    //...
    return syscall.Itimerval{}
}

// Function to parse a string into a syscall.Timeval
func mustParseTimeval(s string) syscall.Timeval {
    // Implement the parsing logic for syscall.Timeval
    //...
    return syscall.Timeval{}
}

// Function to parse a string into a syscall.Timeval
func mustParseTimeval(s string) syscall.Timeval {
    // Implement the parsing logic for syscall.Timeval
    //...
    return syscall.Timeval{}
}

// Function to parse a string into a syscall.Timeval
func mustParseTimeval(s string) syscall.Timeval {
    // Implement the parsing logic for syscall.Timeval
    //...
    return syscall.Timeval{}
}

// Function to parse a