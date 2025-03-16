

import java.util.Scanner;

public class s554610878{
    public static void main(String[] args) {
        // Initialize week array with 7 days of the week
        String[] week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

        // Read input string from scanner
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Find index of the given day in week array
        int index = -1;
        for (int i = 0; i < week.length; i++) {
            if (s.equals(week[i])) {
                index = i;
                break;
            }
        }

        // If the given day is not present in the week array, panic with error message
        if (index == -1) {
            throw new IllegalArgumentException("Invalid day of the week");
        }

        // Calculate the number of days between the given day and Sunday
        // and print the result
        int daysUntilSunday = 7 - index;
        System.out.println("The number of days until Sunday is: " + daysUntilSunday);
    }

    // Function to calculate the absolute value of a number
    public static int abs(int num) {
        return Math.abs(num);
    }

    // Function to calculate the power of a number
    public static int pow(int base, int exp) {
        return (int) Math.pow(base, exp);
    }

    // Function to find the minimum of given numbers
    public static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("min() requires at least one argument");
        }
        int min = nums[0];
        for (int num : nums) {
            if (num < min) {
                min = num;
            }
        }
        return min;
    }

    // Function to find the maximum of given numbers
    public static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("max() requires at least one argument");
        }
        int max = nums[0];
        for (int num : nums) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }

    // Function to check if a string is present in a slice of strings
    public static boolean strSearch(String[] slice, String str) {
        for (String s : slice) {
            if (s.equals(str)) {
                return true;
            }
        }
        return false;
    }

    // Function to print an integer array
    public static void printIntArray(int[] array) {
        System.out.println(java.util.Arrays.toString(array));
    }

    // Function to calculate the modulo of a number
    public static int calcMod(int num) {
        return num % 100000007;
    }

    // Function to read a single line of input as string
    public static String getString() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    // Function to read a single line of input as integer
    public static int getInt() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }
}

// s554610878 function
public class s554610878{
    public static void main(String[] args) {
        // Initialize week array with 7 days of the week
        String[] week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        // Read input string from scanner
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Find index of the given day in week array
        int index = -1;
        for (int i = 0; i < week.length; i++) {
            if (s.equals(week[i])) {
                index = i;
                break;
            }
        }

        // If the given day is not present in the week array, panic with error message
        if (index == -1) {
            throw new IllegalArgumentException("Invalid day of the week");
        }

        // Calculate the number of days between the given day and Sunday
        // and print the result
        int daysUntilSunday = 7 - index;
        System.out.println("The number of days until Sunday is: " + daysUntilSunday);
    }

    // Function to calculate the absolute value of a number
    public static int abs(int num) {
        return Math.abs(num);
    }

    // Function to calculate the power of a number
    public static int pow(int base, int exp) {
        return (int) Math.pow(base, exp);
    }

    // Function to find the minimum of given numbers
    public static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("min() requires at least one argument");
        }
        int min = nums[0];
        for (int num : nums) {
            if (num < min) {
                min = num;
            }
        }
        return min;
    }

    // Function to find the maximum of given numbers
    public static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("max() requires at least one argument");
        }
        int max = nums[0];
        for (int num : nums) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }

    // Function to check if a string is present in a slice of strings
    public static boolean strSearch(String[] slice, String str) {
        for (String s : slice) {
            if (s.equals(str)) {
                return true;
            }
        }
        return false;
    }

    // Function to print an integer array
    public static void printIntArray(int[] array) {
        System.out.println(java.util.Arrays.toString(array));
    }

    // Function to calculate the modulo of a number
    public static int calcMod(int num) {
        return num % 1000000007;
    }

    // Function to read a single line of input as string
    public static String getString() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    // Function to read a single line of input as integer
    public static int getInt() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }
}

// s554610878 function
public class s554610878{
    public static void main(String[] args) {
        // Initialize week array with 7 days of the week
        String[] week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        // Read input string from scanner
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Find index of the given day in week array
        int index = -1;
        for (int i = 0; i < week.length; i++) {
            if (s.equals(week[i])) {
                index = i;
                break;
            }
        }

        // If the given day is not present in the week array, panic with error message
        if (index == -1) {
            throw new IllegalArgumentException("Invalid day of the week");
        }

        // Calculate the number of days between the given day and Sunday
        // and print the result
        int daysUntilSunday = 7 - index;
        System.out.println("The number of days until Sunday is: " + daysUntilSunday);
    }

    // Function to calculate the absolute value of a number
    public static int abs(int num) {
        return Math.abs(num);
    }

    // Function to calculate the power of a number
    public static int pow(int base, int exp) {
        return (int) Math.pow(base, exp);
    }

    // Function to find the minimum of given numbers
    public static int min(int... nums) {
        if (nums.length == 0) {
            panic("min() requires at least one argument")
        }
        int min = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < min) {
                min = nums[i]
            }
        }
        return min;
    }

    // Function to find the maximum of given numbers
    public static int max(int... nums) {
        if (nums.length == 0) {
            panic("max() requires at least one argument")
        }
        int max = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > max) {
                max = nums[i]
            }
        }
        return max;
    }

    // Function to check if a string is present in a slice of strings
    public static bool strSearch(string[] slice, string s) {
        for (int i = 0; i < slice.length; i++) {
            if (slice[i] == s {
                return true
            }
        }
        return false;
    }

    // Function to print an integer array
    public static void printIntArray(int[] array) {
        fmt.Println(array)
    }

    // Function to calculate the modulo of a number
    public static int calcMod(int num) {
        return num % 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000