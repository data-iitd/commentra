// Main function starts here
public static void main(String[] args)
{
    // Initialize variables
    String str;
    String tmp;
    int sum;

    // Start an infinite loop
    while(true)
    {
        // Read a string from the user input
        str = scanner.nextLine();

        // Check if the user wants to exit by entering "0"
        if(str.equals("0"))
        {
            // Exit the loop if user enters "0"
            break;
        }

        // Initialize sum variable to zero
        sum = 0;

        // Iterate through each character in the string
        for(int i=0;i<str.length();i++)
        {
            // Get the character as a string
            tmp = str.substring(i,i+1);

            // Convert the character to an integer and add it to the sum
            int num = Integer.parseInt(tmp);
            sum += num;
        }

        // Print the sum of the digits in the string
        System.out.println(sum);
    }
}

