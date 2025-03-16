
// Importing required packages
import java.util.Scanner;

public class s617302278{
    public static void main(String[] args) {
        // Initializing scanner
        Scanner sc = new Scanner(System.in);

        // Function to read a line text from stdin and return its string
        String NextLine() {
            // Scanning next line from stdin
            sc.nextLine();
            // Returning the scanned line text
            return sc.nextLine();
        }

        // Function to read a line text, that consists of ONLY INTEGERS DELIMITED BY SPACES, from stdin
        // And then returns integers array
        int[] NextIntsLine() {
            // Initializing empty integers array
            String[] tmp = NextLine().split(" ");
            // Initializing integers array with the length of tmp
            int[] ints = new int[tmp.length];
            // Iterating through the tmp array and converting each string to integer
            // and appending it to the integers array
            for (int i = 0; i < tmp.length; i++) {
                // Converting string to integer
                ints[i] = Integer.parseInt(tmp[i]);
            }
            // Returning the integers array
            return ints;
        }

        // Function to read a line text, that consists of ONLY CHARACTERS ARRANGED CONTINUOUSLY, from stdin
        // And then returns runes array
        char[] NextRunesLine() {
            // Returning the next line text as runes array
            return NextLine().toCharArray();
        }

        // Function to find the maximum integer among input integers
        // This function needs at least 1 argument (no argument causes panic)
        int Max(int... integers) {
            // Initializing maximum integer as first integer
            int m = integers[0];
            // Iterating through the input integers
            for (int i = 0; i < integers.length; i++) {
                // If current integer is greater than maximum integer, update maximum integer
                if (i == 0) {
                    continue;
                }
                if (m < integers[i]) {
                    m = integers[i];
                }
            }
            // Returning the maximum integer
            return m;
        }

        // Function to find the minimum integer among input integers
        // This function needs at least 1 argument (no argument causes panic)
        int Min(int... integers) {
            // Initializing minimum integer as first integer
            int m = integers[0];
            // Iterating through the input integers
            for (int i = 0; i < integers.length; i++) {
                // If current integer is smaller than minimum integer, update minimum integer
                if (i == 0) {
                    continue;
                }
                if (m > integers[i]) {
                    m = integers[i];
                }
            }
            // Returning the minimum integer
            return m;
        }

        // Function to calculate integer power
        int PowInt(int a, int e) {
            // Checking for negative integers
            if (a < 0 || e < 0) {
                throw new IllegalArgumentException("PowInt does not accept negative integers");
            }
            // Converting base and exponent to double
            double fa = (double) a;
            double fe = (double) e;
            // Calculating the power using Math.pow
            double fanswer = Math.pow(fa, fe);
            // Converting the answer back to integer
            return (int) fanswer;
        }

        // Function to calculate absolute value of an integer
        int AbsInt(int a) {
            // Converting integer to double
            double fa = (double) a;
            // Calculating the absolute value using Math.abs
            double fanswer = Math.abs(fa);
            // Converting the answer back to integer
            return (int) fanswer;
        }

        // Function to delete an element from a slice
        int[] DeleteElement(int[] s, int i) {
            // Checking for negative index or empty slice
            if (i < 0 || s.length <= i) {
                throw new IndexOutOfBoundsException();
            }
            // Creating a new slice with zero capacity
            int[] n = new int[s.length - 1];
            // Appending elements before the index to the new slice
            System.arraycopy(s, 0, n, 0, i);
            // Appending elements after the index to the new slice
            System.arraycopy(s, i + 1, n, i, s.length - i - 1);
            // Returning the new slice
            return n;
        }

        // Function to concatenate two slices
        char[] Concat(char[] s, char[] t) {
            // Creating a new slice with zero capacity
            char[] n = new char[s.length + t.length];
            // Appending elements of the first slice to the new slice
            System.arraycopy(s, 0, n, 0, s.length);
            // Appending elements of the second slice to the new slice
            System.arraycopy(t, 0, n, s.length, t.length);
            // Returning the new slice
            return n;
        }

        // Function to sort a slice using Arrays.sort
        //Arrays.sort(s);
        //Arrays.sort(s, Collections.reverseOrder());

        // Function to copy elements from one slice to another
        //a = new int[]{0, 1, 2};
        //b = new int[a.length];
        //System.arraycopy(a, 0, b, 0, a.length);

        // Variable declaration and initialization
        int x;

        // s617302278 function
        public static void main(String[] args) {
            // Reading integers from stdin as a line text
            int[] tmp = NextIntsLine();
            // Assigning the first integer to variable x
            x = tmp[0];
            // Initializing sum variable as zero
            int sum = 0;
            // Initializing index variable as one
            int i = 1;
            // Looping until the sum is greater than or equal to x
            while (sum < x) {
                // Adding current index to sum
                sum += i;
                // Incrementing index
                i++;
            }
            // Printing the index
            System.out.println(i);
        }
    }

