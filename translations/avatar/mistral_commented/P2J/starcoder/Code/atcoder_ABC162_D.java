// Import the Math class to use the ceil function
import java.lang.Math;

// Take an integer input N and a string input S from the user
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();
String S = sc.next();

// Define a function calculate that takes two arguments: an integer n and a string s
public static void calculate(int n, String s) {
    // Create a list arr from the string s
    List<Character> arr = new ArrayList<Character>();
    for (int i = 0; i < s.length(); i++) {
        arr.add(s.charAt(i));
    }

    // Count the number of occurrences of each color in the list arr and store them in variables rNum, gNum, and bNum
    int rNum = 0;
    int gNum = 0;
    int bNum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr.get(i) == 'R') {
            rNum++;
        } else if (arr.get(i) == 'G') {
            gNum++;
        } else if (arr.get(i) == 'B') {
            bNum++;
        }
    }

    // Initialize a variable sum to 0
    int sum = 0;

    // Use a for loop to iterate through each step from 1 to the ceiling of N/2
    for (int step = 1; Math.ceil(n/2) >= step; step++) {
        // Inside the inner for loop, join three consecutive elements of the list arr to form a string s
        String s = "";
        for (int i = 0; i < 3; i++) {
            s += arr.get(i);
        }

        // Check if the string s is equal to any of the six possible color combinations: "RGB", "RBG", "BGR", "BRG", "GBR", or "GRB"
        if (s.equals("RGB") || s.equals("RBG") || s.equals("BGR") || s.equals("BRG") || s.equals("GBR") || s.equals("GRB")) {
            sum += 1;
        }
    }

    // After the inner for loop, print the result of the calculation: rNum * gNum * bNum - sum
    System.out.println(rNum * gNum * bNum - sum);
}

// Call the calculate function with the input values N and S
calculate(N, S);

