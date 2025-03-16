// Read input values and split them into a list
String[] xxs = scanner.nextLine().split(" ");

// Convert the input strings to integers
int x = Integer.parseInt(xxs[0]);
int t = Integer.parseInt(xxs[1]);
int a = Integer.parseInt(xxs[2]);
int b = Integer.parseInt(xxs[3]);
int da = Integer.parseInt(xxs[4]);
int db = Integer.parseInt(xxs[5]);

public static void main(String[] args) {
    // Check if the target value x is zero
    if (x == 0) {
        System.out.println("YES"); // If x is zero, print "YES" and return
        return;
    }
    
    // Calculate the maximum time available for a and b, constrained by t
    int a_time = Math.min(a / da, t - 1);
    int b_time = Math.min(b / db, t - 1);
    
    // Iterate through all possible values of i and j within the calculated time limits
    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
            // Check if either a or b can be reduced to x by subtracting multiples of da or db
            if (a - da * i == x || b - db * j == x) {
                System.out.println("YES"); // If found, print "YES" and return
                return;
            }
            // Check if the sum of the remaining values of a and b equals x
            if ((a - da * i) + (b - db * j) == x) {
                System.out.println("YES"); // If found, print "YES" and return
                return;
            }
        }
    }
    
    // If no valid combination is found, return "Result Not Found"
    System.out.println("NO");
}

