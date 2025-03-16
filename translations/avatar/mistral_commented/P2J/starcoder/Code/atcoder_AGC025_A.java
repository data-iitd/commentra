// Take an input from the user and assign it to the variable 'n'
String n = sc.next();

// Initialize a list 'a' with some strings representing numbers
List<String> a = new ArrayList<String>();
a.add("10");
a.add("100");
a.add("1000");
a.add("10000");
a.add("100000");

// Convert each element of the input 'n' to an integer using the'map' function
// and then sum up all the integers using the'sum' function and assign the result to the variable 'new'
int new = 0;
for(int i : map(Integer::parseInt, n)) {
    new += i;
}

// Check if the input 'n' is present in the list 'a'
if(a.contains(n)) {
    // If the input 'n' is present in the list 'a', then print the number 10
    System.out.println(10);
} else {
    // If the input 'n' is not present in the list 'a', then print the value of the variable 'new'
    System.out.println(new);
}

