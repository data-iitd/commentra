// Define the TSize structure
struct TSize
{
    int r;
    int c;
    TSize() : r(0), c(0) {} // Default constructor
    TSize(int Ar, int Ac) // Parameterized constructor
     : r(Ar), c(Ac)
    {}
};
