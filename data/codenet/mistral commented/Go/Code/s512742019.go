// I/O
type Scanner struct {
	sc *bufio.Scanner
}

// NewScanner initializes a new Scanner struct with a bufio.Scanner
func NewScanner() *Scanner {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Buffer(make([]byte, 1024), int(1e+9)) // Buffer size for efficient reading
	return &Scanner{sc}
}

// Helper functions for reading different data types from the scanner
func (s *Scanner) nextStr() string {
	s.sc.Scan()
	return s.sc.Text()
}

func (s *Scanner) nextInt() int {
	i, e := strconv.Atoi(s.nextStr())
	if e != nil {
		panic(e)
	}
	return i
}

func (s *Scanner) nextFloat() float64 {
	f, e := strconv.ParseFloat(s.nextStr(), 64)
	if e != nil {
		panic(e)
	}
	return f
}

func (s *Scanner) nextRuneSlice() []rune {
	return []rune(s.nextStr())
}

func (s *Scanner) nextIntSlice(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = s.nextInt()
	}
	return res
}

func (s *Scanner) nextFloatSlice(n int) []float64 {
	res := make([]float64, n)
	for i := 0; i < n; i++ {
		res[i] = s.nextFloat()
	}
	return res
}

// Arithmetic
func max(nums ...int) int {
	m := nums[0]
	for _, i := range nums {
		if m < i {
			m = i
		}
	}
	return m
}

func min(nums ...int) int {
	m := nums[0]
	for _, i := range nums {
		if m > i {
			m = i
		}
	}
	return m
}

func abs(x int) int {
	if x > 0 {
		return x
	}
	return -x
}

func pow(x, y int) int {
	res := 1
	for i := 0; i < y; i++ {
		res *= x
	}
	return res
}

func ceil(a, b int) int {
	if a%b == 0 {
		return a / b
	} else {
		return a/b + 1
	}
}

// Sort
type RuneSlice []rune

// Custom sorting function for RuneSlice
func (a RuneSlice) Len() int           { return len(a) }
func (a RuneSlice) Less(i, j int) bool { return a[i] < a[j] }
func (a RuneSlice) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }

// Main
const MOD = int(1e+9) + 7 // Modulus value for modular arithmetic
const INF = 1 << 60      // Infinite value for comparison

// Mon represents a monster with x-coordinate and height
type Mon struct {
	x, h int
}

// Mons is a slice of Mon structures
type Mons []Mon

// Custom sorting function for Mons
func (a Mons) Len() int           { return len(a) }
func (a Mons) Less(i, j int) bool { return a[i].x < a[j].x }
func (a Mons) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }

// Node represents a node in the priority queue with x-coordinate and damage
type Node struct {
	x, h int
}

// Queue is a priority queue implemented as a slice with custom push, pop, and isEmpty functions
type Queue struct {
	arr []Node
}

// Pushes a new Node to the priority queue
func (q *Queue) push(v Node) {
	q.arr = append(q.arr, v)
}

// Returns the first Node in the priority queue
func (q *Queue) first() Node {
	return q.arr[0]
}

// Pops and returns the first Node from the priority queue
func (q *Queue) pop() Node {
	res := q.arr[0]
	q.arr = q.arr[1:]
	return res
}

// Checks if the priority queue is empty
func (q *Queue) isEmpty() bool {
	return len(q.arr) == 0
}

// Main function initializes variables, sorts monsters, and calculates the answer
func main() {
	// Initialize a new Scanner and a bufio.Writer for input/output
	sc := NewScanner()
	wtr := bufio.NewWriter(os.Stdout)

	// Read input values N, D, and A from the scanner
	N, D, A := sc.nextInt(), sc.nextInt(), sc.nextInt()

	// Initialize a slice of Mon structures called M
	M := make([]Mon, N)

	// Read x and h values for each Mon and store them in the M slice
	for i := 0; i < N; i++ {
		M[i] = Mon{sc.nextInt(), sc.nextInt()}
	}

	// Sort the M slice based on x-coordinates
	sort.Sort(Mons(M))

	// Initialize an empty priority queue called q
	var q Queue

	// Initialize answer variable ans to 0 and total variable total to 0
	ans := 0
	total := 0

	// Iterate through each Mon in the sorted M slice
	for i := 0; i < N; i++ {
		// Current Mon
		m := M[i]

		// While the priority queue is not empty and the current Mon's x-coordinate is smaller than the x-coordinate of the first Node in the priority queue
		for !q.isEmpty() && q.first().x < m.x {
			// Pop the first Node from the priority queue
			total -= q.pop().h
		}

		// If the total damage is less than the Mon's height, calculate the remaining damage, add it to the answer, and push it to the priority queue
		if total < m.h {
			damage := m.h - total
			ans += damage
			q.push(Node{m.x + 2*D, damage})
			total += damage
		}
	}

	// Print the answer
	fmt.Fprintln(wtr, ans)

	// Flush the writer to output the answer
	wtr.Flush()
}
