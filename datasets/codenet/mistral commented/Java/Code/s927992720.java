import java.util.Scanner; // Importing the Scanner class from the java.util package

class Main{ // Defining a class named Main
    public static void main(String[] args){ // Defining the main method that is the entry point of the program
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the standard input stream

        while(true){ // Starting an infinite loop
            int a = sc.nextInt(); // Reading the first integer input
            String op = sc.next(); // Reading the operator input as a string
            int b = sc.nextInt(); // Reading the second integer input

            if(op.equals("?")){ // Checking if the operator is "?"
                break; // Exiting the loop if the operator is "?"
            }

            if(op.equals("+")){ // Checking if the operator is "+"
                System.out.println(a + b); // Printing the sum of the two integers
            }

            if(op.equals("-")){ // Checking if the operator is "-"
                System.out.println(a - b); // Printing the difference of the two integers
            }

            if(op.equals("*")){ // Checking if the operator is "*"
                System.out.println(a * b); // Printing the product of the two integers
            }

            if(op.equals("/")){ // Checking if the operator is "/"
                System.out.println(a / b); // Printing the quotient of the two integers
            }
        }
    }
}
