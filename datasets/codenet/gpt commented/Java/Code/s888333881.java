import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    
    // Graph0n class represents a graph using an adjacency list
    static class Graph0n {
        private ArrayList<Node0n> dt = new ArrayList<>(); // List of nodes in the graph
        
        // Constructor to initialize the graph with a specified size
        Graph0n(int sz) {
            for (int i = 0; i < sz; i++) {
                Node0n node1 = new Node0n(); // Create a new node
                dt.add(node1); // Add node to the graph
            }
        }
        
        // Add a directed edge from vn to val
        public void add(int vn, int val) {
            dt.get(vn).add(val);
        }
        
        // Add an undirected edge between vn and val
        public void add2(int vn, int val) {
            dt.get(vn).add(val);
            dt.get(val).add(vn);
        }
        
        // Get the value at a specific index of a node
        public int get(int vn, int index) {
            return dt.get(vn).get(index);
        }
        
        // Get all values connected to a node
        public ArrayList<Integer> get(int vn) {
            return dt.get(vn).getAll();
        }
        
        // Get the size of the adjacency list for a node
        public int sizeOf(int vn) {
            return dt.get(vn).size();
        }
        
        // Clear all edges in the graph
        public void clear() {
            for (int i = 0; i < dt.size(); i++) {
                dt.get(i).clear();
            }
        }
    }
    
    // Node0n class represents a node in the graph
    static class Node0n {
        private ArrayList<Integer> next_vs = new ArrayList<>(); // List of adjacent nodes
        
        // Add a value to the list of adjacent nodes
        public void add(int val) {
            next_vs.add(val);
        }
        
        // Get the value at a specific index
        public int get(int ad) {
            return next_vs.get(ad);
        }
        
        // Get all adjacent nodes
        public ArrayList<Integer> getAll() {
            return next_vs;
        }
        
        // Get the number of adjacent nodes
        public int size() {
            return next_vs.size();
        }
        
        // Clear the list of adjacent nodes
        public void clear() {
            next_vs.clear();
        }
    }

    // Edge class represents a weighted edge in the graph
    static class Edge {
        int from = -1, v2 = -1; // Start and end vertices
        long weight; // Weight of the edge
        
        // Constructor for edge with a single vertex and weight
        public Edge(int vn, long w) {
            this.v2 = vn;
            this.weight = w;
        }
        
        // Constructor for edge with two vertices and weight
        public Edge(int cm, int vn, long w) {
            this.from = cm;
            this.v2 = vn;
            this.weight = w;
        }
    }
    
    // Edge2 class represents an edge with two costs
    static class Edge2 {
        int v2; // End vertex
        long cost1, cost2; // Two different costs associated with the edge
        
        // Constructor for Edge2
        public Edge2(int vn, long w1, long w2) {
            this.v2 = vn;
            this.cost1 = w1;
            this.cost2 = w2;
        }
    }

    // Comparator for sorting edges by weight (descending)
    static class Comparator_Edge implements Comparator<Edge> {
        public int compare(Edge a, Edge b) {
            if (a.weight > b.weight) return -1; // a comes before b
            else if (a.weight < b.weight) return 1; // b comes before a
            else return b.v2 - a.v2; // If weights are equal, sort by vertex
        }
    }
    
    // Comparator for sorting edges by vertex and weight
    static class V2Comp implements Comparator<Edge> {
        public int compare(Edge a, Edge b) {
            if (a.v2 > b.v2) return -1; // a comes before b
            else if (a.v2 < b.v2) return 1; // b comes before a
            else if (a.weight > b.weight) return -1; // Sort by weight if vertices are equal
            else if (a.weight < b.weight) return 1;
            else return 0; // Equal edges
        }
    }
    
    // Comparator for sorting edges by vertex (ascending) and weight (descending)
    static class antiV2 implements Comparator<Edge> {
        public int compare(Edge a, Edge b) {
            if (a.v2 > b.v2) return 1; // b comes before a
            else if (a.v2 < b.v2) return -1; // a comes before b
            else if (a.weight > b.weight) return -1; // a comes before b
            else if (a.weight < b.weight) return 1;
            else return 0; // Equal edges
        }
    }
    
    // Vector class to represent a 2D vector
    static class Vector {
        int x, y; // x and y coordinates
        
        // Constructor for Vector
        public Vector(int sx, int sy) {
            this.x = sx;
            this.y = sy;
        }
    }
    
    // Main method to execute the program
    public static void main(String[] args) throws Exception {
        FastScanner sc = new FastScanner(); // Initialize scanner for input
        PrintWriter out = new PrintWriter(System.out); // Output writer
        
        // Read number of elements and a string
        int n = sc.nexI();
        String s = sc.next();
        boolean[] flaged = new boolean[n]; // Array to track flagged positions
        fill(flaged, false); // Initialize flagged array to false
        
        long pop1st = 0L; // Count of '1's in the string
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') {
                flaged[i] = true; // Mark position as flagged
                pop1st++; // Increment count of '1's
            }
        }
        
        long surp1 = 0; // Variable to hold intermediate results
        
        // Calculate surp1 based on flagged positions
        for (int i = 0; i < n; i++) {
            surp1 *= 2L; // Double the value
            if (flaged[i]) surp1++; // Increment if flagged
            surp1 %= (pop1st + 1L); // Modulo operation
        }
        
        long surp9 = 0L; // Variable for another calculation
        if (pop1st > 1) { // Only calculate if there are more than 1 '1's
            for (int i = 0; i < n; i++) {
                surp9 *= 2L; // Double the value
                if (flaged[i]) surp9++; // Increment if flagged
                surp9 %= (pop1st - 1L); // Modulo operation
            }
        }
        
        // Process each position in the string
        for (int p = 0; p < n; p++) {
            if (flaged[p]) { // If the position is flagged
                if (pop1st == 1) {
                    out.println(0); // Special case for single '1'
                    continue; // Skip to next iteration
                }
                long dw = surp9; // Use surp9 for calculations
                
                long dif = pow10E97(2, n - p - 1, pop1st - 1); // Calculate difference
                dw -= dif; // Subtract difference
                dw += (pop1st - 1L); // Adjust dw
                dw %= (pop1st - 1L); // Modulo operation
                
                int ans = 1; // Initialize answer
                while (dw != 0) { // While dw is not zero
                    if (dw < 0) out.println(1 / 0); // Error case
                    int count = countFlaged(dw); // Count flagged bits
                    dw %= count; // Modulo operation
                    ans++; // Increment answer
                }
                out.println(ans); // Output the answer
            } else { // If the position is not flagged
                long dw = surp1; // Use surp1 for calculations
                
                long dif = pow10E97(2, n - p - 1, pop1st + 1); // Calculate difference
                dw += dif; // Add difference
                dw %= (pop1st + 1L); // Modulo operation
                
                int ans = 1; // Initialize answer
                while (dw != 0) { // While dw is not zero
                    if (dw < 0) out.println(1 / 0); // Error case
                    int count = countFlaged(dw); // Count flagged bits
                    dw %= count; // Modulo operation
                    ans++; // Increment answer
                }
                out.println(ans); // Output the answer
            }
        }
        
        out.flush(); // Flush the output
    }
    
    // Constants for limits and modulo
    private static int INF = (int) 1e8;
    private static long INFL = (long) 1e17;
    private static long e97 = (long) 1e9 + 7;
    
    // Assertion method for debugging
    void assertion(boolean b) {
        if (!b) throw new AssertionError();
    }

    // Absolute value methods for different data types
    private static int abs(int a) {
        return (a >= 0) ? a : -a;
    }
    private static long abs(long a) {
        return (a >= 0) ? a : -a;
    }
    private static double abs(double a) {
        return (a >= 0) ? a : -a;
    }
    
    // Min methods for different data types
    private static int min(int a, int b) {
        return (a > b) ? b : a;
    }
    private static long min(long a, long b) {
        return (a > b) ? b : a;
    }
    private static double min(double a, double b) {
        return (a > b) ? b : a;
    }
    
    // Max methods for different data types
    private static int max(int a, int b) {
        return (a > b) ? a : b;
    }
    private static long max(long a, long b) {
        return (a > b) ? a : b;
    }
    private static double max(double a, double b) {
        return (a > b) ? a : b;
    }
    
    // Min and max methods for arrays
    private static int minN(int... ins) {
        int min = ins[0];
        for (int i = 1; i < ins.length; i++) {
            if (ins[i] < min) min = ins[i];
        }
        return min;
    }
    private static int maxN(int... ins) {
        int max = ins[0];
        for (int i = 1; i < ins.length; i++) {
            if (ins[i] > max) max = ins[i];
        }
        return max;
    }
    private static long minN(long... ins) {
        long min = ins[0];
        for (int i = 1; i < ins.length; i++) {
            if (ins[i] < min) min = ins[i];
        }
        return min;
    }
    private static long maxN(long... ins) {
        long max = ins[0];
        for (int i = 1; i < ins.length; i++) {
            if (ins[i] > max) max = ins[i];
        }
        return max;
    }
    
    // Methods to find minimum excluding a specific index or value
    private static int minExAd(int[] dt, int ad) {
        int min = INF;
        for (int i = 0; i < dt.length; i++) {
            if ((i != ad) && (dt[i] < min)) min = dt[i];
        }
        return min;
    }
    private static long minExAd(long[] dt, int ad) {
        long min = INFL;
        for (int i = 0; i < dt.length; i++) {
            if ((i != ad) && (dt[i] < min)) min = dt[i];
        }
        return min;
    }
    private static int minExVal(int[] dt, int ex_val) {
        int min = INF;
        for (int i = 0; i < dt.length; i++) {
            if ((dt[i] != ex_val) && (dt[i] < min)) min = dt[i];
        }
        return min;
    }
    private static long minExVal(long[] dt, long ex_val) {
        long min = INFL;
        for (int i = 0; i < dt.length; i++) {
            if ((dt[i] != ex_val) && (dt[i] < min)) min = dt[i];
        }
        return min;
    }
    private static int maxExAd(int[] dt, int ad) {
        int max = -INF;
        for (int i = 0; i < dt.length; i++) {
            if ((i != ad) && (dt[i] > max)) max = dt[i];
        }
        return max;
    }
    private static long maxExAd(long[] dt, int ad) {
        long max = -INFL;
        for (int i = 0; i < dt.length; i++) {
            if ((i != ad) && (dt[i] > max)) max = dt[i];
        }
        return max;
    }
    private static int maxExVal(int[] dt, int ex_val) {
        int max = -INF;
        for (int i = 0; i < dt.length; i++) {
            if ((dt[i] != ex_val) && (dt[i] > max)) max = dt[i];
        }
        return max;
    }
    private static long maxExVal(long[] dt, long ex_val) {
        long max = -INFL;
        for (int i = 0; i < dt.length; i++) {
            if ((dt[i] != ex_val) && (dt[i] > max)) max = dt[i];
        }
        return max;
    }

    // Sum methods for arrays and lists
    private static int sumA(int[] dt) {
        int sum = 0;
        for (int e : dt) {
            sum += e;
        }
        return sum;
    }
    private static long sumA(long[] dt) {
        long sum = 0;
        for (long e : dt) {
            sum += e;
        }
        return sum;
    }
    private static int sumA(List<Integer> dt) {
        int sum = 0;
        for (long e : dt) {
            sum += e;
        }
        return sum;
    }
    
    // Methods for checking equality and triangle inequality
    private static boolean same3(long a, long b, long c) {
        if (a != b) return false;
        if (b != c) return false;
        if (c != a) return false;
        return true;
    }
    private static boolean dif3(long a, long b, long c) {
        if (a == b) return false;
        if (b == c) return false;
        if (c == a) return false;
        return true;
    }
    private static boolean triangle_inequality(int a, int b, int c) {
        if ((a + b) < c) return false;
        if ((b + c) < a) return false;
        if ((c + a) < b) return false;
        return true;
    }
    
    // Method to calculate the hypotenuse
    private static double hypod(double a, double b) {
        return Math.sqrt(a * a + b * b);
    }
    
    // Factorial methods
    private static long factorial(int n) {
        long ans = 1;
        for (long i = n; i > 0; i--) {
            ans *= i;
        }
        return ans;
    }
    
    // Factorial with modulo
    private static long facP(int n, long p) {
        long ans = 1;
        for (long i = n; i > 0; i--) {
            ans *= i;
            ans %= p;
        }
        return ans;
    }
    
    // Least common multiple
    private static long lcm(long m, long n) {
        long ans = m / gcd(m, n);
        ans *= n;
        return ans;
    }
    
    // Greatest common divisor
    private static long gcd(long m, long n) {
        if (m < n) return gcd(n, m);
        if (n == 0) return m;
        return gcd(n, m % n);
    }
    
    // Prime number check
    private static boolean is_prime(long a) {
        if (a == 1) return false;
        for (long i = 2L; i <= Math.sqrt(a); i++) {
            if (a % i == 0) return false;
        }
        return true;
    }
    
    // Modular inverse
    private static long modinv(long a, long p) { // a|p, >1に注意
        long b = p, u = 1L, v = 0L;
        while (b > 0) {
            long t = a / b;
            long pe = a % b;
            a = b; b = pe;
            pe = u - t * v;
            u = v; v = pe;
        }
        u %= p; 
        if (u < 0) u += p;
        return u;
    }
    
    // Power methods
    private static int pow(int n, int k) {
        int ans = 1;
        for (int i = 0; i < k; i++) ans *= n;
        return ans;
    }
    private static long pow(long n, int k) {
        long ans = 1;
        for (int i = 0; i < k; i++) ans *= n;
        return ans;
    }
    
    // Square methods
    private static int pow2(int in) {
        return in * in;
    }
    private static long pow2(long in) {
        return in * in;
    }
    private static double pow2(double in) {
        return in * in;
    }
    
    // Get number of digits in binary and decimal
    private static int getDigit2(long num) {
        long cf = 1; int d = 0;
        while (num >= cf) {
            d++;
            cf = (1L << d);
        }
        return d; // numはd桁の数で、2^dより小さい
    }
    
    private static int getDigit10(long num) {
        long cf = 1; int d = 0;
        while (num >= cf) {
            d++;
            cf *= 10;
        }
        return d; // numはd桁の数で、10^dより小さい
    }
    
    // Check for overflow
    private static boolean isINF(int in) {
        if (((long) in * 20) > INF) return true;
        else return false;
    }
    private static boolean isINFL(long in) {
        if ((in * 10000) > INFL) return true;
        else return false;
    }
    
    // Power of 10 with exponentiation
    private static long pow10E97(long ob, long soeji, long p) {
        if (ob == 0) return 0;
        if (soeji == 0) return 1;
        if (soeji == 2) return (ob * ob) % p;
        
        int d = getDigit2(soeji);
        long[] ob_pow_2pow = new long[d];
        
        ob_pow_2pow[0] = ob;
        for (int i = 1; i < d; i++) {
            ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;
        }
        
        long ans = 1;
        for (int i = d - 1; i >= 0; i--) {
            if (soeji >= (long) (1 << i)) {
                soeji -= (long) (1 << i);
                ans = (ans * ob_pow_2pow[i]) % p;
            }
        }
        return ans % p;
    }
    
    // Bit manipulation methods
    private static long flag(long pos) {
        return (1L << pos);
    }
    private static boolean isFlaged(int bit, int pos) {
        return (bit & (1 << pos)) > 0;
    }
    private static boolean isFlaged(long bit, int pos) {
        return (bit & (1L << pos)) > 0;
    }
    private static int deflag(int bit, int pos) {
        return bit & ~(1 << pos);
    }
    private static int countFlaged(int bit) {
        int ans = 0; 
        for (int i = 0; i < getDigit2(bit); i++) {
            if ((bit & (1 << i)) > 0) ans++;
        }
        return ans;
    }
    private static int countFlaged(long bit) {
        int ans = 0; 
        for (long i = 0; i < getDigit2(bit); i++) {
            if ((bit & (1L << i)) > 0) ans++;
        }
        return ans;
    }
    
    // Show flags in a binary representation
    private static void showflag(int bit) {
        for (int i = 0; i < getDigit2(bit); i++) {
            if (isFlaged(bit, i)) System.out.print("O");
            else System.out.print(".");
        }
        System.out.println();
    }
    
    // Binary search methods
    public static int biSearch(int[] dt, int target) {
        int left = 0, right = dt.length - 1;
        int mid = -1;
        while (left <= right) {
            mid = (right + left) / 2;
            if (dt[mid] == target) return mid; // Found target
            if (dt[mid] < target) left = mid + 1; // Search right
            else right = mid - 1; // Search left
        }
        return -1; // Target not found
    }
    
    public static int biSearchMax(long[] dt, long target) {
        int left = -1, right = dt.length;
        int mid = -1;
        
        while ((right - left) > 1) {
            mid = left + (right - left) / 2;
            if (dt[mid] <= target) left = mid; // Search right
            else right = mid; // Search left
        }
        return left; // Return the largest index less than or equal to target
    }
    
    public static int biSearchMaxAL(ArrayList<Integer> dt, long target) {
        int left = -1, right = dt.size();
        int mid = -1;
        
        while ((right - left) > 1) {
            mid = left + (right - left) / 2;
            if (dt.get(mid) <= target) left = mid; // Search right
            else right = mid; // Search left
        }
        return left; // Return the largest index less than or equal to target
    }
    
    // Union-Find methods
    private static void fill_parent(int[] ob) {
        for (int i = 0; i < ob.length; i++) ob[i] = i; // Initialize parent array
    }
    
    private static int get_root_uf(int[] parent, int index) {
        if (parent[index] == index) return index; // Return root if it is its own parent
        int root = get_root_uf(parent, parent[index]); // Recursively find root
        parent[index] = root; // Path compression
        return root;
    }
    
    private static boolean is_same_uf(int[] parent, int x, int y) {
        return get_root_uf(parent, x) == get_root_uf(parent, y); // Check if x and y are in the same set
    }
    
    private static void unite_uf(int[] parent, int receiver, int attacker) {
        parent[get_root_uf(parent, attacker)] = get_root_uf(parent, receiver); // Union operation
    }
    
    // Direction arrays for 4 and 8 directions
    private static int[] Xdir4 = {1, 0, 0, -1};
    private static int[] Ydir4 = {0, 1, -1, 0};
    
    private static int[] Xdir8 = {1, 1, 1, 0, 0, -1, -1, -1};
    private static int[] Ydir8 = {1, 0, -1, 1, -1, 1, 0, -1};
    
    // Check if coordinates are within a given area
    private static boolean is_in_area(int y, int x, int h, int w) {
        return !(y < 0 || x < 0 || y >= h || x >= w); // Return true if within bounds
    }
    
    // Show 2D boolean array
    static void show2(boolean[][] dt, int lit_x, int lit_y) {
        PrintWriter out = new PrintWriter(System.out);
        for (int j = 0; j < dt.length; j++) {
            for (int i = 0; i < dt[j].length; i++) {
                if ((i == lit_y) && (j == lit_x)) out.print("X"); // Mark the lit position
                else if (dt[j][i]) out.print("O"); // Mark true positions
                else out.print("."); // Mark false positions
            }
            out.println();
        }
        out.flush();
    }
    
    // Show 2D integer array with comments
    static void show2(int[][] dt, String cmnt) {
        PrintWriter out = new PrintWriter(System.out);
        for (int i = 0; i < dt.length; i++) {
            for (int j = 0; j < dt[i].length; j++) {
                out.print(dt[i][j] + ","); // Print each element
            }
            out.println("<-" + cmnt + ":" + i); // Print comment for the row
        }
        out.flush();
    }
    
    // Show 2D long array with comments
    static void show2(long[][] dt, String cmnt) {
        PrintWriter out = new PrintWriter(System.out);
        for (int i = 0; i < dt.length; i++) {
            for (int j = 0; j < dt[i].length; j++) {
                out.print(dt[i][j] + ","); // Print each element
            }
            out.println("<-" + cmnt + ":" + i); // Print comment for the row
        }
        out.flush();
    }
    
    // Display queue for debugging
    static void disp_que(ArrayDeque<Long> dt) {
        long a = 0;
        while (dt.size() > 0) {
            a = dt.removeFirst(); // Remove and print each element
            System.out.print(a);
        }
        System.out.println("\n");
    }
    
    // Display list for debugging
    static void disp_list(List dt) {
        for (int i = 0; i < dt.size(); i++) {
            System.out.print(dt.get(i) + ","); // Print each element
        }
        System.out.println("\n");
    }
    
    // Print array of integers
    private static void prtlnas(int[] as) {
        PrintWriter out = new PrintWriter(System.out);
        for (int i = 0; i < as.length; i++) {
            out.println(as[i]); // Print each element
        }
        out.flush();
    }
    
    // Print array of longs
    private static void prtlnas(long[] as) {
        PrintWriter out = new PrintWriter(System.out);
        for (int i = 0; i < as.length; i++) {
            out.println(as[i]); // Print each element
        }
        out.flush();
    }
    
    // Print space-separated integers
    private static void prtspas(int[] as) {
        PrintWriter out = new PrintWriter(System.out);
        out.print(as[0]); // Print first element
        for (int i = 1; i < as.length; i++) {
            out.print(" " + as[i]); // Print subsequent elements
        }
        out.println();
        out.flush();
    }
    
    // Print space-separated longs
    private static void prtspas(long[] as) {
        PrintWriter out = new PrintWriter(System.out);
        out.print(as[0]); // Print first element
        for (int i = 1; i < as.length; i++) {
            out.print(" " + as[i]); // Print subsequent elements
        }
        out.println();
        out.flush();
    }
    
    // Print space-separated list elements
    private static void prtspas(List as) {
        PrintWriter out = new PrintWriter(System.out);
        out.print(as.get(0)); // Print first element
        for (int i = 1; i < as.size(); i++) {
            out.print(" " + as.get(i)); // Print subsequent elements
        }
        out.println();
        out.flush();
    }
    
    // Fill methods for different data types
    private static void fill(boolean[] ob, boolean res) {
        for (int i = 0; i < ob.length; i++) {
            ob[i] = res; // Fill array with specified value
        }
    }
    private static void fill(int[] ob, int res) {
        for (int i = 0; i < ob.length; i++) {
            ob[i] = res; // Fill array with specified value
        }
    }
    private static void fill(long[] ob, long res) {
        for (int i = 0; i < ob.length; i++) {
            ob[i] = res; // Fill array with specified value
        }
    }
    private static void fill(char[] ob, char res) {
        for (int i = 0; i < ob.length; i++) {
            ob[i] = res; // Fill array with specified value
        }
    }
    private static void fill(double[] ob, double res) {
        for (int i = 0; i < ob.length; i++) {
            ob[i] = res; // Fill array with specified value
        }
    }
    private static void fill(boolean[][] ob, boolean res) {
        for (int i = 0; i < ob.length; i++) {
            for (int j = 0; j < ob[0].length; j++) {
                ob[i][j] = res; // Fill 2D array with specified value
            }
        }
    }
    private static void fill(int[][] ob, int res) {
        for (int i = 0; i < ob.length; i++) {
            for (int j = 0; j < ob[0].length; j++) {
                ob[i][j] = res; // Fill 2D array with specified value
            }
        }
    }
    private static void fill(long[][] ob, long res) {
        for (int i = 0; i < ob.length; i++) {
            for (int j = 0; j < ob[0].length; j++) {
                ob[i][j] = res; // Fill 2D array with specified value
            }
        }
    }
    private static void fill(char[][] ob, char res) {
        for (int i = 0; i < ob.length; i++) {
            for (int j = 0; j < ob[0].length; j++) {
                ob[i][j] = res; // Fill 2D array with specified value
            }
        }
    }
    private static void fill(double[][] ob, double res) {
        for (int i = 0; i < ob.length; i++) {
            for (int j = 0; j < ob[0].length; j++) {
                ob[i][j] = res; // Fill 2D array with specified value
            }
        }
    }
    private static void fill(int[][][] ob, int res) {
        for (int i = 0; i < ob.length; i++) {
            for (int j = 0; j < ob[0].length; j++) {
                for (int k = 0; k < ob[0][0].length; k++) {
                    ob[i][j][k] = res; // Fill 3D array with specified value
                }
            }
        }
    }
    private static void fill(long[][][] ob, long res) {
        for (int i = 0; i < ob.length; i++) {
            for (int j = 0; j < ob[0].length; j++) {
                for (int k = 0; k < ob[0][0].length; k++) {
                    ob[i][j][k] = res; // Fill 3D array with specified value
                }
            }
        }
    }
    
    // FastScanner class for efficient input reading
    static class FastScanner {
        private final InputStream in = System.in; // Input stream
        private final byte[] buffer = new byte[1024]; // Buffer for reading
        private int ptr = 0; // Pointer for buffer
        private int buflen = 0; // Length of buffer
        
        // Check if there is a next byte to read
        private boolean hasNextByte() {
            if (ptr < buflen) {
                return true; // Bytes available in buffer
            } else {
                ptr = 0; // Reset pointer
                try {
                    buflen = in.read(buffer); // Read into buffer
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (buflen <= 0) {
                    return false; // No more bytes
                }
            }
            return true; // Bytes available
        }
        
        // Read a byte from the buffer
        private int readByte() {
            if (hasNextByte()) return buffer[ptr++]; // Return byte and increment pointer
            else return -1; // No more bytes
        }
        
        // Check if a character is printable
        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126; // ASCII printable range
        }
        
        // Check if there is a next printable character
        public boolean hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; // Skip non-printable characters
            return hasNextByte(); // Check for next byte
        }
        
        // Read the next string
        public String next() {
            if (!hasNext()) throw new NoSuchElementException(); // No more elements
            StringBuilder sb = new StringBuilder(); // StringBuilder for constructing string
            int b = readByte(); // Read first byte
            while (isPrintableChar(b)) { // While character is printable
                sb.appendCodePoint(b); // Append character to string
                b = readByte(); // Read next byte
            }
            return sb.toString(); // Return constructed string
        }
        
        // Read the next long integer
        public long nexL() {
            if (!hasNext()) throw new NoSuchElementException(); // No more elements
            long n = 0; // Initialize number
            boolean minus = false; // Flag for negative numbers
            int b = readByte(); // Read first byte
            if (b == '-') { // Check for negative sign
                minus = true; // Set flag
                b = readByte(); // Read next byte
            }
            if (b < '0' || '9' < b) { // Check if character is a digit
                throw new NumberFormatException(); // Invalid number format
            }
            while (true) {
                if ('0' <= b && b <= '9') { // If character is a digit
                    n *= 10; // Shift left
                    n += b - '0';