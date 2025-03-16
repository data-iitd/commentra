
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Initialize a new scanner object to read input
    struct Scanner sc;
    scanner_init(&sc, stdin);

    // Read the first line of input containing N and D
    int N, D;
    int *a = scanner_read_line(&sc).ints;
    N = a[0];
    D = a[1];

    // Read N lines of input and store them in a slice called lines
    int **lines = scanner_read_lines(&sc, N).ints;

    // Initialize a counter variable count to 0
    int count = 0;

    // Iterate through each line in the lines slice
    for (int i = 0; i < N; i++) {
        // Calculate the Euclidean distance of the current line from the origin (0,0)
        int x = lines[i][0];
        int y = lines[i][1];
        double d = sqrt(x * x + y * y);

        // If the distance of the current line is less than or equal to D, increment the counter
        if (D >= d) {
            count++;
        }
    }

    // Write the final result to the output writer
    printf("%d\n", count);

    // Free the memory allocated for the lines slice
    for (int i = 0; i < N; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}

// Function scanner_init initializes a new scanner object
void scanner_init(struct Scanner *sc, FILE *r) {
    sc->sc = bufio.NewScanner(r)
}

// Scanner structure to read input lines
struct Scanner {
    *bufio.Scanner sc;
};

// Function scanner_read_line reads a single line of input and returns it as a Value object
struct Value scanner_read_line(struct Scanner *sc) {
    // Read a line using the scanner and return it as a Value object
    if (sc->sc.Scan()) {
        return Value(sc->sc.Text())
    }
    // Panic if there's an error while reading input
    panic("scan error")
}

// Function scanner_read_lines reads N lines of input and returns them as a slice of Value objects
struct Values scanner_read_lines(struct Scanner *sc, int n) {
    // Initialize an empty slice called a and append N Value objects to it
    struct Values a;
    for (int i = 0; i < n; i++) {
        // Read a single line and append it to the slice
        a = append(a, scanner_read_line(sc))
    }
    // Return the slice of Value objects
    return a
}

// Value structure to store a string value
struct Value {
    char *str;
};

// Function value_string returns the string representation of the Value object
char *value_string(struct Value v) {
    return v.str;
}

// Function value_int converts a Value object to an integer
int value_int(struct Value v) {
    // Parse the string representation of the Value object to an integer and return it
    char *endptr;
    int n = strtol(v.str, &endptr, 10);
    if (*endptr!= '\0') {
        // Panic if there's an error while converting the Value object to an integer
        panic("invalid integer")
    }
    return n;
}

// Function value_float64 converts a Value object to a float64
double value_float64(struct Value v) {
    // Parse the string representation of the Value object to a float64 and return it
    char *endptr;
    double f = strtod(v.str, &endptr);
    if (*endptr!= '\0') {
        // Panic if there's an error while converting the Value object to a float64
        panic("invalid float")
    }
    return f;
}

// Function value_strings splits a Value object into a slice of strings based on whitespace
char **value_strings(struct Value v) {
    // Split the string representation of the Value object based on whitespace and return the slice
    return strings.Split(v.str, " ")
}

// Function value_ints converts a Value object to a slice of integers
int *value_ints(struct Value v) {
    // Convert each string in the slice returned by the value_strings function to an integer and return the slice
    char **strings = value_strings(v);
    int *ints = malloc(sizeof(int) * len(strings));
    for (int i = 0; i < len(strings); i++) {
        ints[i] = atoi(strings[i]);
    }
    return ints;
}

// Function value_float64s converts a Value object to a slice of float64s
double *value_float64s(struct Value v) {
    // Parse each string in the slice returned by the value_strings function to a float64 and return the slice
    char **strings = value_strings(v);
    double *float64s = malloc(sizeof(double) * len(strings));
    for (int i = 0; i < len(strings); i++) {
        float64s[i] = atof(strings[i]);
    }
    return float64s;
}

// Function value_runes converts a Value object to a slice of runes
rune *value_runes(struct Value v) {
    // Convert the string representation of the Value object to a slice of runes and return it
    return []rune(v.str)
}

// Values structure to store a slice of Value objects
struct Values {
    struct Value *values;
    int len;
};

// Function values_strings returns a slice of slices of strings, where each inner slice corresponds to the strings in a single Value object
char ***values_strings(struct Values v) {
    // Convert each Value object to a slice of strings and return the outer slice
    char ***strings = malloc(sizeof(char *) * v.len);
    for (int i = 0; i < v.len; i++) {
        strings[i] = value_strings(v.values[i]).str;
    }
    return strings;
}

// Function values_ints returns a slice of slices of integers, where each inner slice corresponds to the integers in a single Value object
int ***values_ints(struct Values v) {
    // Convert each Value object to a slice of integers and return the outer slice
    int ***ints = malloc(sizeof(int *) * v.len);
    for (int i = 0; i < v.len; i++) {
        ints[i] = value_ints(v.values[i]);
    }
    return ints;
}

// Function values_float64s returns a slice of slices of float64s, where each inner slice corresponds to the float64s in a single Value object
double ***values_float64s(struct Values v) {
    // Convert each Value object to a slice of float64s and return the outer slice
    double ***float64s = malloc(sizeof(double *) * v.len);
    for (int i = 0; i < v.len; i++) {
        float64s[i] = value_float64s(v.values[i]);
    }
    return float64s;
}

// Function values_runes returns a slice of slices of runes, where each inner slice corresponds to the runes in a single Value object
rune ***values_runes(struct Values v) {
    // Convert each Value object to a slice of runes and return the outer slice
    rune ***runes = malloc(sizeof(rune *) * v.len);
    for (int i = 0; i < v.len; i++) {
        runes[i] = []rune(v.values[i].str)
    }
    return runes;
}

// Function len returns the length of a slice of Value objects
int len(struct Values v) {
    return v.len;
}

// Function append appends a Value object to a slice of Value objects
struct Values append(struct Values a, struct Value v) {
    // Allocate memory for a new Value object
    struct Values *na = malloc(sizeof(struct Values))
    *na = a
    na.values = append(na.values, v)
    na.len++
    return na
}

// Function main calls the Run function with standard input and output streams
func main() {
    // Initialize a new scanner object to read input
    struct Scanner sc;
    scanner_init(&sc, os.Stdin)

    // Read the first line of input containing N and D
    int N, D;
    int *a = scanner_read_line(&sc).ints;
    N = a[0];
    D = a[1];

    // Read N lines of input and store them as a slice of Value objects
    struct Values lines = scanner_read_lines(&sc, N).ints;

    // Initialize a counter variable count to 0
    int count = 0

    // Iterate through each line in the lines slice
    for i := 0; i < N; i++ {
        // Calculate the Euclidean distance of the current line to the origin (0,0)
        double d = math.Sqrt(float64(lines[i][0]*lines[i][0]
        if D >= d {
            count++
        }
    }

    // Write the final result to the output writer
    fmt.Fprintln(os.Stdout, count)

    // Free the memory allocated for the lines slice
    for i := 0; i < N; i++ {
        free(lines[i])
    }
    free(lines)

    return 0
}

// Function scanner_init initializes a new scanner object
func scanner_init(struct Scanner *sc, FILE *r) {
    sc.sc = bufio.NewScanner(r)
}

// Function scanner_read_line reads a single line of input and returns it as a Value object
func scanner_read_line(struct Scanner *sc) {
    // Read a line using the scanner and return it as a Value object
    struct Value v = scanner_read_line(sc)
    return v
}

// Function scanner_read_lines reads N lines of input and returns them as a slice of Value objects
func scanner_read_lines(struct Scanner *sc, int n) {
    // Initialize an empty slice called a and append N Value objects to it
    struct Values a;
    for i := 0; i < n; i++ {
        // Read a single line of input and append it to the slice
        a = append(a, scanner_read_line(sc)
    }
    return a
}

// Function Value structure to store a string value
type Value struct {
    str string
}

// Function Int converts a Value object to an integer
func (v Value) Int() int {
    // Parse the string representation of the Value object to an integer
    n, _ := strconv.Atoi(v.str)
    return n
}

// Function Float64 converts a Value object to a float64
func (v Value) Float64() float64 {
    // Parse the string representation of the Value object to a float64
    f, _ := strconv.ParseFloat(v.str, 64)
    return f
}

// Function Strings splits a Value object into a slice of strings
func (v Value) Strings() []string {
    // Split the string representation of the Value object into a slice of strings
    strs := strings.Split(v.str, " ")
    return strs
}

// Function Ints converts a Value object to a slice of integers
func (v Value) Ints() []int {
    // Split the string representation of the Value object into a slice of integers
    a := strings.Split(v.str, " ")
    return a
}

// Function Ints converts a Value object to a slice of integers
func (v Value) Ints() []int {
    // Convert each string in the slice to an integer
    n, _ := strconv.Atoi(v.str)
    return n
}

// Function Float64s converts a Value object to a slice of float64s
func (v Value) Float64s() []float64 {
   