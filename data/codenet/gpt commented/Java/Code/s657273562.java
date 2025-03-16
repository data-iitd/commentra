import java.io.*;
import java.util.*;

public class Main {
    // Static variables for input/output and data structures
    static PrintWriter pw;
    static Scanner sc;
    static ArrayList<Integer>[] adj;
    static boolean[] visit;
    static HashMap<Pair, Integer> dp;

    // Utility function to perform ceiling division
    static long ceildiv(long x, long y) { return (x+y-1)/y; }

    // Utility function to perform modular arithmetic
    static int mod(long x, int m) { return (int)((x%m+m)%m); }

    // HashMap to store integer mappings
    static HashMap<Integer, Integer> map;

    // Utility function to compute GCD of two numbers
    static long gcd(long x, long y) { return y==0 ? x : gcd(y, x % y); }

    // Utility function to convert boolean to integer (1 or 0)
    static int Int(boolean x) { return x ? 1 : 0; }

    // Function to add or update a Pair in the TreeMap
    static void put(TreeMap<Pair, Integer> map, Pair p) {
        if (map.containsKey(p))
            map.replace(p, map.get(p) + 1);
        else
            map.put(p, 1);
    }

    // Function to remove or decrement a Pair in the TreeMap
    static void rem(TreeMap<Pair, Integer> map, Pair p) {
        if (map.get(p) == 1)
            map.remove(p);
        else
            map.replace(p, map.get(p) - 1);
    }

    public static void main(String[] args) throws Exception {
        // Initialize Scanner and PrintWriter for input/output
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);

        // Read the number of elements
        int n = sc.nextInt();
        // Read and sort the array in descending order
        Integer[] arr = sc.nextsort(n);
        Arrays.sort(arr, Collections.reverseOrder());

        // If there are at least 3 elements, perform the main logic
        if (n >= 3) {
            TreeMap<Pair, Integer> map = new TreeMap<>(Collections.reverseOrder());
            long ans = arr[0] + arr[1]; // Initialize answer with the sum of the two largest elements
            map.put(new Pair(arr[0], arr[1]), 1); // Store the pair in the map

            // Create pairs with the third largest element
            Pair p1 = new Pair(arr[2], arr[1]), p2 = new Pair(arr[2], arr[0]);
            put(map, p1); put(map, p2);

            // Iterate through the rest of the elements
            for (int i = 3; i < n; i++) {
                Pair p = map.firstKey(); // Get the first key (largest pair)
                rem(map, p); // Remove it from the map
                ans += Math.min(p.x, p.y); // Add the minimum of the pair to the answer
                // Create new pairs with the current element and add them to the map
                put(map, new Pair(p.x, arr[i])); 
                put(map, new Pair(p.y, arr[i]));
            }
            // Print the final answer
            pw.println(ans);
        } else {
            // If there are less than 3 elements, print the largest element
            pw.println(arr[0]);
        }
        pw.close(); // Close the PrintWriter
    }

    // Function to fill an array based on the bits of x
    static void fill(int[] arr, int x) {
        for (int i = 0; i < 30; i++)
            arr[i] += Int(((1 << i) & x) != 0);
    }

    // Function to compute power using exponentiation by squaring
    static long pow(long a, long pow) {
        long ans = 1;
        while (pow > 0) {
            if ((pow & 1) == 1)
                ans *= a; // Multiply if the current bit is set
            a *= a; // Square the base
            pow >>= 1; // Shift right to process the next bit
        }
        return ans;
    }

    // Function to get power based on user input
    static int getpow(int x) throws Exception {
        int pow = x;
        pw.println("B " + pow);
        pw.flush();
        sc.next();
        pw.println("B " + pow);
        pw.flush();
        if (sc.nextInt() == 1) {
            pow *= x; // Update power if the response is 1
            while (true) {
                pw.println("B " + pow);
                pw.flush();
                if (sc.nextInt() == 0)
                    return pow / x; // Return the computed power
                pow *= x; // Continue multiplying
            }
        } else {
            return 1; // Return 1 if the response is not 1
        }
    }

    // Variables for linear sieve
    static int[] least;
    static TreeSet<Integer> prime;

    // Function to perform linear sieve for prime factorization
    static void linearsieve(int x) {
        least = new int[x + 1];
        prime = new TreeSet<Integer>();
        for (int i = 2; i <= x; i++) {
            if (least[i] == 0) {
                least[i] = i; // Mark the least prime factor
                prime.add(i); // Add prime to the set
            }
            for (int y : prime) {
                if (i * y <= x)
                    least[i * y] = y; // Update least prime factor for multiples
                else break;
            }
        }
    }

    // Function to print an array of integers
    static void printArr(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++)
            pw.print(arr[i] + " ");
        pw.println(arr[arr.length - 1]);
    }

    // Function to print an array of long integers
    static void printArr(long[] arr) {
        for (int i = 0; i < arr.length - 1; i++)
            pw.print(arr[i] + " ");
        pw.println(arr[arr.length - 1]);
    }

    // Function to print an array of Integer objects
    static void printArr(Integer[] arr) {
        for (int i = 0; i < arr.length; i++)
            pw.print(arr[i] + " ");
        pw.println();
    }

    // Function to print an array of characters
    static void printArr(char[] arr) {
        for (int i = 0; i < arr.length; i++)
            pw.print(arr[i] == 0 ? '1' : arr[i]);
        pw.println();
    }

    // Function to print an ArrayList of integers
    static void printArr(ArrayList<Integer> list) {
        for (int i = 0; i < list.size(); i++)
            pw.print(list.get(i) + " ");
        pw.println();
    }

    // Custom Scanner class for input handling
    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        // Method to read the next token as a String
        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        // Method to read the next token as an integer
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        // Method to read the next token as a long
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        // Method to read the next line as a String
        public String nextLine() throws IOException {
            return br.readLine();
        }

        // Method to read the next token as a double
        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        // Method to read an array of integers
        public int[] nextArr(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < arr.length; i++)
                arr[i] = nextInt();
            return arr;
        }

        // Method to read and sort an array of integers
        public Integer[] nextsort(int n) throws IOException {
            Integer[] arr = new Integer[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextInt();
            return arr;
        }

        // Method to read a pair of integers
        public Pair nextPair() throws IOException {
            return new Pair(nextInt(), nextInt());
        }

        // Method to read an array of pairs
        public Pair[] nextPairArr(int n) throws IOException {
            Pair[] arr = new Pair[n];
            for (int i = 0; i < n; i++)
                arr[i] = nextPair();
            return arr;
        }

        // Method to check if the input stream is ready
        public boolean ready() throws IOException {
            return br.ready();
        }
    }

    // Pair class to hold two integers and provide comparison functionality
    static class Pair implements Comparable<Pair> {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        // Override hashCode for proper functioning in hash-based collections
        public int hashCode() {
            return (this.x * 1000 + this.y);
        }

        // Compare pairs based on their values
        public int compareTo(Pair p) {
            int min1 = Math.min(x, y), min2 = Math.min(p.x, p.y);
            if (min1 != min2)
                return min1 - min2;
            if (x == p.x)
                return y - p.y;
            return x - p.x;
        }

        // Override equals for proper comparison
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }
            if (this.getClass() != obj.getClass()) {
                return false;
            }
            Pair p = (Pair) obj;
            return this.x == p.x && this.y == p.y;
        }

        // Clone method to create a new Pair instance
        public Pair clone() {
            return new Pair(x, y);
        }

        // String representation of the Pair
        public String toString() {
            return this.x + " " + this.y;
        }

        // Method to add another Pair to this Pair
        public void add(Pair p) {
            x += p.x;
            y += p.y;
        }
    }
}
