import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of friends
        int n = sc.nextInt(); 
        
        // Arrays to keep track of the number of male and female friends per day
        int[] FfriendPerDay = new int[367]; // Array for female friends
        int[] MfriendPerDay = new int[367]; // Array for male friends
        
        // Variable to store the maximum number of friends present on any day
        int answer = 0; 
        
        // Loop through each friend to gather their availability
        for (int i = 0; i < n; i++) { 
            // Read the gender of the friend (M for male, F for female)
            char c = sc.next().charAt(0); 
            // Read the start day (a) and end day (b) of availability
            int a = sc.nextInt(); 
            int b = sc.nextInt(); 
            
            // Loop through the days from a to b
            for (int j = a; j <= b; j++) { 
                // Increment the count for male or female friends based on gender
                if (c == 'M') 
                    MfriendPerDay[j]++; 
                else 
                    FfriendPerDay[j]++; 
                
                // Check which gender has more friends on that day and update the answer
                if (MfriendPerDay[j] < FfriendPerDay[j]) { 
                    // If females are more, check if their count is greater than the current answer
                    if (MfriendPerDay[j] > answer) 
                        answer = MfriendPerDay[j]; 
                } else { 
                    // If males are more or equal, check if their count is greater than the current answer
                    if (FfriendPerDay[j] > answer) 
                        answer = FfriendPerDay[j]; 
                } 
            } 
        }
        
        // Output the maximum number of friends present on any day multiplied by 2
        System.out.println(answer * 2); 
    } 
}
