
public class Main {
    public static void main(String[] args) {
        int N, D;
        int ans, rem;

        // Read two integers from standard input
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        D = sc.nextInt();

        // Calculate the number of groups that can be formed
        ans = N / (D*2+1);
        rem = N % (D*2+1);

        // If there are remaining items, increment the number of groups
        if(rem != 0){
            ans = ans + 1;
        }

        // Print the result to standard output
        System.out.println(ans);
    }
}

