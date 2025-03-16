import java.util.*; // Importing the necessary classes from the java.util package

public class Main {
    public static void main(String[] args) throws Exception {
        // Creating a Scanner object to read input from the console
        Scanner scan = new Scanner(System.in);
        
        // Initializing an ArrayList to store the input strings
        ArrayList<String> scList = new ArrayList<>();

        // Continuously read input lines until an exception occurs (e.g., EOF)
        for (int i = 0; i >= 0; i++) {
            try {
                // Adding the input line to the ArrayList
                scList.add(scan.nextLine());
            } catch (Exception e) {
                // Break the loop if an exception occurs (e.g., no more input)
                break;
            }
        }

        // Splitting the first line of input into an array of strings
        String[] numlist = scList.get(0).split(" ");
        
        // Parsing the first number as the count of sheep
        int Sheep = Integer.parseInt(numlist[0]);
        
        // Parsing the second number as the count of wolves
        int Wolve = Integer.parseInt(numlist[1]);

        // Checking if the number of wolves is greater than or equal to the number of sheep
        if (Wolve >= Sheep) {
            // If wolves are greater than or equal to sheep, it's unsafe
            System.out.println("unsafe");
        } else {
            // If wolves are fewer than sheep, it's safe
            System.out.println("safe");
        }
    }
}
