
// Package main defines the entry point of the program.

// Imports are necessary for various functionalities such as buffered I/O, mathematical operations, and system utilities.
import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"

	"flag"
	"runtime"
	"runtime/pprof"
)

// Constants
var magic = 1000000007

// Flags for profiling
var cpuprofile = flag.String("cpuprofile", "", "write cpu profile to file")
var memprofile = flag.String("memprofile", "", "write mem profile to file")

// Variables
var N int
var p [200000]int

// find checks if a number exists in the array p.
func find(n int) int {
	for i := 0; i < N; i++ {
		if n == p[i] {
			return 0
		}
	}
	return 1
}

// solve is the main function that handles the program logic.
func solve() {
	io := NewIo()
	defer io.Flush()

	// PARSE HELPER SESSION

	// X := io.NextInt()
	// N = io.NextInt()
	// for i := 0; i < N; i++ {
	// 	p[i] = io.NextInt()
	// }

	// Main logic to find the closest number to X in the array p.
	X := io.NextInt()
	N = io.NextInt()
	for i := 0; i < N; i++ {
		p[i] = io.NextInt()
	}

	// Search for the closest number to X in the array p.
	for i := 0; i <= 100; i++ {
		if find(X-i) == 1 {
			fmt.Printf("%v\n", X-i)
			os.Exit(0)
		}
		if find(X+i) == 1 {
			fmt.Printf("%v\n", X+i)
			os.Exit(0)
		}
	}
}

// main is the entry point of the program.
func main() {
	flag.Parse()
	if *cpuprofile!= "" {
		f, err := os.Create(*cpuprofile)
		if err!= nil {
			Logf("%v\n", err)
			os.Exit(1)
		}
		pprof.StartCPUProfile(f)
		defer pprof.StopCPUProfile()
	}

	solve()

	if *memprofile!= "" {
		f, err := os.Create(*memprofile)
		if err!= nil {
			Logf("could not create memory profile: ", err)
			os.Exit(1)
		}
		defer f.Close() // error handling omitted for example
		runtime.GC() // get up-to-date statistics
		if err := pprof.WriteHeapProfile(f); err!= nil {
			Logf("could not write memory profile: ", err)
			os.Exit(1)
		}
	}
}

// Io helps parsing inputs from standard input for programming contest.
class Io {
	private BufferedReader reader;
	private BufferedWriter writer;
	private StringTokenizer tokenizer;
	private int nextToken;

	public Io() {
		reader = new BufferedReader(new InputStreamReader(System.in));
		writer = new BufferedWriter(new OutputStreamWriter(System.out));
		tokenizer = new StringTokenizer("");
		nextToken = 0;
	}

	public void Flush() {
		try {
			writer.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public String NextLine() {
		try {
			return reader.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	public String Next() {
		while (nextToken >= tokenizer.countTokens()) {
			String line = NextLine();
			if (line == null) {
				return null;
			}
			tokenizer = new StringTokenizer(line);
		}
		nextToken++;
		return tokenizer.nextToken();
	}

	public int NextInt() {
		try {
			return Integer.parseInt(Next());
		} catch (NumberFormatException e) {
			e.printStackTrace();
		}
		return 0;
	}

	public float NextFloat() {
		try {
			return Float.parseFloat(Next());
		} catch (NumberFormatException e) {
			e.printStackTrace();
		}
		return 0;
	}

	public void PrintLn(Object... a) {
		try {
			for (int i = 0; i < a.length; i++) {
				writer.write("" + a[i]);
				if (i < a.length - 1) {
					writer.write(" ");
				}
			}
			writer.write("\n");
			writer.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void Printf(String format, Object... a) {
		try {
			writer.write(String.format(format, a));
			writer.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void PrintIntLn(int... a) {
		Object[] b = new Object[a.length];
		for (int i = 0; i < a.length; i++) {
			b[i] = a[i];
		}
		PrintLn(b);
	}

	public void PrintStringLn(String... a) {
		Object[] b = new Object[a.length];
		for (int i = 0; i < a.length; i++) {
			b[i] = a[i];
		}
		PrintLn(b);
	}

	public void Log(String name, Object value) {
		System.err.printf("%s=%+v\n", name, value);
	}

	public void Logf(String format, Object... a) {
		System.err.printf(format, a);
	}
}

// Stack data structure
class Stack {
	private Element top;
	private int size;

	public Stack() {
		top = null;
		size = 0;
	}

	public int Len() {
		return size;
	}

	public void Push(Object value) {
		top = new Element(value, top);
		size++;
	}

	public Object Pop() {
		if (size > 0) {
			Object value = top.value;
			top = top.next;
			size--;
			return value;
		}
		return null;
	}
}

// Element is a struct for stack element
class Element {
	public Object value;
	public Element next;

	public Element(Object value, Element next) {
		this.value = value;
		this.next = next;
	}
}

// powerInt (use math.Pow() for float parameters)
public int powerInt(int n, int p) {
	int tmp = 1;
	for (int i = 0; i < n; i++) {
		tmp *= p;
	}
	return tmp;
}

public void findDivisors(int n, int[] a) {
	if (n == 1) {
		return;
	}

	int sqrt = (int) Math.sqrt(n);
	for (int i = 2; i <= sqrt; i++) {
		if (n%i == 0) {
			a[0] = i;
			a[1] = n/i;
		}
	}
	a[1] = n;
}

public int[] removeDuplicate(int[] a) {
	int[] res = new int[a.length];
	int index = 0;
	for (int i = 0; i < a.length; i++) {
		if (i == 0 || a[i]!= a[i-1]) {
			res[index] = a[i];
			index++;
		}
	}
	return res;
}

public int abs(int a) {
	if (a > 0) {
		return a;
	}
	return -a;
}

// var gcdmap map[int](map[int]int)
// func gcd(a, b int) int {
// 	ina := a
// 	inb := b
// 	if _, ok := gcdmap[a];!ok {
// 		gcdmap[a] = make(map[int]int)
// 	}
// 	if _, ok := gcdmap[ina][inb]; ok {
// 		return gcdmap[ina][inb]
// 	}
// 	for b!= 0 {
// 		t := b
// 		b = a % b
// 		a = t
// 	}
// 	gcdmap[ina][inb] = a
// 	return a
// }

public int gcd(int a, int b) {
	while (a!= 0) {
		a, b = b % a, a
	}
	return b;
}

public int power2mod(int n, int mod) {
	int res = 1, x = 2;
	for (; n > 0; n >>= 1) {
		if (n&1 == 1) {
			res = res * x % mod;
		}
		x = x * x % mod;
	}
	return res;
}

public int power2(int n) {
	return power2mod(n, magic);
}

