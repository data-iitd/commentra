
public class Cube {
    public static void main(String[] args) {
        // Declare an integer variable to hold the input value
        int x;

        // Read an integer value from the user and store it in variable x
        x = Integer.parseInt(args[0]);

        // Calculate the cube of the input value by multiplying it by itself twice
        x = x * x * x;

        // Print the result (the cube of the input value) to the console
        System.out.println(x);
    }
}

