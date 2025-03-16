
import java.util.*;
import java.io.*;

public class Main {
    public static final long MOD = 1000000007; // constant value for modulo arithmetic

    public static void main(String[] args) { // main method to start the program
        FastScanner sc = new FastScanner(); // create a FastScanner object to read input
        PrintWriter out = new PrintWriter(System.out); // create a PrintWriter object to write output

        Integer i, j, k, n = 0, m = 0, h = 0, w = 0, ans = 0; // initialize variables with default values
        long a = 0, b = 0, c = 0, d = 0, x = 0, y = 0, z = 0; // initialize long variables with default values
        List<Integer> l = new ArrayList<>(); // create an empty ArrayList to store integers
        List<String> s = new ArrayList<>(); // create an empty ArrayList to store strings
        List<Pair> p = new ArrayList<>(); // create an empty ArrayList to store Pair objects

        n = sc.nextInt(); // read the first integer from the input

        for (i = 0; i < n; i++) { // loop through the input integers and add them to the ArrayList
            l.add(sc.nextInt());
        }

        Collections.sort(l); // sort the ArrayList in ascending order

        // calculate and print the middle element or the average of the middle two elements
        if (n % 2 == 0) { // if the number of elements is even
            print(l.get(n / 2) - l.get(n / 2 - 1)); // print the difference between the middle two elements
        } else { // if the number of elements is odd
            print(l.get(n / 2)); // print the middle element
        }

        out.flush(); // flush the PrintWriter buffer to write the output to the console
    }

    private static void print(Object o) { // method to print an object to the console
        System.out.println(o.toString()); // convert the object to a string and print it to the console
    }

    private static long lcm(long m, long n) { // method to calculate the least common multiple of two numbers
        return m * n / gcd(m, n); // calculate the greatest common divisor first and then use it to find the LCM
    }

    private static long gcd(long m, long n) { // method to calculate the greatest common divisor of two numbers
        if (m < n) return gcd(n, m); // swap m and n if m is smaller than n
        if (n == 0) return m; // n is 0, so m is the GCD

        return gcd(n, m % n); // recursively calculate the GCD of n and the remainder of m divided by n
    }

    private static class Pair { // define a class to store a key-value pair
        private int key;
        private int value;

        public Pair(int key, int value) { // constructor to initialize a new Pair object
            this.key = key;
            this.value = value;
        }

        public int getValue() { // method to get the value of the Pair
            return this.value;
        }

        public int getKey() { // method to get the key of the Pair
            return this.key;
        }
    }
}

class FastScanner { // define a FastScanner class to read input more efficiently
    private final InputStream in;
    private final byte[] buffer;
    private int ptr;
    private int buflen;
    private boolean hasNextByte() { // check if there is a next byte to read
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { // read a byte from the input buffer
        if (hasNextByte()) return buffer[ptr++]; // if there is a next byte, read it and increment the pointer
        else return -1; // if there is no next byte, return -1
    }
    private static boolean isPrintableChar(int c) { // check if a character is printable
        return 33 <= c && c <= 126;
    }
    public boolean hasNext() { // check if there is a next token to read
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; // skip non-printable characters
        return hasNextByte(); // return true if there is a next byte, false otherwise
    }
    public String next() { // read a token as a String
        if (!hasNext()) throw new NoSuchElementException(); // throw an exception if there is no next token
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) { // read printable characters and add them to the StringBuilder
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() { // read a long integer
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') { // if the first character is a '-', set the minus flag and read the next character
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) { // if the character is not a digit, throw an exception
            throw new NumberFormatException();
        }
        while (true) { // read digits and add them to the long variable
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1) { // if there is no next character, return the number
                return minus ? -n : n;
            } else { // if the character is not a digit, throw an exception
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() { // read an integer
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException(); // check if the number is within the range of an integer
        return (int) nl; // convert the long number to an integer and return it
    }
    public double nextDouble() { // read a double number
        return Double.parseDouble(next()); // parse the next token as a String and convert it to a double
    }
}