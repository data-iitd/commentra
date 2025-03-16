// Define input variables's' and 'l'
String s = (input());
int l = 2019;

// Initialize list'm' with initial value 1 for index 0 and zeros for other indices
int[] m = new int[l + 1];
m[0] = 1;

// Initialize variables 'a' and 'r' with zero values
int a = 0, r = 0;

// Iterate through the string's' in reverse order
for (int i = s.length() - 1; i >= 0; i--) {
    // Calculate the current digit's power and add it to 'a'
    a += (int) Math.pow(10, i) * (int) s.charAt(i) - 48;

    // Increment the index 'a % l' in list'm'
    m[a % l]++;

    // Update 'r' with the current sum
    r += m[a % l];
}

// Print the final result 'r'
System.out.println(r);

