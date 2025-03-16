// Define the first hour and minute variables from user input
Scanner input = new Scanner(System.in);
int h1 = input.nextInt();
int m1 = input.nextInt();

// Add the hour to the minute value
m1 += h1 * 60;

// Define the second hour and minute variables from user input
int h2 = input.nextInt();
int m2 = input.nextInt();

// Add the hour to the minute value for the second set of variables
m2 += h2 * 60;

// Calculate the difference between the total minutes of the first and second sets of variables
m2 = m1 - m2;

// Calculate the remainder of the difference when divided by 1440 (24 hours * 60 minutes)
m2 %= 1440;

// Print the result in the format of hours and minutes
System.out.println(m2 / 60 + ":" + m2 % 60);

