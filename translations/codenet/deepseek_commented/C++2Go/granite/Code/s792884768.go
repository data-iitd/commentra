
// Define the TSize structure
type TSize struct {
    r int
    c int
}

func NewTSize() *TSize {
    return &TSize{r: 0, c: 0}
}

func NewTSize2(Ar, Ac int) *TSize {
    return &TSize{r: Ar, c: Ac}
}

// 