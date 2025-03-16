// Importing required packages
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Initializing scanner
    private static final Scanner sc = new Scanner(System.in);

    // Function to read a line text from stdin and return its string
    private static String nextLine() {
        // Returning the scanned line text
        return sc.nextLine();
    }

    // Function to read a line text, that consists of ONLY INTEGERS DELIMITED BY SPACES, from stdin
    // And then returns integers list
    private static List<Integer> nextIntsLine() {
        // Initializing empty integers list
        List<Integer> integers = new ArrayList<>();
        // Reading a line text from stdin
        String intsStr = nextLine();
        // Splitting the line text by space
        String[] tmp = intsStr.split(" ");
        // Iterating through the split text and converting each string to integer
        // and appending it to the integers list
        for (String s : tmp) {
            // Converting string to integer
            integers.add(Integer.parseInt(s));
        }
        // Returning the integers list
        return integers;
    }

    // Function to find the maximum integer among input integers
    // This function needs at least 1 argument (no argument causes exception)
    private static int max(int... integers) {
        // Initializing maximum integer as first integer
        int m = integers[0];
        // Iterating through the input integers
        for (int i = 1; i < integers.length; i++) {
            // If current integer is greater than maximum integer, update maximum integer
            if (m < integers[i]) {
                m = integers[i];
            }
        }
        // Returning the maximum integer
        return m;
    }

    // Function to find the minimum integer among input integers
    // This function needs at least 1 argument (no argument causes exception)
    private static int min(int... integers) {
        // Initializing minimum integer as first integer
        int m = integers[0];
        // Iterating through the input integers
        for (int i = 1; i < integers.length; i++) {
            // If current integer is smaller than minimum integer, update minimum integer
            if (m > integers[i]) {
                m = integers[i];
            }
        }
        // Returning the minimum integer
        return m;
    }

    // Function to calculate integer power
    private static int powInt(int a, int e) {
        // Checking for negative integers
        if (a < 0 || e < 0) {
            throw new IllegalArgumentException("[argument error]: powInt does not accept negative integers");
        }
        // Calculating the power using Math.pow
        return (int) Math.pow(a, e);
    }

    // Function to calculate absolute value of an integer
    private static int absInt(int a) {
        // Calculating the absolute value using Math.abs
        return Math.abs(a);
    }

    // Function to delete an element from a list
    private static List<Integer> deleteElement(List<Integer> list, int i) {
        // Checking for negative index or empty list
        if (i < 0 || list.size() <= i) {
            throw new IndexOutOfBoundsException("[index error]");
        }
        // Creating a new list
        List<Integer> newList = new ArrayList<>(list.size() - 1);
        // Appending elements before the index to the new list
        for (int j = 0; j < list.size(); j++) {
            if (j != i) {
                newList.add(list.get(j));
            }
        }
        // Returning the new list
        return newList;
    }

    // Main function
    public static void main(String[] args) {
        // Reading integers from stdin as a line text
        List<Integer> tmp = nextIntsLine();
        // Assigning the first integer to variable x
        int x = tmp.get(0);
        // Initializing sum variable as zero
        int sum = 0;
        // Initializing index variable as one
        int i = 1;
        // Looping until the sum is greater than or equal to x
        while (true) {
            // Adding current index to sum
            sum += i;
            // Checking if sum is greater than or equal to x
            if (sum >= x) {
                // Breaking the loop
                break;
            }
            // Incrementing index
            i++;
        }
        // Printing the index
        System.out.println(i);
    }
}
// <END-OF-CODE>
