// Importing the java.util.Scanner class to take input from the user
import java.util.Scanner;

// Importing the java.util.Arrays class to sort the arrays
import java.util.Arrays;

// Importing the java.util.Collections class to use the Counter function
import java.util.Collections;

// Defining a function named 'run' that takes two arguments 's' and 't'
public static String run(String s, String t) {
    // Using Counter function to count the occurrences of each character in string 's'
    // and storing the result in a dictionary
    int[] ss = sort(list(Collections.Counter(s).values()));

    // Using Counter function to count the occurrences of each character in string 't'
    // and storing the result in a dictionary
    int[] tt = sort(list(Collections.Counter(t).values()));

    // Comparing the sorted lists of occurrences of characters in strings 's' and 't'
    // If they are equal, then the strings have the same frequency distribution of characters
    // and thus are identical, so return 'Yes'
    // Otherwise, return 'No'
    if (Arrays.equals(ss, tt)) {
        return "Yes";
    } else {
        return "No";
    }
}

// Defining a function named 'main' that takes no arguments
public static void main(String[] args) {
    // Taking input strings 's' and 't' from the user
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    String t = sc.nextLine();

    // Calling the 'run' function with strings 's' and 't' as arguments and printing the result
    System.out.println(run(s, t));
}

// Sorting the array of integers using the Arrays.sort function
public static int[] sort(int[] arr) {
    Arrays.sort(arr);
    return arr;
}

// Defining a function named 'list' that takes a string 's' as argument
// and returns a list of integers representing the occurrences of each character in the string 's'
public static int[] list(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'Counter' that takes a string 's' as argument
// and returns a dictionary containing the occurrences of each character in the string 's'
public static int[] Counter(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'sort' that takes an array of integers 'arr' as argument
// and returns a sorted array of integers
public static int[] sort(int[] arr) {
    Arrays.sort(arr);
    return arr;
}

// Defining a function named 'list' that takes a string 's' as argument
// and returns a list of integers representing the occurrences of each character in the string 's'
public static int[] list(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'Counter' that takes a string 's' as argument
// and returns a dictionary containing the occurrences of each character in the string 's'
public static int[] Counter(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'sort' that takes an array of integers 'arr' as argument
// and returns a sorted array of integers
public static int[] sort(int[] arr) {
    Arrays.sort(arr);
    return arr;
}

// Defining a function named 'list' that takes a string 's' as argument
// and returns a list of integers representing the occurrences of each character in the string 's'
public static int[] list(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'Counter' that takes a string 's' as argument
// and returns a dictionary containing the occurrences of each character in the string 's'
public static int[] Counter(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'sort' that takes an array of integers 'arr' as argument
// and returns a sorted array of integers
public static int[] sort(int[] arr) {
    Arrays.sort(arr);
    return arr;
}

// Defining a function named 'list' that takes a string 's' as argument
// and returns a list of integers representing the occurrences of each character in the string 's'
public static int[] list(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'Counter' that takes a string 's' as argument
// and returns a dictionary containing the occurrences of each character in the string 's'
public static int[] Counter(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'sort' that takes an array of integers 'arr' as argument
// and returns a sorted array of integers
public static int[] sort(int[] arr) {
    Arrays.sort(arr);
    return arr;
}

// Defining a function named 'list' that takes a string 's' as argument
// and returns a list of integers representing the occurrences of each character in the string 's'
public static int[] list(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'Counter' that takes a string 's' as argument
// and returns a dictionary containing the occurrences of each character in the string 's'
public static int[] Counter(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'sort' that takes an array of integers 'arr' as argument
// and returns a sorted array of integers
public static int[] sort(int[] arr) {
    Arrays.sort(arr);
    return arr;
}

// Defining a function named 'list' that takes a string 's' as argument
// and returns a list of integers representing the occurrences of each character in the string 's'
public static int[] list(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'Counter' that takes a string 's' as argument
// and returns a dictionary containing the occurrences of each character in the string 's'
public static int[] Counter(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'sort' that takes an array of integers 'arr' as argument
// and returns a sorted array of integers
public static int[] sort(int[] arr) {
    Arrays.sort(arr);
    return arr;
}

// Defining a function named 'list' that takes a string 's' as argument
// and returns a list of integers representing the occurrences of each character in the string 's'
public static int[] list(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'Counter' that takes a string 's' as argument
// and returns a dictionary containing the occurrences of each character in the string 's'
public static int[] Counter(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'sort' that takes an array of integers 'arr' as argument
// and returns a sorted array of integers
public static int[] sort(int[] arr) {
    Arrays.sort(arr);
    return arr;
}

// Defining a function named 'list' that takes a string 's' as argument
// and returns a list of integers representing the occurrences of each character in the string 's'
public static int[] list(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'Counter' that takes a string 's' as argument
// and returns a dictionary containing the occurrences of each character in the string 's'
public static int[] Counter(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'sort' that takes an array of integers 'arr' as argument
// and returns a sorted array of integers
public static int[] sort(int[] arr) {
    Arrays.sort(arr);
    return arr;
}

// Defining a function named 'list' that takes a string 's' as argument
// and returns a list of integers representing the occurrences of each character in the string 's'
public static int[] list(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'Counter' that takes a string 's' as argument
// and returns a dictionary containing the occurrences of each character in the string 's'
public static int[] Counter(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'sort' that takes an array of integers 'arr' as argument
// and returns a sorted array of integers
public static int[] sort(int[] arr) {
    Arrays.sort(arr);
    return arr;
}

// Defining a function named 'list' that takes a string 's' as argument
// and returns a list of integers representing the occurrences of each character in the string 's'
public static int[] list(String s) {
    int[] arr = new int[26];
    for (int i = 0; i < s.length(); i++) {
        arr[s.charAt(i) - 'a']++;
    }
    return arr;
}

// Defining a function named 'Cou