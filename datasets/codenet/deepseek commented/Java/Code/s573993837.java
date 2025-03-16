
   // Importing necessary packages for input/output, utility operations, and mathematical operations
   import java.io.*;
   import java.util.*;
   import java.lang.*;
   import java.math.BigInteger; 
   


   // Main method to execute the program
   public static void main(String[] args) {
      // Initialize input and output streams
      InputStream inputStream = System.in;
      OutputStream outputStream = System.out;
      // Create InputReader and PrintWriter instances
      InputReader in = new InputReader(inputStream);
      PrintWriter out = new PrintWriter(outputStream);
      // Call the solve method and close the PrintWriter
      solve(in, out);
      out.close();
   }
   


   // Declaring static variables for later use
   static int L, R, top, bottom;
   // Declaring a static variable 'ans' which is not used in the code
   // static int ans;
   


   // Main logic of the program, executed for each test case
   public static void solve(InputReader sc, PrintWriter pw) {
      // Read the number of test cases (though it's always 1 in this case)
      int t = sc.nextInt();
      // Loop through each test case
      u: while (t-- > 0) {
         // Read two long integers n and m
         long n = sc.nextLong();
         long m = sc.nextLong();
         // If n is 0, print 0 and continue to the next iteration of the loop
         if (n == 0) {
               pw.println(0);
               continue u;
         }
         // If n is equal to m, print 0 and continue to the next iteration of the loop
         if (n == m) {
               pw.println(0);
               continue u;
         }
         // If n is greater than m, adjust n and print the minimum difference
         if (n > m) {
               n = m + n % m;
               n -= m;
               pw.println(Math.min(m - n, n));
               continue u;
         }
         // Otherwise, print the minimum difference between m and n
         pw.println(Math.min(m - n, n));
      }
   }
   


   // Method to swap two elements in a character array
   public static void swap(char[] chrr, int i, int j) {
      char temp = chrr[i];
      chrr[i] = chrr[j];
      chrr[j] = temp;
   }
   // Method to count the number of 1s in the binary representation of an integer
   public static int num(int n) {
      int a = 0;
      while (n > 0) {
         a += (n & 1);
         n >>= 1;
      }
      return a;
   }
   // Class to store pairs of integers and an index
   static class Pair {
      int u, v, i;
      Pair(int a, int b, int i) {
         this.u = a;
         this.v = b;
         this.i = i;
      }
   }
   // Method to check if a number is prime
   static boolean isPrime(int n) {
      if (n <= 1) return false;
      if (n <= 3) return true;
      if (n % 2 == 0 || n % 3 == 0) return false;
      for (int i = 5; i * i <= n; i = i + 6)
         if (n % i == 0 || n % (i + 2) == 0)
               return false;
      return true;
   }
   // Method to calculate the greatest common divisor
   static long gcd(long a, long b) {
      if (b == 0) return a;
      return a > b ? gcd(b, a % b) : gcd(a, b % a);
   }
   // Method to calculate power with fast exponentiation
   static long fast_pow(long base, long n, long M) {
      if (n == 0) return 1;
      if (n == 1) return base;
      long halfn = fast_pow(base, n / 2, M);
      if (n % 2 == 0) return (halfn * halfn) % M;
      else return (((halfn * halfn) % M) * base) % M;
   }
   // Method to calculate modular inverse using Fermat's little theorem
   static long modInverse(long n, long M) {
      return fast_pow(n, M - 2, M);
   }
   // Method to fill an array with long values from input
   public static void feedArr(long[] arr, InputReader sc) {
      for (int i = 0; i < arr.length; i++)
         arr[i] = sc.nextLong();
   }
   // Method to fill an array with double values from input
   public static void feedArr(double[] arr, InputReader sc) {
      for (int i = 0; i < arr.length; i++)
         arr[i] = sc.nextDouble();
   }
   // Method to fill an array with int values from input
   public static void feedArr(int[] arr, InputReader sc) {
      for (int i = 0; i < arr.length; i++)
         arr[i] = sc.nextInt();
   }
   // Method to fill an array with String values from input
   public static void feedArr(String[] arr, InputReader sc) {
      for (int i = 0; i < arr.length; i++)
         arr[i] = sc.next();
   }
   // Method to print an array of integers
   public static String printArr(int[] arr) {
      StringBuilder sbr = new StringBuilder();
      for (int i : arr)
         sbr.append(i + " ");
      return sbr.toString();
   }
   // Method to print an array of long values
   public static String printArr(long[] arr) {
      StringBuilder sbr = new StringBuilder();
      for (long i : arr)
         sbr.append(i + " ");
      return sbr.toString();
   }
   // Method to print an array of Strings
   public static String printArr(String[] arr) {
      StringBuilder sbr = new StringBuilder();
      for (String i : arr)
         sbr.append(i + " ");
      return sbr.toString();
   }
   // Method to print an array of double values
   public static String printArr(double[] arr) {
      StringBuilder sbr = new StringBuilder();
      for (double i : arr)
         sbr.append(i + " ");
      return sbr.toString();
   }
   


   // Nested class to read input efficiently
   static class InputReader {
      public BufferedReader reader;
      public StringTokenizer tokenizer;
      public InputReader(InputStream stream) {
         reader = new BufferedReader(new InputStreamReader(stream), 32768);
         tokenizer = null;
      }
      public String next() {
         while (tokenizer == null || !tokenizer.hasMoreTokens()) {
               try {
                  tokenizer = new StringTokenizer(reader.readLine());
               } catch (IOException e) {
                  throw new RuntimeException(e);
               }
         }
         return tokenizer.nextToken();
      }
      public int nextInt() {
         return Integer.parseInt(next());
      }
      public long nextLong() {
         return Long.parseLong(next());
      }
      public double nextDouble() {
         return Double.parseDouble(next());
      }
   }
   

