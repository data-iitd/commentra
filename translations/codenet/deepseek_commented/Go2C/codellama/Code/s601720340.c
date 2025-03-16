
  // Package main defines the entry point of the program.
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>

  // Constants
  #define magic 1000000007

  // Flags for profiling
  char *cpuprofile = "";
  char *memprofile = "";

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
  	int X;
  	scanf("%d", &X);
  	scanf("%d", &N);
  	for (int i = 0; i < N; i++) {
  		scanf("%d", &p[i]);
  	}

  	// Search for the closest number to X in the array p.
  	for (int i = 0; i <= 100; i++) {
  		if (find(X - i) == 1) {
  			printf("%d\n", X - i);
  			exit(0);
  		}
  		if (find(X + i) == 1) {
  			printf("%d\n", X + i);
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
  typedef struct {
  	FILE *reader;
  	FILE *writer;
  	char *tokens[100000];
  	int nextToken;
  } Io;

  // NewIo generates Io instance.
  Io *NewIo() {
  	Io *io = (Io *)malloc(sizeof(Io));
  	io->reader = stdin;
  	io->writer = stdout;
  	return io;
  }

  // Flush flushes buffer. Don't forget to do this when you call Io.Printf/Io.PrintLn for final output.
  void Flush(Io *io) {
  	fflush(io->writer);
  }

  // NextLine parses line as string.
  char *NextLine(Io *io) {
  	char *buffer = (char *)malloc(sizeof(char) * 100000);
  	for (;;) {
  		char *line = (char *)malloc(sizeof(char) * 100000);
  		fgets(line, 100000, io->reader);
  		buffer = strcat(buffer, line);
  		if (strchr(line, '\n') != NULL) {
  			break;
  		}
  	}
  	return buffer;
  }

  // Next parse next word as string.
  char *Next(Io *io) {
  	for (io->nextToken >= 100000; io->nextToken < 100000; io->nextToken++) {
  		char *line = NextLine(io);
  		io->tokens[io->nextToken] = strtok(line, " ");
  		free(line);
  	}
  	char *r = io->tokens[io->nextToken];
  	io->nextToken++;
  	return r;
  }

  // NextInt parse next word as Int.
  int NextInt(Io *io) {
  	int i;
  	sscanf(Next(io), "%d", &i);
  	return i;
  }

  // NextFloat parses next word as float64.
  float NextFloat(Io *io) {
  	float i;
  	sscanf(Next(io), "%f", &i);
  	return i;
  }

  // PrintLn does buffer write with linefeed.
  void PrintLn(Io *io, char *a) {
  	fprintf(io->writer, "%s\n", a);
  }

  // Printf does formatted buffer write.
  void Printf(Io *io, char *format, char *a) {
  	fprintf(io->writer, format, a);
  }

  // PrintIntLn prints Int array in a single line.
  void PrintIntLn(Io *io, int *a, int n) {
  	char *buffer = (char *)malloc(sizeof(char) * 100000);
  	for (int i = 0; i < n; i++) {
  		buffer = strcat(buffer, a[i]);
  		buffer = strcat(buffer, " ");
  	}
  	PrintLn(io, buffer);
  	free(buffer);
  }

  // PrintStringLn prints string array in a single line.
  void PrintStringLn(Io *io, char **a, int n) {
  	char *buffer = (char *)malloc(sizeof(char) * 100000);
  	for (int i = 0; i < n; i++) {
  		buffer = strcat(buffer, a[i]);
  		buffer = strcat(buffer, " ");
  	}
  	PrintLn(io, buffer);
  	free(buffer);
  }

  // Log print single value to standard output (contest server ignores this so you don't have to remove when finishing)
  void Log(char *name, int value) {
  	fprintf(stderr, "%s=%+d\n", name, value);
  }

  // Logf print formatted output to standard output (contest server ignores this so you don't have to remove when finishing)
  void Logf(char *format, int a) {
  	fprintf(stderr, format, a);
  }

  int intMin(int a, int b) {
  	if (a < b) {
  		return a;
  	}
  	return b;
  }

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

  void bfs(int start, int *nodes, void (*fn)(int)) {
  	int frontier[100000];
  	int visited[100000];
  	frontier[0] = start;
  	visited[start] = 1;

  	for (int i = 0; i < 100000; i++) {
  		int next[100000];
  		int nextIndex = 0;
  		for (int j = 0; j < i; j++) {
  			int node = frontier[j];
  			visited[node] = 1;
  			fn(node);
  			for (int k = 0; k < 100000; k++) {
  				if (nodes[node * 100000 + k] != 0 && visited[nodes[node * 100000 + k]] == 0) {
  					next[nextIndex] = nodes[node * 100000 + k];
  					nextIndex++;
  				}
  			}
  		}
  		for (int j = 0; j < nextIndex; j++) {
  			frontier[j] = next[j];
  		}
  		if (nextIndex == 0) {
  			break;
  		}
  	}
  }

  void bfsFrontier(int node, int *nodes, int *visited) {
  	int next[100000];
  	int nextIndex = 0;
  	for (int i = 0; i < 100000; i++) {
  		if (nodes[node * 100000 + i] != 0 && visited[nodes[node * 100000 + i]] == 0) {
  			next[nextIndex] = nodes[node * 100000 + i];
  			nextIndex++;
  		}
  	}
  	return next;
  }

  void dfs(int node, int *nodes, void (*fn)(int)) {
  	int visited[100000];
  	dfsRecur(node, -1, nodes, visited, fn);
  }

  void dfsRecur(int node, int parent, int *nodes, int *v, void (*fn)(int)) {
  	v[node] = 1;
  	fn(node);
  	for (int i = 0; i < 100000; i++) {
  		if (nodes[node * 100000 + i] != 0 && v[nodes[node * 100000 + i]] == 0) {
  			dfsRecur(nodes[node * 100000 + i], node, nodes, v, fn);
  		}
  	}
  }

  // handles 2 function, one is before entering child tree, and another is
  // after entering child tree.
  void dfs2(int node, int *nodes, void (*fn1)(int, int), void (*fn2)(int, int)) {
  	dfs2Recur(node, -1, nodes, fn1, fn2);
  }

  void dfs2Recur(int node, int parent, int *nodes, void (*fn1)(int, int), void (*fn2)(int, int)) {
  	if (fn1 != NULL) {
  		fn1(node, parent);
  	}
  	for (int i = 0; i < 100000; i++) {
  		if (nodes[node * 100000 + i] != 0) {
  			dfs2Recur(nodes[node * 100000 + i], node, nodes, fn1, fn2);
  		}
  	}
  	if (fn2 != NULL) {
  		fn2(node, parent);
  	}
  }

  // Stack data structure
  typedef struct {
  	int top;
  	int size;
  } Stack;

  // Element is a struct for stack element
  typedef struct {
  	int value;
  	int next;
  } Element;

  // Len returns stack height
  int Len(Stack *s) {
  	return s->size;
  }

  // Push put a element on the stack.
  void Push(Stack *s, int value) {
  	Element *e = (Element *)malloc(sizeof(Element));
  	e->value = value;
  	e->next = s->top;
  	s->top = e;
  	s->size++;
  }

  // Pop picks out the last element from the stack.
  int Pop(Stack *s) {
  	if (s->size > 0) {
  		Element *e = s->top;
  		s->top = e->next;
  		s->size--;
  		return e->value;
  	}
  	return -1;
  }

  // powerInt (use math.Pow() for float parameters)
  int powerInt(int n, int p) {
  	int tmp = 1;
  	for (int i = 0; i < n; i++) {
  		tmp *= p;
  	}
  	return tmp;
  }

  void findDivisors(int n, int *a) {
  	if (n == 1) {
  		return;
  	}

  	int sqrt = (int)sqrt(n);
  	for (int i = 2; i <= sqrt; i++) {
  		if (n % i == 0) {
  			*a = i;
  			*a = n / i;
  		}
