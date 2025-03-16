// Define a function to map strings to integers
public static int[] map(String[] s) {
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
        a[i] = Integer.parseInt(s[i]);
    }
    return a;
}

// Read the first pair of integers (a and at) from the user input
String[] a = in.readLine().split(" ");
int[] at = map(a);

// Read the second pair of integers (b and bt) from the user input
String[] b = in.readLine().split(" ");
int[] bt = map(b);

// Read the start time (t1) and end time (t2) from the user input in the format "HH:MM"
String[] t = in.readLine().split(" ");
int t1 = Integer.parseInt(t[0]);
int t2 = Integer.parseInt(t[1]);

int st = t2 + (t1 - 5) * 60; // Calculate the start time in seconds
// Convert the start time from HH:MM format to seconds

int fin = st + at[0]; // Calculate the finish time in seconds
// Calculate the finish time in seconds

int now = 0; // Initialize the current time to zero
int ans = 0; // Initialize the answer to zero

// Loop through the time until the current time is less than the finish time and less than 1140 (11:00 PM)
while (now < fin && now < 1140) {
    // If the next event starts after the current time, increment the answer
    if (now + bt[0] > st) {
        ans++;
    }
    // Increment the current time by the duration of the next event
    now += b[0];
}

// Print the final answer
System.out.println(ans);

