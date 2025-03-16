import java.io.*;
import java.util.*;

public class Main {
    // Declaring static variables and initializing Scanner and PrintWriter
    static PrintWriter pw;
    static Scanner sc;
    static ArrayList<Integer>[] adj;
    static boolean[] visit;
    static HashMap<Pair, Integer> dp;
    static long ceildiv(long x, long y) { return (x+y-1)/y; } // Ceiling division function
    static int mod(long x, int m) { return (int)((x%m+m)%m); } // Modulo function
    static HashMap<Integer, Integer> map; // HashMap to store frequency of numbers
    static long gcd(long x, long y) {return y==0?x:gcd(y, x%y);} // GCD function
    static int Int(boolean x){ return x?1:0; } // Function to convert boolean to integer
    static void put(TreeMap<Pair, Integer> map, Pair p){ // Function to put pair in TreeMap
        if(map.containsKey(p))
            map.replace(p, map.get(p)+1);
        else
            map.put(p, 1);
    }
    static void rem(TreeMap<Pair, Integer> map, Pair p){ // Function to remove pair from TreeMap
        if(map.get(p)==1)
            map.remove(p);
        else
            map.replace(p, map.get(p)-1);
    }

    public static void main(String[] args) throws Exception {
        // Initializing Scanner and PrintWriter
        sc = new Scanner(System.in);
        pw=new PrintWriter(System.out);

        // Reading input number of integers n
        int n=sc.nextInt();

        // Reading and sorting input integers in descending order
        Integer[] arr=sc.nextsort(n);

        // Checking if the number of integers is greater than or equal to 3
        if(n>=3){
            // Creating an empty TreeMap to store pairs
            TreeMap<Pair, Integer> map=new TreeMap<>(Collections.reverseOrder());

            // Initializing variables ans and pair p1 and p2
            long ans=arr[0]+arr[1];
            Pair p1=new Pair(arr[0], arr[1]), p2=new Pair(arr[2], arr[1]);

            // Putting pair p1 and p2 in the TreeMap and incrementing their frequency
            put(map, p1); put(map, p2);

            // Iterating through the remaining integers starting from the third integer
            for(int i=3; i<n; i++){
                // Getting the first pair from the TreeMap
                Pair p=map.firstKey();

                // Removing the pair from the TreeMap
                rem(map, p);

                // Updating the answer by adding the minimum of the two numbers in the pair
                ans+=Math.min(p.x, p.y);

                // Putting new pairs (p.x, arr[i]) and (p.y, arr[i]) in the TreeMap and incrementing their frequency
                put(map, new Pair(p.x, arr[i])); put(map, new Pair(p.y, arr[i]));
            }

            // Printing the answer
            pw.println(ans);
        }else{
            // If the number of integers is less than 3, printing the first integer
            pw.println(arr[0]);
        }

        // Closing the PrintWriter
        pw.close();
    }

    // Helper functions
    static void fill(int[] arr, int x){ // Function to fill an array with binary representation of a number
        for(int i=0; i<30; i++)
            arr[i]+=Int(((1<<i)&x)!=0);
    }

    static long pow(long a, long pow){ // Function to calculate a raised to the power of pow
        long ans=1;
        while(pow>0){
            if((pow&1)==1)
                ans*=a;
            a*=a;
            pow>>=1;
        }
        return ans;
    }

    static int getpow(int x) throws Exception{ // Function to calculate log base 2 of a number
        int pow=x;
        pw.println("B "+pow); // Sending the number to an external program to calculate log base 2
        pw.flush(); // Flushing the PrintWriter to send the command
        if(sc.nextInt()==1){ // Checking if the answer is 1, meaning the number is a power of 2
            pow*=x; // Multiplying the number with itself if it is a power of 2
            while(true){ // Recursively calculating log base 2 until the number is not a power of 2 anymore
                pw.println("B "+pow); // Sending the number to the external program
                pw.flush();
                if(sc.nextInt()==0)
                    return pow/x; // Returning the log base 2 if the answer is not 1
                pow*=x; // Multiplying the number with itself if it is a power of 2
            }
        }else{
            return 1; // Returning 1 if the number is not a power of 2
        }
    }

    static int[] least; // Array to store the smallest prime factor of each number
    static TreeSet<Integer> prime; // TreeSet to store prime numbers

    static void linearsieve(int x){ // Linear Sieve of Eratosthenes algorithm to find prime numbers up to x
        least=new int[x+1]; // Initializing the least array
        prime=new TreeSet<Integer>(); // Initializing the prime TreeSet
        for(int i=2; i<=x; i++){
            if(least[i]==0){ // If i is not marked as prime yet
                least[i]=i; // Marking i as prime
                prime.add(i); // Adding i to the prime TreeSet
            }
            for(int y :prime) { // Iterating through all prime numbers less than the square root of i
                if(i*y<=x) // If the product of i and y is less than or equal to x
                    least[i*y]=y; // Marking i*y as a multiple of y
                else break; // Breaking the loop if i*y is greater than x
            }
        }
    }

    static void printArr(int[] arr) { // Function to print an integer array
        for (int i = 0; i < arr.length - 1; i++)
            pw.print(arr[i] + " ");
        pw.println(arr[arr.length - 1]);
    }

    static void printArr(long[] arr) { // Function to print a long array
        for (int i = 0; i < arr.length - 1; i++)
            pw.print(arr[i] + " ");
        pw.println(arr[arr.length - 1]);
    }

    static void printArr(Integer[] arr) { // Function to print an Integer array
        for (int i = 0; i < arr.length; i++)
            pw.print(arr[i]+" ");
        pw.println();
    }

    static void printArr(char[] arr) { // Function to print a character array
        for (int i = 0; i < arr.length; i++)
            pw.print(arr[i]==0? '1': arr[i]);
        pw.println();
    }

    static void printArr(ArrayList<Integer> list) { // Function to print an ArrayList of integers
        for (int i = 0; i < list.size(); i++)
            pw.print(list.get(i)+" ");
        pw.println();
    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        // Constructor for Scanner class
        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        // Function to read the next token from the input stream
        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        // Function to read an integer from the input stream
        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        // Function to read a long from the input stream
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        // Function to read a line from the input stream
        public String nextLine() throws IOException {
            return br.readLine();
        }

        // Function to read a double from the input stream
        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        // Function to read an integer array of size n from the input stream
        public int[] nextArr(int n) throws IOException{
            int[] arr = new int[n];
            for (int i = 0; i < arr.length; i++)
                arr[i] = nextInt();
            return arr;
        }
        public Integer[] nextsort(int n) throws IOException{
            Integer[] arr=new Integer[n];
            for(int i=0; i<n; i++)
                arr[i]=nextInt();
            return arr;
        }
        public Pair nextPair() throws IOException{
            return new Pair(nextInt(), nextInt());
        }
        public Pair[] nextPairArr(int n) throws IOException{
            Pair[] arr=new Pair[n];
            for(int i=0; i<n; i++)
                arr[i]=nextPair();
            return arr;
        }
        public boolean ready() throws IOException {
            return br.ready();
        }
    }

    static class Pair implements Comparable<Pair>{
        int x;
        int y;

        // Constructor for Pair class
        public Pair(int x, int y) {
            this.x=x;
            this.y=y;
        }

        // Overriding the hashCode method
        public int hashCode() {
            return (this.x*1000+this.y);
        }

        // Overriding the compareTo method
        public int compareTo(Pair p){
            int min1=Math.min(x, y), min2=Math.min(p.x, p.y);
            if(min1!=min2)
                return min1-min2;
            if(x==p.x)
                return y-p.y;
            return x-p.x;
        }

        // Overriding the equals method
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }
            if (this.getClass() != obj.getClass()) {
                return false;
            }
            Pair p = (Pair) obj;
            return this.x==p.x && this.y==p.y;
        }

        // Overriding the clone method
        public Pair clone(){
            return new Pair(x, y);
        }

        // Overriding the toString method
        public String toString(){
            return this.x+" "+this.y;
        }

        // Overloading the addition operator
        public void add(Pair p){
            x+=p.x;
            