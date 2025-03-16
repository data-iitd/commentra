
// Function A definition goes here
void A(){
    // Function A code goes here
}

// Function B definition goes here
void B(){
    // Function B code goes here
}

// Function C definition goes here
void C(){
    // Function C code goes here
}

// Function D definition goes here
void D(){
    // Function D code goes here
}

public class Main{
    public static void main(String[] args){
        // Call function B
        B();
    }

    // Function B definition
    // Reads a long long integer 'x' from the standard input
    public static void B(){
        long long int x, sum; // Declare variables 'x' and 'sum' of type long long int
        Scanner sc = new Scanner(System.in); // Create a Scanner object 'sc' to read input from the standard input
        x = sc.nextLong(); // Read a long long integer 'x' from the standard input
        int i; // Declare variable 'i' of type int
        sum = 100; // Initialize 'sum' with the value 100

        // Calculate the number of iterations required to reach or exceed 'x'
        for(i = 0; sum < x; ++i){
            sum += sum / 100; // Update 'sum' by adding the result of dividing 'sum' by 100
        }

        // Print the number of iterations required to reach or exceed 'x'
        System.out.println(i);
    }
}

