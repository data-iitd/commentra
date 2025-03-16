
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        // Declare a character array to hold the input string
        char n[] = new char[10];

        // Read a string from standard input and store it in the array 'n'
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        n = sc.nextLine().toCharArray();

        // Check if the first three characters are the same or if the last three characters are the same
        if (((n[0] == n[1]) && (n[1] == n[2])) || ((n[1] == n[2]) && (n[2] == n[3])))
        {
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        }
        else
        {
            // If the condition is false, print "No"
            System.out.println("No");
        }
    }
}

