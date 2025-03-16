
// Take two integers as input and store them in 'l' and 'r' respectively
Scanner sc = new Scanner(System.in);
int l = sc.nextInt();
int r = sc.nextInt();

// Initialize current number to 'r'
int curr = r;

// Initialize sum variable 's' to 0
int s = 0;

// While 'curr' is not zero, perform the following operations
while (curr != 0) {
    // Increment the sum 's' by 1
    s++;
    
    // Calculate the power of 10 raised to the value of 's' and store it in 'first'
    int first = (int) Math.pow(10, s);
    
    // Calculate half of 'first' and store it in 'second'
    int second = first / 2;
    
    // Initialize 'ans' with a negative value
    int ans = -1;
    
    // Iterate through the list containing 'l', 'r', 'first', and 'second'
    for (int i = l; i <= r; i++) {
        // If 'i' lies within the range of 'l' and 'r', update 'curr' and 'rev'
        if (i >= l && i <= r) {
            curr = i;
            String rev = "";
            // Reverse the digits of 'curr' and store it in 'rev'
            for (int k = 0; k < String.valueOf(curr).length(); k++) {
                rev += (9 - Integer.parseInt(String.valueOf(curr).charAt(k) + ""));
            }
            
            // Update 'ans' with the maximum value of the current 'ans' and the product of 'curr' and the reversed number
            ans = Math.max(ans, Integer.parseInt(rev) * curr);
        }
    }
}

// Print the final answer
System.out.println(ans);

