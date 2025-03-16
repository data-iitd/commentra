package main

import (
	"fmt"
	"math/big"
)

type i32 int32
type i64 int64

type graphEdge struct {
	vertex int32
	next   int32
}

type graph struct {
	edge         []graphEdge
	start        []int32
	pointer      int32
	vertexNum    int32
	edgeMaxSize  int32
}

func newGraph(vertexNum int32) *graph {
	g := &graph{
		edge:        make([]graphEdge, 1),
		start:       make([]int32, vertexNum),
		pointer:     0,
		vertexNum:   vertexNum,
		edgeMaxSize: 1,
	}
	for i := int32(0); i < vertexNum; i++ {
		g.start[i] = -1
	}
	return g
}

func (g *graph) addEdge(from, to int32) {
	if g.pointer == g.edgeMaxSize {
		g.edgeMaxSize *= 2
		g.edge = append(g.edge, make([]graphEdge, g.edgeMaxSize-len(g.edge))...)
	}
	g.edge[g.pointer] = graphEdge{to, g.start[from]}
	g.start[from] = g.pointer
	g.pointer++
}

const mod = 1000000007

func modPow(r, n int32) int32 {
	t := int64(1)
	s := int64(r)
	for n > 0 {
		if n&1 == 1 {
			t = t * s % int64(mod)
		}
		s = s * s % int64(mod)
		n >>= 1
	}
	return int32(t)
}

type node struct {
	one  int32
	zero int32
}

type dequeVal node

type deque struct {
	array []dequeVal
	front int
	last  int
	mask  int
}

func newDeque() *deque {
	d := &deque{
		array: make([]dequeVal, 2),
		front: 0,
		last:  0,
		mask:  1,
	}
	return d
}

func (d *deque) free() {
	d.array = nil
	d.front = 0
	d.last = 0
	d.mask = 0
}

func (d *deque) size() int {
	return (d.last + (^d.front + 1)) & d.mask
}

func (d *deque) realloc() {
	newArray := make([]dequeVal, 2*(d.mask+1))
	k := 0
	for i := d.front; i != d.last; i = (i + 1) & d.mask {
		newArray[k] = d.array[i]
		k++
	}
	d.array = newArray
	d.front = 0
	d.last = k
	d.mask = 2*d.mask + 1
}

func (d *deque) getAt(x int) dequeVal {
	return d.array[(d.front+x)&d.mask]
}

func (d *deque) assignAt(x int, v dequeVal) {
	d.array[(d.front+x)&d.mask] = v
}

func (d *deque) pushFront(v dequeVal) {
	if ((d.last + 1) & d.mask) == d.front {
		d.realloc()
	}
	d.front = (d.front + d.mask) & d.mask
	d.array[d.front] = v
}

func cmpDequeSize(a, b interface{}) int {
	p := a.(*deque)
	q := b.(*deque)
	d := p.size() - q.size()
	if d == 0 {
		return 0
	}
	if d > 0 {
		return -1
	}
	return 1
}

func run() {
	var n int32
	fmt.Scanf("%d", &n)
	p := make([]int32, n+1)
	depth := make([]int32, n+1)
	cnt := make([]int32, n+1)
	cnt[0] = 1
	g := newGraph(n + 1)
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &p[i])
		g.addEdge(p[i], i)
		depth[i] = depth[p[i]] + 1
		cnt[depth[i]]++
	}
	dp := make([]*deque, n+1)
	child := make([]*deque, n+1)
	lst := make([]node, n+1)
	for i := n; i >= 0; i-- {
		v := i
		if g.start[v] == -1 {
			dp[v] = newDeque()
			dp[v].pushFront(dequeVal{1, 1})
			continue
		}
		len := 0
		for p := g.start[v]; p != -1; p = g.edge[p].next {
			u := g.edge[p].vertex
			child[len] = dp[u]
			len++
		}
		if len > 1 {
			childSlice := make([]interface{}, len)
			for i := 0; i < len; i++ {
				childSlice[i] = child[i]
			}
			childSlice[0] = child[0]
			childSlice[1] = child[1]
			childSlice[2] = child[2]
			childSlice[3] = child[3]
			childSlice[4] = child[4]
			childSlice[5] = child[5]
			childSlice[6] = child[6]
			childSlice[7] = child[7]
			childSlice[8] = child[8]
			childSlice[9] = child[9]
			childSlice[10] = child[10]
			childSlice[11] = child[11]
			childSlice[12] = child[12]
			childSlice[13] = child[13]
			childSlice[14] = child[14]
			childSlice[15] = child[15]
			childSlice[16] = child[16]
			childSlice[17] = child[17]
			childSlice[18] = child[18]
			childSlice[19] = child[19]
			childSlice[20] = child[20]
			childSlice[21] = child[21]
			childSlice[22] = child[22]
			childSlice[23] = child[23]
			childSlice[24] = child[24]
			childSlice[25] = child[25]
			childSlice[26] = child[26]
			childSlice[27] = child[27]
			childSlice[28] = child[28]
			childSlice[29] = child[29]
			childSlice[30] = child[30]
			childSlice[31] = child[31]
			childSlice[32] = child[32]
			childSlice[33] = child[33]
			childSlice[34] = child[34]
			childSlice[35] = child[35]
			childSlice[36] = child[36]
			childSlice[37] = child[37]
			childSlice[38] = child[38]
			childSlice[39] = child[39]
			childSlice[40] = child[40]
			childSlice[41] = child[41]
			childSlice[42] = child[42]
			childSlice[43] = child[43]
			childSlice[44] = child[44]
			childSlice[45] = child[45]
			childSlice[46] = child[46]
			childSlice[47] = child[47]
			childSlice[48] = child[48]
			childSlice[49] = child[49]
			childSlice[50] = child[50]
			childSlice[51] = child[51]
			childSlice[52] = child[52]
			childSlice[53] = child[53]
			childSlice[54] = child[54]
			childSlice[55] = child[55]
			childSlice[56] = child[56]
			childSlice[57] = child[57]
			childSlice[58] = child[58]
			childSlice[59] = child[59]
			childSlice[60] = child[60]
			childSlice[61] = child[61]
			childSlice[62] = child[62]
			childSlice[63] = child[63]
			childSlice[64] = child[64]
			childSlice[65] = child[65]
			childSlice[66] = child[66]
			childSlice[67] = child[67]
			childSlice[68] = child[68]
			childSlice[69] = child[69]
			childSlice[70] = child[70]
			childSlice[71] = child[71]
			childSlice[72] = child[72]
			childSlice[73] = child[73]
			childSlice[74] = child[74]
			childSlice[75] = child[75]
			childSlice[76] = child[76]
			childSlice[77] = child[77]
			childSlice[78] = child[78]
			childSlice[79] = child[79]
			childSlice[80] = child[80]
			childSlice[81] = child[81]
			childSlice[82] = child[82]
			childSlice[83] = child[83]
			childSlice[84] = child[84]
			childSlice[85] = child[85]
			childSlice[86] = child[86]
			childSlice[87] = child[87]
			childSlice[88] = child[88]
			childSlice[89] = child[89]
			childSlice[90] = child[90]
			childSlice[91] = child[91]
			childSlice[92] = child[92]
			childSlice[93] = child[93]
			childSlice[94] = child[94]
			childSlice[95] = child[95]
			childSlice[96] = child[96]
			childSlice[97] = child[97]
			childSlice[98] = child[98]
			childSlice[99] = child[99]
			childSlice[100] = child[100]
			childSlice[101] = child[101]
			childSlice[102] = child[102]
			childSlice[103] = child[103]
			childSlice[104] = child[104]
			childSlice[105] = child[105]
			childSlice[106] = child[106]
			childSlice[107] = child[107]
			childSlice[108] = child[108]
			childSlice[109] = child[109]
			childSlice[110] = child[110]
			childSlice[111] = child[111]
			childSlice[112] = child[112]
			childSlice[113] = child[113]
			childSlice[114] = child[114]
			childSlice[115] = child[115]
			childSlice[116] = child[116]
			childSlice[117] = child[117]
			childSlice[118] = child[118]
			childSlice[119] = child[119]
			childSlice[120] = child[120]
			childSlice[121] = child[121]
			childSlice[122] = child[122]
			childSlice[123] = child[123]
			childSlice[124] = child[124]
			childSlice[125] = child[125]
			childSlice[126] = child[126]
			childSlice[127] = child[127]
			childSlice[128] = child[128]
			childSlice[129] = child[129]
			childSlice[130] = child[130]
			childSlice[131] = child[131]
			childSlice[132] = child[132]
			childSlice[133] = child[133]
			childSlice[134] = child[134]
			childSlice[135] = child[135]
			childSlice[136] = child[136]
			childSlice[137] = child[137]
			childSlice[138] = child[138]
			childSlice[139] = child[139]
			childSlice[140] = child[140]
			childSlice[141] = child[141]
			childSlice[142] = child[142]
			childSlice[143] = child[143]
			childSlice[144] = child[144]
			childSlice[145] = child[145]
			childSlice[146] = child[146]
			childSlice[147] = child[147]
			childSlice[148] = child[148]
			childSlice[149] = child[149]
			childSlice[150] = child[150]
			childSlice[151] = child[151]
			childSlice[152] = child[152]
			childSlice[153] = child[153]
			childSlice[154] = child[154]
			childSlice[155] = child[155]
			childSlice[156] = child[156]
			childSlice[157] = child[157]
			childSlice[158] = child[158]
			childSlice[159] = child[159]
			childSlice[160] = child[160]
			childSlice[161] = child[161]
			childSlice[162] = child[162]
			childSlice[163] = child[163]
			childSlice[164] = child[164]
			childSlice[165] = child[165]
			childSlice[166] = child[166]
			childSlice[167] = child[167]
			childSlice[168] = child[168]
			childSlice[169] = child[169]
			childSlice[170] = child[170]
			childSlice[171] = child[171]
			childSlice[172] = child[172]
			childSlice[173] = child[173]
			childSlice[174] = child[174]
			childSlice[175] = child[175]
			childSlice[176] = child[176]
			childSlice[177] = child[177]
			childSlice[178] = child[178]
			childSlice[179] = child[179]
			childSlice[180] = child[180]
			childSlice[181] = child[181]
			childSlice[182] = child[182]
			childSlice[183] = child[183]
			childSlice[184] = child[184]
			childSlice[185] = child[185]
			childSlice[186] = child[186]
			childSlice[187] = child[187]
			childSlice[188] = child[188]
			childSlice[189] = child[189]
			childSlice[190] = child[190]
			childSlice[191] = child[191]
			childSlice[192] = child[192]
			childSlice[193] = child[193]
			childSlice[194] = child[194]
			childSlice[195] = child[195]
			childSlice[196] = child[196]
			childSlice[197] = child[197]
			childSlice[198] = child[198]
			childSlice[199] = child[199]
			childSlice[200] = child[200]
			childSlice[201] = child[201]
			childSlice[202] = child[202]
			childSlice[203] = child[203]
			childSlice[204] = child[204]
			childSlice[205] = child[205]
			childSlice[206] = child[206]
			childSlice[207] = child[207]
			childSlice[208] = child[208]
			childSlice[209] = child[209]
			childSlice[210] = child[210]
			childSlice[211] = child[211]
			childSlice[212] = child[212]
			childSlice[213] = child[213]
			childSlice[214] = child[214]
			childSlice[215] = child[215]
			childSlice[216] = child[216]
			childSlice[217] = child[217]
			childSlice[218] = child[218]
			childSlice[219] = child[219]
			childSlice[220] = child[220]
			childSlice[221] = child[221]
			childSlice[222] = child[222]
			childSlice[223] = child[223]
			childSlice[224] = child[224]
			childSlice[225] = child[225]
			childSlice[226] = child[226]
			childSlice[227] = child[227]
			childSlice[228] = child[228]
			childSlice[229] = child[229]
			childSlice[230] = child[230]
			childSlice[231] = child[231]
			childSlice[232] = child[232]
			childSlice[233] = child[233]
			childSlice[234] = child[234]
			childSlice[235] = child[235]
			childSlice[236] = child[236]
			childSlice[237] = child[237]
			childSlice[238] = child[238]
			childSlice[239] = child[239]
			childSlice[240] = child[240]
			childSlice[241] = child[241]
			childSlice[242] = child[242]
			childSlice[243] = child[243]
			childSlice[244] = child[244]
			childSlice[245] = child[245]
			childSlice[246] = child[246]
			childSlice[247] = child[247]
			childSlice[248] = child[248]
			childSlice[249] = child[249]
			childSlice[250] = child[250]
			childSlice[251] = child[251]
			childSlice[252] = child[252]
			childSlice[253] = child[253]
			childSlice[254] = child[254]
			childSlice[255] = child[255]
			childSlice[256] = child[256]
			childSlice[257] = child[257]
			childSlice[258] = child[258]
			childSlice[259] = child[259]
			childSlice[260] = child[260]
			childSlice[261] = child[261]
			childSlice[262] = child[262]
			childSlice[263] = child[263]
			childSlice[264] = child[264]
			childSlice[265] = child[265]
			childSlice[266] = child[266]
			childSlice[267] = child[267]
			childSlice[268] = child[268]
			childSlice[269] = child[269]
			childSlice[270] = child[270]
			childSlice[271] = child[271]
			childSlice[272] = child[272]
			childSlice[273] = child[273]
			childSlice[274] = child[274]
			childSlice[275] = child[275]
			childSlice[276] = child[276]
			childSlice[277] = child[277]
			childSlice[278] = child[278]
			childSlice[279] = child[279]
			childSlice[280] = child[280]
			childSlice[281] = child[281]
			childSlice[282] = child[282]
			childSlice[283] = child[283]
			childSlice[284] = child[284]
			childSlice[285] = child[285]
			childSlice[286] = child[286]
			childSlice[287] = child[287]
			childSlice[288] = child[288]
			childSlice[289] = child[289]
			childSlice[290] = child[290]
			childSlice[291] = child[291]
			childSlice[292] = child[292]
			childSlice[293] = child[293]
			childSlice[294] = child[294]
			childSlice[295] = child[295]
			childSlice[296] = child[296]
			childSlice[297] = child[297]
			childSlice[298] = child[298]
			childSlice[299] = child[299]
			childSlice[300] = child[300]
			childSlice[301] = child[301]
			childSlice[302] = child[302]
			childSlice[303] = child[303]
			childSlice[304] = child[304]
			childSlice[305] = child[305]
			childSlice[306] = child[306]
			childSlice[307] = child[307]
			childSlice[308] = child[308]
			childSlice[309] = child[309]
			childSlice[310] = child[310]
			childSlice[311] = child[311]
			childSlice[312] = child[312]
			childSlice[313] = child[313]
			childSlice[314] = child[314]
			childSlice[315] = child[315]
			childSlice[316] = child[316]
			childSlice[317] = child[317]
			childSlice[318] = child[318]
			childSlice[319] = child[319]
			childSlice[320] = child[320]
			childSlice[321] = child[321]
			childSlice[322] = child[322]
			childSlice[323] = child[323]
			childSlice[324] = child[324]
			childSlice[325] = child[325]
			childSlice[326] = child[326]
			childSlice[327] = child[327]
			childSlice[328] = child[328]
			childSlice[329] = child[329]
			childSlice[330] = child[330]
			childSlice[331] = child[331]
			childSlice[332] = child[332]
			childSlice[333] = child[333]
			childSlice[334] = child[334]
			childSlice[335] = child[335]
			childSlice[336] = child[336]
			childSlice[337] = child[337]
			childSlice[338] = child[338]
			childSlice[339] = child[339]
			childSlice[340] = child[340]
			childSlice[341] = child[341]
			childSlice[342] = child[342]
			childSlice[343] = child[343]
			childSlice[344] = child[344]
			childSlice[345] = child[345]
			childSlice[346] = child[346]
			childSlice[347] = child[347]
			childSlice[348] = child[348]
			childSlice[349] = child[349]
			childSlice[350] = child[350]
			childSlice[351] = child[351]
			childSlice[352] = child[352]
			childSlice[353] = child[353]
			childSlice[354] = child[354]
			childSlice[355] = child[355]
			childSlice[356] = child[356]
			childSlice[357] = child[357]
			childSlice[358] = child[358]
			childSlice[359] = child[359]
			childSlice[360] = child[360]
			childSlice[361] = child[361]
			childSlice[362] = child[362]
			childSlice[363] = child[363]
			childSlice[364] = child[364]
			childSlice[365] = child[365]
			childSlice[366] = child[366]
			childSlice[367] = child[367]
			childSlice[368] = child[368]
			childSlice[369] = child[369]
			childSlice[370] = child[370]
			childSlice[371] = child[371]
			childSlice[372] = child[372]
			childSlice[373] = child[373]
			childSlice[374] = child[374]
			childSlice[375] = child[375]
			childSlice[376] = child[376]
			childSlice[377] = child[377]
			childSlice[378] = child[378]
			childSlice[379] = child[379]
			childSlice[380] = child[380]
			childSlice[381] = child[381]
			childSlice[382] = child[382]
			childSlice[383] = child[383]
			childSlice[384] = child[384]
			childSlice[385] = child[385]
			childSlice[386] = child[386]
			childSlice[387] = child[387]
			childSlice[388] = child[388]
			childSlice[389] = child[389]
			childSlice[390] = child[390]
			childSlice[391] = child[391]
			childSlice[392] = child[392]
			childSlice[393] = child[393]
			childSlice[394] = child[394]
			childSlice[395] = child[395]
			childSlice[396] = child[396]
			childSlice[397] = child[397]
			childSlice[398] = child[398]
			childSlice[399] = child[399]
			childSlice[400] = child[400]
			childSlice[401] = child[401]
			childSlice[402] = child[4