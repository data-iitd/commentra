// Define the TSize structure
type TSize struct {
    r int
    c int
}

func NewTSize(Ar int, Ac int) *TSize {
    return &TSize{Ar, Ac}
}

