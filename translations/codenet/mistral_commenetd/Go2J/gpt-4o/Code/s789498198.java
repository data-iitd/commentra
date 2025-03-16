import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        // Read the first two integers from the input
        String[] input = reader.readLine().split(" ");
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);

        // Check if the sum of A and B is even
        if ((A + B) % 2 == 0) {
            // If it is, print the result (the average)
            System.out.println((A + B) / 2);
        } else {
            // If the sum is odd, print "IMPOSSIBLE"
            System.out.println("IMPOSSIBLE");
        }
    }

    // Function to calculate the number of digits in an integer
    public static int digits(int x) {
        return String.valueOf(x).length();
    }

    // Function to calculate the power of a number
    public static int powInt(int x, int p) {
        int result = 1;
        for (int i = 0; i < p; i++) {
            result *= x;
        }
        return result;
    }

    // Function to find the maximum of two integers
    public static int max(int x, int y) {
        return Math.max(x, y);
    }

    // Function to find the minimum of two integers
    public static int min(int x, int y) {
        return Math.min(x, y);
    }

    // Function to calculate the absolute value of an integer
    public static int abs(int x) {
        return Math.abs(x);
    }

    // Function to print "Yes"
    public static void yes() {
        System.out.println("Yes");
    }

    // Function to print "No"
    public static void no() {
        System.out.println("No");
    }

    // Pair class definition
    public static class Pair {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    // Queue class definition
    public static class Queue {
        private List<Pair> v = new ArrayList<>();

        // Function to push a pair into the queue
        public void push(Pair pair) {
            v.add(pair);
        }

        // Function to pop a pair from the queue
        public Pair pop() {
            return v.remove(0);
        }

        // Function to get the front pair from the queue
        public Pair front() {
            return v.get(0);
        }

        // Function to check if the queue is empty
        public boolean empty() {
            return v.isEmpty();
        }
    }
}

// <END-OF-CODE>
