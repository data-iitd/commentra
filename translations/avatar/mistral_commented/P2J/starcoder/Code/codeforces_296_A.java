// Take an integer 'n' as input from the user
int n = Integer.parseInt(sc.next());

// Take a list'm' as input from the user, where each element is a single character
String[] m = sc.next().split(" ");

// Initialize a boolean variable 'possible' with a default value of True
boolean possible = true;

// Iterate through each unique character 'i' in the list'm'
for (String i : new HashSet<>(Arrays.asList(m))) {
    // Check if the character 'i' appears more than 'n/2 + 1' times in the list'm'
    if (Arrays.asList(m).stream().filter(x -> x.equals(i)).count() >= n / 2 + 1) {
        // If the condition is true, set 'possible' to False and break the loop
        possible = false;
        break;
    }
}

// Print 'YES' if 'possible' is still True, otherwise print 'NO'
System.out.println(possible? "YES" : "NO");

