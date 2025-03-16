// Main function: Initializes a new Scanner, reads two integers A and B,
// and calculates the maximum value among A+B, A-B, and A*B. Finally, it prints the maximum value.
public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int A = sc.nextInt();
	int B = sc.nextInt();

	int mx = max(A+B, A-B);
	mx = max(mx, A*B);
	System.out.println(mx);
}

// max function: Returns the larger of two integers.
public static int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Scanner class: Wraps a bufio.Reader and provides methods to read various types of input data.
class Scanner {
	private BufferedReader r;
	private StringTokenizer st;

	public Scanner(InputStream i) {
		r = new BufferedReader(new InputStreamReader(i));
	}

	public String next() throws IOException {
		while (st == null ||!st.hasMoreTokens()) {
			st = new StringTokenizer(r.readLine());
		}
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	public float nextFloat() throws IOException {
		return Float.parseFloat(next());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public String[] nextStringArray() throws IOException {
		return next().split(" ");
	}

	public int[] nextIntArray() throws IOException {
		String[] s = nextStringArray();
		int[] result = new int[s.length];
		for (int i = 0; i < s.length; i++) {
			result[i] = Integer.parseInt(s[i]);
		}
		return result;
	}

	public long[] nextLongArray() throws IOException {
		String[] s = nextStringArray();
		long[] result = new long[s.length];
		for (int i = 0; i < s.length; i++) {
			result[i] = Long.parseLong(s[i]);
		}
		return result;
	}

	public float[] nextFloatArray() throws IOException {
		String[] s = nextStringArray();
		float[] result = new float[s.length];
		for (int i = 0; i < s.length; i++) {
			result[i] = Float.parseFloat(s[i]);
		}
		return result;
	}

	public double[] nextDoubleArray() throws IOException {
		String[] s = nextStringArray();
		double[] result = new double[s.length];
		for (int i = 0; i < s.length; i++) {
			result[i] = Double.parseDouble(s[i]);
		}
		return result;
	}
}

