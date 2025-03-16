// Read an integer input from the user
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();

// Define a recursive function 'aaa' that takes a string 'n'
public static int aaa(String n) {
    // Check if the integer value of 'n' exceeds the limit N
    if (Integer.parseInt(n) > N) {
        return 0; // If it does, return 0 (base case)
    }

    // Check if the digits of 'n' are exactly '7', '5', and '3'
    int ans = 1;
    if (new HashSet<Character>(n.toCharArray()).size() == 3) {
        ans = 0;
    }

    // Iterate over each character in the string '753'
    for (char i : "753".toCharArray()) {
        // Recursively call 'aaa' with the current number 'n' concatenated with 'i'
        ans += aaa(n + i);
    }

    // Return the accumulated answer
    return ans;
}

// Print the result of calling 'aaa' with the initial value '0'
System.out.println(aaa("0"));

