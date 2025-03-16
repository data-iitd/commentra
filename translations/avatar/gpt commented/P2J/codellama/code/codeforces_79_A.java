// Read two integers from input and assign them to x and y
Scanner sc = new Scanner(System.in);
int x = sc.nextInt();
int y = sc.nextInt();

// Initialize a variable 'a' to keep track of whose turn it is (0 or 1)
int a = 0;

// Loop while the conditions for valid moves are met
while (x >= 0 && y >= 22 || x >= 1 && y >= 12 || x >= 2 && y >= 2) {
    // Check whose turn it is based on the value of 'a'
    if (a == 0) {
        // If it's player 0's turn (a == 0)
        if (x >= 2 && y >= 2) {
            // Player 0 can subtract 2 from x and 2 from y
            x -= 2;
            y -= 2;
        } else if (x >= 1 && y >= 12) {
            // Player 0 can subtract 1 from x and 12 from y
            x -= 1;
            y -= 12;
        } else {
            // Player 0 can subtract 22 from y
            y -= 22;
        }
    } else {
        // If it's player 1's turn (a == 1)
        if (y >= 22) {
            // Player 1 can subtract 22 from y
            y -= 22;
        } else if (x >= 1 && y >= 12) {
            // Player 1 can subtract 1 from x and 12 from y
            x -= 1;
            y -= 12;
        } else {
            // Player 1 can subtract 2 from x and 2 from y
            x -= 2;
            y -= 2;
        }
    }

    // Switch turns between player 0 and player 1
    a = 1 - a;
}

// Print the winner based on the last value of 'a'
// If 'a' is 0, player 1 (Ciel) wins; if 'a' is 1, player 0 (Hanako) wins
System.out.println(a == 0 ? "Ciel" : "Hanako");

