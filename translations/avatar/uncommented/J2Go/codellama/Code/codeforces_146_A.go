
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var x, y, t int
	var n int
	var str string
	var l []rune
	var i int
	var err error
	var s string
	var r int
	var c rune
	var x1, y1 int
	var t1 int
	var n1 int
	var str1 string
	var l1 []rune
	var i1 int
	var err1 error
	var s1 string
	var r1 int
	var c1 rune
	var x2, y2 int
	var t2 int
	var n2 int
	var str2 string
	var l2 []rune
	var i2 int
	var err2 error
	var s2 string
	var r2 int
	var c2 rune
	var x3, y3 int
	var t3 int
	var n3 int
	var str3 string
	var l3 []rune
	var i3 int
	var err3 error
	var s3 string
	var r3 int
	var c3 rune
	var x4, y4 int
	var t4 int
	var n4 int
	var str4 string
	var l4 []rune
	var i4 int
	var err4 error
	var s4 string
	var r4 int
	var c4 rune
	var x5, y5 int
	var t5 int
	var n5 int
	var str5 string
	var l5 []rune
	var i5 int
	var err5 error
	var s5 string
	var r5 int
	var c5 rune
	var x6, y6 int
	var t6 int
	var n6 int
	var str6 string
	var l6 []rune
	var i6 int
	var err6 error
	var s6 string
	var r6 int
	var c6 rune
	var x7, y7 int
	var t7 int
	var n7 int
	var str7 string
	var l7 []rune
	var i7 int
	var err7 error
	var s7 string
	var r7 int
	var c7 rune
	var x8, y8 int
	var t8 int
	var n8 int
	var str8 string
	var l8 []rune
	var i8 int
	var err8 error
	var s8 string
	var r8 int
	var c8 rune
	var x9, y9 int
	var t9 int
	var n9 int
	var str9 string
	var l9 []rune
	var i9 int
	var err9 error
	var s9 string
	var r9 int
	var c9 rune
	var x10, y10 int
	var t10 int
	var n10 int
	var str10 string
	var l10 []rune
	var i10 int
	var err10 error
	var s10 string
	var r10 int
	var c10 rune
	var x11, y11 int
	var t11 int
	var n11 int
	var str11 string
	var l11 []rune
	var i11 int
	var err11 error
	var s11 string
	var r11 int
	var c11 rune
	var x12, y12 int
	var t12 int
	var n12 int
	var str12 string
	var l12 []rune
	var i12 int
	var err12 error
	var s12 string
	var r12 int
	var c12 rune
	var x13, y13 int
	var t13 int
	var n13 int
	var str13 string
	var l13 []rune
	var i13 int
	var err13 error
	var s13 string
	var r13 int
	var c13 rune
	var x14, y14 int
	var t14 int
	var n14 int
	var str14 string
	var l14 []rune
	var i14 int
	var err14 error
	var s14 string
	var r14 int
	var c14 rune
	var x15, y15 int
	var t15 int
	var n15 int
	var str15 string
	var l15 []rune
	var i15 int
	var err15 error
	var s15 string
	var r15 int
	var c15 rune
	var x16, y16 int
	var t16 int
	var n16 int
	var str16 string
	var l16 []rune
	var i16 int
	var err16 error
	var s16 string
	var r16 int
	var c16 rune
	var x17, y17 int
	var t17 int
	var n17 int
	var str17 string
	var l17 []rune
	var i17 int
	var err17 error
	var s17 string
	var r17 int
	var c17 rune
	var x18, y18 int
	var t18 int
	var n18 int
	var str18 string
	var l18 []rune
	var i18 int
	var err18 error
	var s18 string
	var r18 int
	var c18 rune
	var x19, y19 int
	var t19 int
	var n19 int
	var str19 string
	var l19 []rune
	var i19 int
	var err19 error
	var s19 string
	var r19 int
	var c19 rune
	var x20, y20 int
	var t20 int
	var n20 int
	var str20 string
	var l20 []rune
	var i20 int
	var err20 error
	var s20 string
	var r20 int
	var c20 rune
	var x21, y21 int
	var t21 int
	var n21 int
	var str21 string
	var l21 []rune
	var i21 int
	var err21 error
	var s21 string
	var r21 int
	var c21 rune
	var x22, y22 int
	var t22 int
	var n22 int
	var str22 string
	var l22 []rune
	var i22 int
	var err22 error
	var s22 string
	var r22 int
	var c22 rune
	var x23, y23 int
	var t23 int
	var n23 int
	var str23 string
	var l23 []rune
	var i23 int
	var err23 error
	var s23 string
	var r23 int
	var c23 rune
	var x24, y24 int
	var t24 int
	var n24 int
	var str24 string
	var l24 []rune
	var i24 int
	var err24 error
	var s24 string
	var r24 int
	var c24 rune
	var x25, y25 int
	var t25 int
	var n25 int
	var str25 string
	var l25 []rune
	var i25 int
	var err25 error
	var s25 string
	var r25 int
	var c25 rune
	var x26, y26 int
	var t26 int
	var n26 int
	var str26 string
	var l26 []rune
	var i26 int
	var err26 error
	var s26 string
	var r26 int
	var c26 rune
	var x27, y27 int
	var t27 int
	var n27 int
	var str27 string
	var l27 []rune
	var i27 int
	var err27 error
	var s27 string
	var r27 int
	var c27 rune
	var x28, y28 int
	var t28 int
	var n28 int
	var str28 string
	var l28 []rune
	var i28 int
	var err28 error
	var s28 string
	var r28 int
	var c28 rune
	var x29, y29 int
	var t29 int
	var n29 int
	var str29 string
	var l29 []rune
	var i29 int
	var err29 error
	var s29 string
	var r29 int
	var c29 rune
	var x30, y30 int
	var t30 int
	var n30 int
	var str30 string
	var l30 []rune
	var i30 int
	var err30 error
	var s30 string
	var r30 int
	var c30 rune
	var x31, y31 int
	var t31 int
	var n31 int
	var str31 string
	var l31 []rune
	var i31 int
	var err31 error
	var s31 string
	var r31 int
	var c31 rune
	var x32, y32 int
	var t32 int
	var n32 int
	var str32 string
	var l32 []rune
	var i32 int
	var err32 error
	var s32 string
	var r32 int
	var c32 rune
	var x33, y33 int
	var t33 int
	var n33 int
	var str33 string
	var l33 []rune
	var i33 int
	var err33 error
	var s33 string
	var r33 int
	var c33 rune
	var x34, y34 int
	var t34 int
	var n34 int
	var str34 string
	var l34 []rune
	var i34 int
	var err34 error
	var s34 string
	var r34 int
	var c34 rune
	var x35, y35 int
	var t35 int
	var n35 int
	var str35 string
	var l35 []rune
	var i35 int
	var err35 error
	var s35 string
	var r35 int
	var c35 rune
	var x36, y36 int
	var t36 int
	var n36 int
	var str36 string
	var l36 []rune
	var i36 int
	var err36 error
	var s36 string
	var r36 int
	var c36 rune
	var x37, y37 int
	var t37 int
	var n37 int
	var str37 string
	var l37 []rune
	var i37 int
	var err37 error
	var s37 string
	var r37 int
	var c37 rune
	var x38, y38 int
	var t38 int
	var n38 int
	var str38 string
	var l38 []rune
	var i38 int
	var err38 error
	var s38 string
	var r38 int
	var c38 rune
	var x39, y39 int
	var t39 int
	var n39 int
	var str39 string
	var l39 []rune
	var i39 int
	var err39 error
	var s39 string
	var r39 int
	var c39 rune
	var x40, y40 int
	var t40 int
	var n40 int
	var str40 string
	var l40 []rune
	var i40 int
	var err40 error
	var s40 string
	var r40 int
	var c40 rune
	var x41, y41 int
	var t41 int
	var n41 int
	var str41 string
	var l41 []rune
	var i41 int
	var err41 error
	var s41 string
	var r41 int
	var c41 rune
	var x42, y42 int
	var t42 int
	var n42 int
	var str42 string
	var l42 []rune
	var i42 int
	var err42 error
	var s42 string
	var r42 int
	var c42 rune
	var x43, y43 int
	var t43 int
	var n43 int
	var str43 string
	var l43 []rune
	var i43 int
	var err43 error
	var s43 string
	var r43 int
	var c43 rune
	var x44, y44 int
	var t44 int
	var n44 int
	var str44 string
	var l44 []rune
	var i44 int
	var err44 error
	var s44 string
	var r44 int
	var c44 rune
	var x45, y45 int
	var t45 int
	var n45 int
	var str45 string
	var l45 []rune
	var i45 int
	var err45 error
	var s45 string
	var r45 int
	var c45 rune
	var x46, y46 int
	var t46 int
	var n46 int
	var str46 string
	var l46 []rune
	var i46 int
	var err46 error
	var s46 string
	var r46 int
	var c46 rune
	var x47, y47 int
	var t47 int
	var n47 int
	var str47 string
	var l47 []rune
	var i47 int
	var err47 error
	var s47 string
	var r47 int
	var c47 rune
	var x48, y48 int
	var t48 int
	var n48 int
	var str48 string
	var l48 []rune
	var i48 int
	var err48 error
	var s48 string
	var r48 int
	var c48 rune
	var x49, y49 int
	var t49 int
	var n49 int
	var str49 string
	var l49 []rune
	var i49 int
	var err49 error
	var s49 string
	var r49 int
	var c49 rune
	var x50, y50 int
	var t50 int
	var n50 int
	var str50 string
	var l50 []rune
	var i50 int
	var err50 error
	var s50 string
	var r50 int
	var c50 rune
	var x51, y51 int
	var t51 int
	var n51 int
	var str51 string
	var l51 []rune
	var i51 int
	var err51 error
	var s51 string
	var r51 int
	var c51 rune
	var x52, y52 int
	var t52 int
	var n52 int
	var str52 string
	var l52 []rune
	var i52 int
	var err52 error
	var s52 string
	var r52 int
	var c52 rune
	var x53, y53 int
	var t53 int
	var n53 int
	var str53 string
	var l53 []rune
	var i53 int
	var err53 error
	var s53 string
	var r53 int
	var c53 rune
	var x54, y54 int
	var t54 int
	var n54 int
	var str54 string
	var l54 []rune
	var i54 int
	var err54 error
	var s54 string
	var r54 int
	var c54 rune
	var x55, y55 int
	var t55 int
	var n55 int
	var str55 string
	var l55 []rune
	var i55 int
	var err55 error
	var s55 string
	var r55 int
	var c55 rune
	var x56, y56 int
	var t56 int
	var n56 int
	var str56 string
	var l56 []rune
	var i56 int
	var err56 error
	var s56 string
	var r56 int
	var c56 rune
	var x57, y57 int
	var t57 int
	var n57 int
	var str57 string
	var l57 []rune
	var i57 int
	var err57 error
	var s57 string
	var r57 int
	var c57 rune
	var x58, y58 int
	var t58 int
	var n58 int
	var str58 string
	var l58 []rune
	var i58 int
	var err58 error
	var s58 string
	var r58 int
	var c58 rune
	var x59, y59 int
	var t59 int
	var n59 int
	var str59 string
	var l59 []rune
	var i59 int
	var err59 error
	var s59 string
	var r59 int
	var c59 rune
	var x60, y60 int
	var t60 int
	var n60 int
	var str60 string
	var l60 []rune
	var i60 int
	var err60 error
	var s60 string
	var r60 int
	var c60 rune
	var x61, y61 int
	var t61 int
	var n61 int
	var str61 string
	var l61 []rune
	var i61 int
	var err61 error
	var s61 string
	var r61 int
	var c61 rune
	var x62, y62 int
	var t62 int
	var n62 int
	var str62 string
	var l62 []rune
	var i62 int
	var err62 error
	var s62 string
	var r62 int
	var c62 rune
	var x63, y63 int
	var t63 int
	var n63 int
	var str63 string
	var l63 []rune
	var i63 int
	var err63 error
	var s63 string
	var r63 int
	var c63 rune
	var x64, y64 int
	var t64 int
	var n64 int
	var str64 string
	var l64 []rune
	var i64 int
	var err64 error
	var s64 string
	var r64 int
	var c64 rune
	var x65, y65 int
	var t65 int
	var n65 int
	var str65 string
	var l65 []rune
	var i65 int
	var err65 error
	var s65 string
	var r65 int
	var c65 rune
	var x66, y66 int
	var t66 int
	var n66 int
	var str66 string
	var l66 []rune
	var i66 int