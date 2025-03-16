import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read from standard input

        int n = sc.nextInt(); // Read an integer from standard input and store it in n
        int m = sc.nextInt(); // Read an integer from standard input and store it in m
        int x = sc.nextInt(); // Read an integer from standard input and store it in x

        int[] a = new int[105]; // Create an array a of size 105 with zeros

        for(int i = 0; i < m; ++i) // Iterate through m times
        {
            int temp = sc.nextInt(); // Read an integer from standard input and store it in temp
            a[temp] = 1; // Set the value of the array element at index temp to 1
        }

        int ansl = 0, ansr = 0, i; // Declare and initialize three integer variables: ansl, ansr, and i

        for(i = x; i <= n; ++i) // Iterate through the range from x to n
        {
            ansr += a[i]; // Add the value of the array element at index i to the variable ansr
        }

        for(i=x; i >= 0; --i) // Iterate through the range from x to 0
        {
            ansl += a[i]; // Add the value of the array element at index i to the variable ansl
        }

        System.out.println(Math.min(ansl, ansr)); // Print the minimum value between ansl and ansr
    }
}

