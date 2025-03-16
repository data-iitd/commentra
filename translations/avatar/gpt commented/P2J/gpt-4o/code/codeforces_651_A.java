import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from input and assign them to x and y
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        
        // Calculate the maximum value based on the formula and print it
        // The formula computes x + y - 3 and adjusts based on the difference between y and x
        // It ensures the result is not negative by taking the maximum with 0
        System.out.println(Math.max(x + y - 3 + ((y - x) % 3 > 0 ? 1 : 0), 0));
        
        // Close the scanner
        scanner.close();
    }
}

// Define a method to read a single integer from input
public static int numInp() {
    Scanner scanner = new Scanner(System.in);
    return scanner.nextInt();
}

// Define a method to read a list of integers from input
public static int[] arrInp() {
    Scanner scanner = new Scanner(System.in);
    String[] input = scanner.nextLine().split(" ");
    int[] arr = new int[input.length];
    for (int i = 0; i < input.length; i++) {
        arr[i] = Integer.parseInt(input[i]);
    }
    return arr;
}

// Define a method to read a space-separated list of integers from input
public static int[] spInp() {
    Scanner scanner = new Scanner(System.in);
    String[] input = scanner.nextLine().split(" ");
    int[] arr = new int[input.length];
    for (int i = 0; i < input.length; i++) {
        arr[i] = Integer.parseInt(input[i]);
    }
    return arr;
}

// Define a method to read a string from input
public static String strInp() {
    Scanner scanner = new Scanner(System.in);
    return scanner.nextLine();
}

// <END-OF-CODE>
