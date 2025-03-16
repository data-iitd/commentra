
type TSize struct {
    r int
    c int
}

<<<<<<< HEAD
func NewTSize(Ar, Ac int) TSize {
    return TSize{Ar, Ac}
=======
func NewTSize(Ar, Ac int) *TSize {
    return &TSize{Ar, Ac}
>>>>>>> 98c87cb78a (data updated)
}

