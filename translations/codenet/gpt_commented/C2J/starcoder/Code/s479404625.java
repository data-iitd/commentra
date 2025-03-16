
import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        // Declare character arrays to hold three strings
        char A[] = new char[20], B[] = new char[20], C[] = new char[20];

        // Read three strings from user input
        Scanner sc = new Scanner(System.in);
        sc.next(A);
        sc.next(B);
        sc.next(C);

        // Calculate the lengths of the first two strings
        int la = A.length, lb = B.length;

        // Check if the last character of A is the same as the first character of B
        // and if the last character of B is the same as the first character of C
        if (A[la - 1] == B[0] && B[lb - 1] == C[0])
        {
            // If both conditions are true, print "YES"
            System.out.println("YES");
        }
        else
        {
            // If either condition is false, print "NO"
            System.out.println("NO");
        }
    }
}

