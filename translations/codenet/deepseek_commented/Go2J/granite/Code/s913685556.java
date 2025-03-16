
// s913685556 function: Initializes a new Scanner, reads two integers A and B,
// and calculates the maximum value among A+B, A-B, and A*B. Finally, it prints the maximum value.
public class s913685556{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();

        int mx = Math.max(A + B, A - B);
        mx = Math.max(mx, A * B);
        System.out.println(mx);
    }
}

// Scanner class: Wraps a BufferedReader and provides methods to read various types of input data.
class Scanner {
    BufferedReader r;
    String[] buf;
    int p;

    public Scanner(InputStream in) {
        r = new BufferedReader(new InputStreamReader(in));
        buf = new String[0];
        p = 0;
    }

    String next() {
        if (p >= buf.length) {
            buf = readLine().split(" ");
            p = 0;
        }
        return buf[p++];
    }

    String nextLine() {
        try {
            return r.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    int[] nextIntArray() {
        return Arrays.stream(nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    long[] nextLongArray() {
        return Arrays.stream(nextLine().split(" ")).mapToLong(Long::parseLong).toArray();
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    double[] nextDoubleArray() {
        return Arrays.stream(nextLine().split(" ")).mapToDouble(Double::parseDouble).toArray();
    }

    String[] nextStringArray() {
        return nextLine().split(" ");
    }

    private String[] readLine() {
        try {
            return r.readLine().split(" ");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

// Translate the above Java code to C++ and end with comment "