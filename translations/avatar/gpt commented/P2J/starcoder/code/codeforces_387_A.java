// Read the first time input in 'hh:mm' format and split it into hours and minutes
Scanner sc = new Scanner(System.in);
String[] firstTime = sc.nextLine().split(":");
int h1 = Integer.parseInt(firstTime[0]);
int m1 = Integer.parseInt(firstTime[1]);

// Convert the first time into total minutes
int m1Total = h1 * 60 + m1;

// Read the second time input in 'hh:mm' format and split it into hours and minutes
String[] secondTime = sc.nextLine().split(":");
int h2 = Integer.parseInt(secondTime[0]);
int m2 = Integer.parseInt(secondTime[1]);

// Convert the second time into total minutes
int m2Total = h2 * 60 + m2;

// Calculate the difference in minutes between the first and second time
int m2Diff = m1Total - m2Total;

// Ensure the result is within a 24-hour format by taking modulo 1440 (total minutes in a day)
m2Diff %= 1440;

// Print the result in 'hh:mm' format, ensuring two digits for both hours and minutes
System.out.println(String.format("%02d:%02d", m2Diff / 60, m2Diff % 60));

