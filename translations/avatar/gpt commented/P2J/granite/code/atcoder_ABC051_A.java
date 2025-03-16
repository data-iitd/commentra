
// Prompt the user for input and read the input string
Scanner scanner = new Scanner(System.in);
String userInput = scanner.nextLine();

// Replace all commas in the input string with spaces
String modifiedInput = userInput.replaceAll(",", " ");

// Print the modified input string
System.out.println(modifiedInput);

// End of code
