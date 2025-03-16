
public class Main {

    public static void main(String[] args) {

        int x, kotae; // Declare two integer variables, x and kotae


        // Ask the user to input an integer value for x
        System.out.print("Enter an integer value for x: ");
        x = Integer.parseInt(System.console().readLine());


        // Calculate the cube of the input integer x and store the result in the variable kotae
        kotae = x*x*x ;


        // Print the result (the cube of the input integer) to the console
        System.out.printf("The cube of %d is %d.\n", x, kotae);


    }

}
