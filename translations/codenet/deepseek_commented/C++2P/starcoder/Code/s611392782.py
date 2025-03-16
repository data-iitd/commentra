
# This function multiplies consecutive digits until it encounters a '+' or the end of the string.
def mul(str, idx):
	res = str[idx]-'0'
	while(idx+1 < len(str) and str[idx+1]=='*'):
		idx += 2
		res *= str[idx]-'0'
	return res

# This function adds the results of multiple calls to mul by handling '+' operations.
def add(str, idx):
	res = mul(str, idx)
	while(idx+1 < len(str) and str[idx+1] == '+'):
		idx += 2
		res += mul(str, idx)
	return res

# This function performs the same operations as add but uses a different approach.
def bob(str, idx):
	res = str[idx]-'0'
	while(idx+1 < len(str)):
		if(str[idx+1] == '+') res += str[idx+2]-'0'
		else                  res *= str[idx+2]-'0'
		idx += 2
	return res

while True:
	s = raw_input()
	if s == "