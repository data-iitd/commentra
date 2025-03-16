// Define the TSize structure
struct TSize
{
    int r;
    int c;
};

// Default constructor
void TSize_default_constructor(struct TSize *this)
{
    this->r = 0;
    this->c = 0;
}

// Parameterized constructor
void TSize_parameterized_constructor(struct TSize *this, int Ar, int Ac)
{
    this->r = Ar;
    this->c = Ac;
}

