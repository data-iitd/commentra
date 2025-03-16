// Define a type alias for long long to simplify code
typedef long long ll;

public class Main {
    public static void main(String[] args) {
        // Declare variables for the number of items (n) and the distance (d)
        int n, d;
        
        // Read input values for n and d from the user
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        d = sc.nextInt();

        // Calculate the effective range of coverage, which is (d*2 + 1)
        double a = d * 2 + 1;

        // Calculate and output the minimum number of groups needed to cover 'n' items
        // This is done by dividing 'n' by the coverage 'a' and rounding up to the nearest whole number
        System.out.println((int) Math.ceil(n / a));
    }
}

