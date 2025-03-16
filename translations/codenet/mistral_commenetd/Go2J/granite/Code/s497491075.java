
// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

public class s497491075{
    public static void main(String[] args) throws Exception {
        // Create a new scanner object to read input lines
        Scanner sc = new Scanner(System.in);

        // Read the first line of input containing two integers N and D
        int[] a = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int N = a[0], D = a[1];

        // Read N lines of input and store them in a list called lines
        List<int[]> lines = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            // Read a single line of input and convert it to an array of integers
            lines.add(Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray());
        }

        // Initialize a counter variable count to 0
        int count = 0;

        // Iterate through each line in the lines list
        for (int[] line : lines) {
            // Calculate the Euclidean distance of the current line from the origin (0,0)
            double d = Math.sqrt(Math.pow(line[0], 2) + Math.pow(line[1], 2));

            // If the distance of the current line is less than or equal to D, increment the counter
            if (d <= D) {
                count++;
            }
        }

        // Write the final result to the output stream
        System.out.println(count);
    }
}

// Scanner class to read input lines
class Scanner {
    BufferedReader br;
    StringTokenizer st;

    public Scanner(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in));
        eat("");
    }

    private void eat(String s) {
        st = new StringTokenizer(s);
    }

    public String nextLine() throws IOException {
        return br.readLine();
    }

    public boolean hasNextLine() throws IOException {
        return br.ready();
    }

    public String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String s = nextLine();
            if (s == null) return null;
            eat(s);
        }
        return st.nextToken();
    }

    public boolean hasNext() throws IOException {
        while (!st.hasMoreTokens()) {
            String s = nextLine();
            if (s == null) return false;
            eat(s);
        }
        return true;
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}

// Add comments for each logical block
// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

public class s497491075{
    public static void main(String[] args) throws Exception {
        // Create a new scanner object to read input lines
        Scanner sc = new Scanner(System.in);

        // Read the first line of input containing two integers N and D
        int[] a = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int N = a[0], D = a[1]; // N is the number of lines, D is the side length of the square

        // Read N lines of input and store them in a list called lines
        List<int[]> lines = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            // Read a single line of input and convert it to an array of integers
            lines.add(Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray());
        }

        // Initialize a counter variable count to 0
        int count = 0;

        // Iterate through each line in the lines list
        for (int[] line : lines) {
            // Calculate the Euclidean distance of the current line from the origin (0,0)
            double d = Math.sqrt(Math.pow(line[0], 2) + Math.pow(line[1], 2));

            // If the distance of the current line is less than or equal to D, increment the counter
            if (d <= D) {
                count++;
            }
        }

        // Write the final result to the output stream
        System.out.println(count);
    }
}

// Scanner class to read input lines
class Scanner {
    BufferedReader br;
    StringTokenizer st;

    public Scanner(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in));
        eat("");
    }

    private void eat(String s) {
        st = new StringTokenizer(s);
    }

    public String nextLine() throws IOException {
        return br.readLine();
    }

    public boolean hasNextLine() throws IOException {
        return br.ready();
    }

    public String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String s = nextLine();
            if (s == null) return null;
            eat(s);
        }
        return st.nextToken();
    }

    public boolean hasNext() throws IOException {
        while (!st.hasMoreTokens()) {
            String s = nextLine();
            if (s == null) return false;
            eat(s);
        }
        return true;
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}

// Add comments for each logical block
// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

public class s497491075{
    public static void main(String[] args) throws Exception {
        // Create a new scanner object to read input lines
        Scanner sc = new Scanner(System.in);

        // Read the first line of input containing two integers N and D
        int[] a = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int N = a[0], D = a[1]; // N is the number of lines, D is the side length of the square

        // Read N lines of input and store them in a list called lines
        List<int[]> lines = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            // Read a single line of input and convert it to an array of integers
            lines.add(Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray());
        }

        // Initialize a counter variable count to 0
        int count = 0;

        // Iterate through each line in the lines list
        for (int[] line : lines) {
            // Calculate the Euclidean distance of the current line from the origin (0,0)
            double d = Math.sqrt(Math.pow(line[0], 2) + Math.pow(line[1], 2));

            // If the distance of the current line is less than or equal to D, increment the counter
            if (d <= D) {
                count++;
            }
        }

        // Write the final result to the output stream
        System.out.println(count);
    }
}

// Scanner class to read input lines
class Scanner {
    BufferedReader br;
    StringTokenizer st;

    public Scanner(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in));
        eat("");
    }

    private void eat(String s) {
        st = new StringTokenizer(s);
    }

    public String nextLine() throws IOException {
        return br.readLine();
    }

    public boolean hasNextLine() throws IOException {
        return br.ready();
    }

    public String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String s = nextLine();
            if (s == null) return null;
            eat(s);
        }
        return st.nextToken();
    }

    public boolean hasNext() throws IOException {
        while (!st.hasMoreTokens()) {
            String s = nextLine();
            if (s == null) return false;
            eat(s);
        }
        return true;
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}

// Add comments for each logical block
// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

public class s497491075{
    public static void main(String[] args) throws Exception {
        // Create a new scanner object to read input lines
        Scanner sc = new Scanner(System.in);

        // Read the first line of input containing two integers N and D
        int[] a = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int N = a[0], D = a[1]; // N is the number of lines, D is the side length of the square

        // Read N lines of input and store them in a list called lines
        List<int[]> lines = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            // Read a single line of input and convert it to an array of integers
            lines.add(Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray());
        }

        // Initialize a counter variable count to 0
        int count = 0;

        // Iterate through each line in the lines list
        for (int[] line : lines) {
            // Calculate the Euclidean distance of the current line from the origin (0,0)
            double d = Math.sqrt(Math.pow(line[0], 2) + Math.pow(line[1], 2));

            // If the distance of the current line is less than or equal to D, increment the counter
            if (d <= D) {
                count++;
            }
        }

        // Write the final result to the output stream
        System.out.println(count);
    }
}

// Scanner class to read input lines
class Scanner {
    BufferedReader br;
    StringTokenizer st;

    public Scanner(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in));
        eat("");
    }

