

package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"sort"
)

var (
	N, M, K, Q, Va, Vb, Vc, Vd, Ve, Vf, Ua, Ub, Uc, Ud, Ue, Uf, Vra, Vrb, Vrc, Vda, Vdb, Vdc, Dresult, Maybe, Sum int64
	Ch, Dh rune
	S string
	X, Y, Z, W, H, L, R, A, B, C, D, E, F, G, I, J, U, V, W1, W2, W3, W4, W5, W6, W7, W8, W9, W0, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf,Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ye, Yf, Za, Zb, Zc, Zd, Ze, Zf, Ua, Ub, Uc, Ud, Ue, Uf, Va, Vb, Vc, Vd, Ve, Vf, Wa, Wb, Wc, Wd, We, Wf, Xa, Xb, Xc, Xd, Xe, Xf, Ya, Yb, Yc, Yd, Ve, Vf,

int main(void)
{
	return 0;
}



int main(void)
{
	return 0;
}


int main(void)
{
	return 0;
}


int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}


int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}


int main(void)
{
	return 0;
}


	return 0;
}
int main(void)
{
	return 0;
}
int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
{
	return 0;
}

int main(void)
	return 0;
}

int main(