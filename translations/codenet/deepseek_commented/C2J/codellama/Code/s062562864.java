
public class Main {
    public static void main(String[] args) {
        // Declare integer variables to store input values and intermediate results
        int a, b, c, d, i, j;

        // Read four integers from the user
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        d = sc.nextInt();

        // Perform multiplication operations and store the results in i and j
        i = a * b;
        j = c * d;

        // Use an if-else statement to compare the results and print the larger one
        if (i > j) {
            System.out.println(i);
        } else {
            System.out.println(j);
        }
    }
}

