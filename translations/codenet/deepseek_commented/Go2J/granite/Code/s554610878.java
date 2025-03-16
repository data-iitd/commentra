
import java.util.*;

public class s554610878{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
        String s = sc.next();
        int index = -1;
        for (int i = 0; i < week.length; i++) {
            if (s.equals(week[i])) {
                index = i;
                break;
            }
        }
        System.out.println(7 - index);
    }
}

// s554610878 function to determine the number of days until Sunday for a given day.
public class s554610878{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
        String s = sc.next();
        int index = -1;
        for (int i = 0; i < week.length; i++) {
            if (s.equals(week[i])) {
                index = i;
                break;
            }
        }
        System.out.println(7 - index);
    }
}

// Helper function to read an integer from standard input.
public static int getInt() {
    Scanner sc = new Scanner(System.in);
    return sc.nextInt();
}

// Helper function to read a string from standard input.
public static String getString() {
    Scanner sc = new Scanner(System.in);
    return sc.next();
}

// Function to return the absolute value of an integer.
public static int abs(int a) {
    return Math.abs(a);
}

// Function to return the result of raising the first argument to the power of the second argument.
public static int pow(int p, int q) {
    return (int) Math.pow(p, q);
}

// Function to return the smallest integer from a list of integers.
public static int min(int... nums) {
    if (nums.length == 0) {
        throw new IllegalArgumentException("function min() requires at least one argument.");
    }
    int res = nums[0];
    for (int i = 0; i < nums.length; i++) {
        res = Math.min(res, nums[i]);
    }
    return res;
}

// Function to return the largest integer from a list of integers.
public static int max(int... nums) {
    if (nums.length == 0) {
        throw new IllegalArgumentException("function max() requires at least one argument.");
    }
    int res = nums[0];
    for (int i = 0; i < nums.length; i++) {
        res = Math.max(res, nums[i]);
    }
    return res;
}

// Function to check if a string is present in a slice of strings.
public static boolean strSearch(String[] a, String b) {
    for (int i = 0; i < a.length; i++) {
        if (a[i].equals(b)) {
            return true;
        }
    }
    return false;
}

// Function to print a slice of integers in a specific format.
public static void printIntArray(int[] array) {
    System.out.println(Arrays.toString(array).replace("[", "").replace("]", "").replace(", ", ","));
}

// Function to return the modulo of an integer with respect to mod.
public static int calcMod(int x) {
    return x % mod;
}

// END-OF-CODE