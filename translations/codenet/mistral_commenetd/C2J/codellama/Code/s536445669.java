
// The main function is the entry point of the program
public static void main(String[] args)
{
        // Declare two integer variables 'n' and 'k'
        int n, k;

        // Read two integers from the standard input using scanf
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();

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

