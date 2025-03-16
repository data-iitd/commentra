
// Constants
final int mod = 998244353;
final int facNum = 300001;

// s716019902 function
public class s716019902{
    public static void main(String[] args) {
        // Initialize a new scanner
        Scanner sc = new Scanner(System.in);

        // Read an integer N from the standard input
        int N = sc.nextInt();

        // Initialize a variable sum to 0
        int sum = 0;

        // Loop through numbers from 1 to N
        for (int i = 1; i <= N; i++) {
            // If the number is not divisible by 3 or 5, add it to the sum
            if (i % 3!= 0 && i % 5!= 0) {
                sum += i;
            }
        }

        // Print the result to the standard output
        System.out.println(sum);
    }
}

// I/O
class Scanner {
    private final BufferedReader br;
    private StringTokenizer st;

    // Constructor
    public Scanner(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in));
    }

    // Next string
    String next() {
        while (st == null ||!st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    // Next integer
    int nextInt() {
        return Integer.parseInt(next());
    }

    // Next long
    long nextLong() {
        return Long.parseLong(next());
    }

    // Next double
    double nextDouble() {
        return Double.parseDouble(next());
    }

    // Next line
    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}

// Math functions
int pow(int a, int n) {
    // Calculate a^n modulo mod
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (int) ((long) ans * a % mod);
    }
    return ans;
}

int gcd(int a, int b) {
    // Calculate the greatest common divisor of a and b
    if (a < b) {
        return gcd(b, a);
    }
    while (b!= 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int min(int a, int b) {
    // Return the minimum of a and b
    return a < b? a : b;
}

// Combination function
int combination(int n, int k, int[] fac, int[] ifac) {
    // Calculate the binomial coefficient (n choose k) modulo mod
    if (n < k || n < 0) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    // While n is not 0
    int ans = ifac[k] * ifac[n - k] % mod;
    return (int) ((long) ans * fac[n] % mod);
}

// Factorial function
int[] factorial() {
    // Calculate and return the factorial of all numbers from 0 to facNum-1
    int[] fac = new int[facNum];
    int[] ifac = new int[facNum];
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < facNum; i++) {
        fac[i] = (int) ((long) fac[i - 1] * i % mod);
        ifac[i] = pow(fac[i], mod - 2);
    }
    return new int[]{fac, ifac};
}

// Lower bound function
int lowerBound(int[] vs, int v) {
    // Calculate the index of the first element in vs that is greater than or equal to v
    int n = Arrays.binarySearch(vs, v);
    if (n < 0) {
        n = -n - 1;
    }
    return n;
}

// Int array
int[] intArr(int n, int init) {
    // Create and initialize a new int array of length n with the given initial value
    int[] r = new int[n];
    Arrays.fill(r, init);
    return r;
}

// 

