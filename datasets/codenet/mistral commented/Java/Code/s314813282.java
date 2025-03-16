import java.util.*; // Importing the utility class Scanner

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in); // Creating a new Scanner object to read input from the user

        int m = scan.nextInt(); // Reading the first integer value from the user and assigning it to the variable 'm'
        int n = scan.nextInt(); // Reading the second integer value from the user and assigning it to the variable 'n'
        int x = scan.nextInt(); // Reading the third integer value from the user and assigning it to the variable 'x'
        int y = scan.nextInt(); // Reading the fourth integer value from the user and assigning it to the variable 'y'

        int[] a = new int[m]; // Creating an integer array 'a' of size 'm'
        for(int i=0;i<a.length;i++) // Iterating through the array 'a' to read its elements from the user
        {
            a[i] = scan.nextInt(); // Reading an integer value from the user and assigning it to the current index of the array 'a'
        }

        int[] b = new int[n]; // Creating an integer array 'b' of size 'n'
        for(int i=0;i<b.length;i++) // Iterating through the array 'b' to read its elements from the user
        {
            b[i] = scan.nextInt(); // Reading an integer value from the user and assigning it to the current index of the array 'b'
        }

        int x_max = MaxInt(x,a); // Finding the maximum integer between 'x' and all the integers in the array 'a'
        int y_min = MinInt(y,b); // Finding the minimum integer between 'y' and all the integers in the array 'b'

        CheckWar(x_max,y_min); // Checking if 'x_max' is greater than or equal to 'y_min' and printing the corresponding message
    }

    static int MaxInt(int x,int[] a){ // Method to find the maximum integer between 'x' and all the integers in the array 'a'
        int bignum=x; // Initializing a variable 'bignum' with the value of 'x'

        for(int i=0;i<a.length;i++) // Iterating through the array 'a' to find the maximum integer
        {
            bignum=Math.max(bignum,a[i]); // Updating the value of 'bignum' with the maximum of its current value and the current array element
        }
        return bignum; // Returning the maximum integer found
    }

    static int MinInt(int y,int[] b){ // Method to find the minimum integer between 'y' and all the integers in the array 'b'
        int smallnum=y; // Initializing a variable 'smallnum' with the value of 'y'

        for(int i=0;i<b.length;i++) // Iterating through the array 'b' to find the minimum integer
        {
            smallnum=Math.min(smallnum,b[i]); // Updating the value of 'smallnum' with the minimum of its current value and the current array element
        }
        return smallnum; // Returning the minimum integer found
    }

    static void CheckWar(int a,int b){ // Method to check if 'a' is greater than or equal to 'b' and print the corresponding message
        if(a>=b) // Checking if 'a' is greater than or equal to 'b'
        {
            System.out.println("War"); // Printing the message "War" if the condition is true
        }
        else
        {
            System.out.println("No War"); // Printing the message "No War" if the condition is false
        }
    }
}