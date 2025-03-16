
public class Main {
    public static void main(String[] args) {
        // Declare two integer variables: x for input and kotae for storing the result
        int x, kotae;

        // Prompt the user to enter an integer value
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();

        // Calculate the cube of the input value x and store it in kotae
        kotae = x * x * x;

        // Output the result (the cube of x) to the console
        System.out.println(kotae);
    }
}

