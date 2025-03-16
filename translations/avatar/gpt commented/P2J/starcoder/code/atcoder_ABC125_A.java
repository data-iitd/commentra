// Read input values for 'a', 'b', and 't' from the user
Scanner sc = new Scanner(System.in);
int a = sc.nextInt();
int b = sc.nextInt();
int t = sc.nextInt();

// Initialize the cookie count to zero
int cookie = 0;

// Set the initial time to 'a'
int time = a;

// Loop until the time exceeds 't + 0.5'
while (time <= t + 0.5) {
    // Add 'b' cookies for each time interval
    cookie += b;
    // Increment the time by 'a' for the next iteration
    time += a;
}

// Print the total number of cookies collected
System.out.println(cookie);

