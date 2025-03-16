int main()
{
    // Declare variables to hold the dimensions and calculated values
    int a, b, mawari, menseki;
    
    // Read two integer inputs from the user representing the dimensions
    cin >> a >> b;
    
    // Calculate the perimeter (mawari) of the rectangle
    mawari = a + a + b + b; // Perimeter formula: 2 * (length + width)
    
    // Calculate the area (menseki) of the rectangle
    menseki = a * b; // Area formula: length * width
    
    // Print the area and perimeter to the console
    cout << menseki << " " << mawari << endl;
    
    // Return 0 to indicate successful completion of the program
    return 0;
}
