#######
# Code
#######

// Input the string of numbers separated by spaces and split it into a list
String[] xxs = input.split(" ");

// Extract the first six numbers as integers and assign them to variables x, t, a, b, da, db respectively
int x = Integer.parseInt(xxs[0]);
int t = Integer.parseInt(xxs[1]);
int a = Integer.parseInt(xxs[2]);
int b = Integer.parseInt(xxs[3]);
int da = Integer.parseInt(xxs[4]);
int db = Integer.parseInt(xxs[5]);

// Define the main function to perform the logic of the program
public static String main() {
    // Check if x is equal to zero
    if (x == 0) {
        // If yes, print "YES" and return
        System.out.println("YES");
        return "Result Found";
    }

    // Calculate the minimum time it takes for a and b to reach x
    int a_time = Math.min(a / da, t - 1);
    int b_time = Math.min(b / db, t - 1);

    // Loop through all possible combinations of a_time and b_time
    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
            // Check if x is equal to a after 'i' time steps or b after 'j' time steps
            if (a - da * i == x || b - db * j == x) {
                // If yes, print "YES" and return
                System.out.println("YES");
                return "Result Found";
            }

            // Check if x is equal to the sum of a after 'i' time steps and b after 'j' time steps
            if (a - da * i) + (b - db * j) == x) {
                // If yes, print "YES" and return
                System.out.println("YES");
                return "Result Found";
            }
        }
    }

    // If the result is "Result Not Found", print "NO"
    System.out.println("NO");
    return "Result Not Found";
}

// Call the main function and assign the result to a variable ff
String ff = main();

// If the result is "Result Not Found", print "NO"
if (ff == "Result Not Found") {
    System.out.println("NO");
}

