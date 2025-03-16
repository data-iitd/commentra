
import java.util.*;

public class Main
{
        public static void main(String[] args)
        {
                // Read two integers from the standard input using Scanner
                Scanner sc = new Scanner(System.in);
                int n = sc.nextInt();
                int k = sc.nextInt();

                // Check if 'n' is divisible by 'k'
                if(n%k==0)
                {
                        // If it is, print '0' to the standard output
                        System.out.println("0");
                }
                else
                {
                        // If it's not, print '1' to the standard output
                        System.out.println("1");
                }
        }
}

