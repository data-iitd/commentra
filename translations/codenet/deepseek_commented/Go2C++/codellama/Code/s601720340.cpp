
  // Package main defines the entry point of the program.
  #include <bits/stdc++.h>

  // Imports are necessary for various functionalities such as buffered I/O, mathematical operations, and system utilities.
  using namespace std;

  // Constants
  const int magic = 1000000007;

  // Flags for profiling
  string cpuprofile;
  string memprofile;

  // Variables
  int N;
  int p[200000];

  // find checks if a number exists in the array p.
  int find(int n) {
  	for (int i = 0; i < N; i++) {
  		if (n == p[i]) {
  			return 0;
  		}
  	}
  	return 1;
  }

  // solve is the main function that handles the program logic.
  void solve() {
  	// PARSE HELPER SESSION

  	// X := io.NextInt()
  	// N = io.NextInt()
  	// for i := 0; i < N; i++ {
  	// 	p[i] = io.NextInt()
  	// }

  	// Main logic to find the closest number to X in the array p.
  	int X = 0;
  	N = 0;
  	for (int i = 0; i < 200000; i++) {
  		p[i] = 0;
  	}

  	// Search for the closest number to X in the array p.
  	for (int i = 0; i <= 100; i++) {
  		if (find(X - i) == 1) {
  			cout << X - i << endl;
  			exit(0);
  		}
  		if (find(X + i) == 1) {
  			cout << X + i << endl;
  			exit(0);
  		}
  	}
  }

  // main is the entry point of the program.
  int main() {
  	// flag.Parse()
  	// if *cpuprofile != "" {
  	// 	f, err := os.Create(*cpuprofile)
  	// 	if err != nil {
  	// 		Logf("%v\n", err)
  	// 		os.Exit(1)
  	// 	}
  	// 	pprof.StartCPUProfile(f)
  	// 	defer pprof.StopCPUProfile()
  	// }

  	solve();

  	// if *memprofile != "" {
  	// 	f, err := os.Create(*memprofile)
  	// 	if err != nil {
  	// 		Logf("could not create memory profile: ", err)
  	// 		os.Exit(1)
  	// 	}
  	// 	defer f.Close() // error handling omitted for example
  	// 	runtime.GC() // get up-to-date statistics
  	// 	if err := pprof.WriteHeapProfile(f); err != nil {
  	// 		Logf("could not write memory profile: ", err)
  	// 		os.Exit(1)
  	// 	}
  	// }
  }

  // Io helps parsing inputs from standard input for programming contest.
  class Io {
  	// Variables
  	ifstream reader;
  	ofstream writer;
  	vector<string> tokens;
  	int nextToken;

  	// Constructor
  	Io() {
  		reader.open("input.txt");
  		writer.open("output.txt");
  		tokens = vector<string>();
  		nextToken = 0;
  	}

  	// Destructor
  	~Io() {
  		reader.close();
  		writer.close();
  	}

  	// Flush flushes buffer. Don't forget to do this when you call Io.Printf/Io.PrintLn for final output.
  	void Flush() {
  		writer.flush();
  	}

  	// NextLine parses line as string.
  	string NextLine() {
  		string buffer = "";
  		while (true) {
  			string line;
  			getline(reader, line);
  			buffer += line;
  			if (reader.eof()) {
  				break;
  			}
  		}
  		return buffer;
  	}

  	// Next parse next word as string.
  	string Next() {
  		while (nextToken >= tokens.size()) {
  			string line = NextLine();
  			tokens = vector<string>(split(line, " "));
  			nextToken = 0;
  		}
  		string r = tokens[nextToken];
  		nextToken++;
  		return r;
  	}

  	// NextInt parse next word as int.
  	int NextInt() {
  		return stoi(Next());
  	}

  	// NextFloat parses next word as float64.
  	float NextFloat() {
  		return stof(Next());
  	}

  	// PrintLn does buffer write with linefeed.
  	void PrintLn(string a) {
  		writer << a << endl;
  	}

  	// Printf does formatted buffer write.
  	void Printf(string format, string a) {
  		writer << format << a;
  	}

  	// PrintIntLn prints Int array in a single line.
  	void PrintIntLn(vector<int> a) {
  		vector<string> b = vector<string>();
  		for (int x : a) {
  			b.push_back(to_string(x));
  		}
  		PrintLn(join(b, " "));
  	}

  	// PrintStringLn prints string array in a single line.
  	void PrintStringLn(vector<string> a) {
  		PrintLn(join(a, " "));
  	}

  	// Log print single value to standard output (contest server ignores this so you don't have to remove when finishing)
  	void Log(string name, string value) {
  		cout << name << "=" << value << endl;
  	}

  	// Logf print formatted output to standard output (contest server ignores this so you don't have to remove when finishing)
  	void Logf(string format, string a) {
  		cout << format << a;
  	}
  };

  // intMin returns minimum of two integers.
  int intMin(int a, int b) {
  	if (a < b) {
  		return a;
  	}
  	return b;
  }

  // intMax returns maximum of two integers.
  int intMax(int a, int b) {
  	if (a > b) {
  		return a;
  	}
  	return b;
  }

  // direct calculation of combination
  // n, m should be "small"
  int combination(int n, int m) {
  	if (m > n) {
  		return 0;
  	} else if (m == n || m == 0) {
  		return 1;
  	} else {
  		int res = 1;
  		for (int i = 0; i < m; i++) {
  			res *= (n - i);
  		}
  		for (int i = 1; i <= m; i++) {
  			res /= i;
  		}
  		return res;
  	}
  }

  // caluclate combination modulo based on Lucas theorem
  int lucas(int n, int m, int p) {
  	int ntemp = n;
  	int mtemp = m;
  	int res = 1;
  	for (int i = 0; i < 100; i++) {
  		int nreminder = ntemp % p;
  		ntemp = ntemp / p;
  		int mreminder = mtemp % p;
  		mtemp = mtemp / p;
  		res = res * (combination(nreminder, mreminder) % p);
  		if (ntemp == 0) {
  			break;
  		}
  	}
  	return res % p;
  }

  int combMod(int n, int m, int p) {
  	return lucas(n, m, p);
  }

  // BFS
  void bfs(int start, map<int, vector<int>> nodes, function<void(int)> fn) {
  	queue<int> frontier;
  	map<int, bool> visited;

  	frontier.push(start);
  	visited[start] = true;

  	while (!frontier.empty()) {
  		int node = frontier.front();
  		frontier.pop();
  		fn(node);
  		for (int n : bfsFrontier(node, nodes, visited)) {
  			frontier.push(n);
  		}
  	}
  }

  vector<int> bfsFrontier(int node, map<int, vector<int>> nodes, map<int, bool> visited) {
  	vector<int> next;
  	auto iter = [&](int n) { return !visited[n]; };
  	for (int n : nodes[node]) {
  		if (iter(n)) {
  			next.push_back(n);
  		}
  	}
  	return next;
  }

  // DFS
  void dfs(int node, map<int, vector<int>> nodes, function<void(int)> fn) {
  	dfsRecur(node, -1, nodes, map<int, bool>(), fn);
  }

  void dfsRecur(int node, int parent, map<int, vector<int>> nodes, map<int, bool> v, function<void(int)> fn) {
  	v[node] = true;
  	fn(node);
  	for (int n : nodes[node]) {
  		if (v[n]) {
  			continue;
  		}
  		dfsRecur(n, node, nodes, v, fn);
  	}
  }

  // handles 2 function, one is before entering child tree, and another is
  // after entering child tree.
  void dfs2(int node, map<int, vector<int>> nodes, function<void(int, int)> fn1, function<void(int, int)> fn2) {
  	dfs2Recur(node, -1, nodes, map<int, bool>(), fn1, fn2);
  }

  void dfs2Recur(int node, int parent, map<int, vector<int>> nodes, map<int, bool> v, function<void(int, int)> fn1, function<void(int, int)> fn2) {
  	v[node] = true;
  	if (fn1) {
  		fn1(node, parent);
  	}
  	for (int n : nodes[node]) {
  		if (v[n]) {
  			continue;
  		}
  		dfs2Recur(n, node, nodes, v, fn1, fn2);
  	}
  	if (fn2) {
  		fn2(node, parent);
  	}
  }

  // Stack data structure
  class Stack {
  	// Variables
  	int top;
  	int size;
  	vector<int> stack;

  	// Constructor
  	Stack() {
  		top = -1;
  		size = 0;
  		stack = vector<int>();
  	}

  	// Destructor
  	~Stack() {
  		stack.clear();
  	}

  	// Len returns stack height
  	int Len() {
  		return size;
  	}

  	// Push put a element on the stack.
  	void Push(int value) {
  		stack.push_back(value);
  		top++;
  		size++;
  	}

  	// Pop picks out the last element from the stack.
  	int Pop() {
  		if (size > 0) {
  			int value = stack[top];
  			stack.erase(stack.begin() + top);
  			top--;
  			size--;
  			return value;
  		}
  		return -1;
  	}
  };

  // powerInt (use math.Pow() for float parameters)
  int powerInt(int n, int p) {
  	int tmp = 1;
  	for (int i = 0; i < n; i++) {
  		tmp *= p;
  	}
  	return tmp;
  }

  void findDivisors(int n, vector<int>* a) {
  	if (n == 1) {
  		return;
  	}

  	int sqrt = int(sqrt(n));
  	for (int i = 2; i <= sqrt; i++) {
  		if (n % i == 0) {
  			a->push_back(i);
  			a->push_back(n / i);
  		}
  	}
  	a->push_back(n);
  }

  vector<int> removeDuplicate(vector<int> a) {
  	map<int, bool> m;
  	for (int i = 0; i < a.size(); i++) {
  		m[a[i]] = true;
  	}
  	vector<int> res;
  	for (auto it = m.begin(); it != m.end(); it++) {
  		res.push_back(it->first);
  	}
  	return res;
  }

  int abs(int a) {
  	if (a > 0) {
  		return a;
  	}
  	return -a;
  }

  // var gcdmap map[int](map[int]int)
  // func gcd(a, b int) int {
  // 	ina := a
  // 	inb := b
  // 	if _, ok := gcdmap[a]; !ok {
  // 		gcdmap[a] = make(map[int]int)
  // 	}
  // 	if _, ok := gcdmap[ina][inb]; ok {
  // 		return gcdmap[ina][inb]
  // 	}
  // 	for b != 0 {
  // 		t := b
  // 		b = a % b
  // 		a = t
  // 	}
  // 	gcdmap[ina][inb] = a
  // 	return a
  // }

  int gcd(int a, int b) {
  	for (a != 0; b != 0; a %= b, b = a) {
  	}
  	return b;
  }

  int power2mod(int n, int mod)