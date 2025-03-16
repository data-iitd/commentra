hcell, wcell = map(int, input().split())
hpaint, wpaint = map(int, input().split())
nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint)
nwhite = (hcell * wcell) - nblack
print(nwhite)
# <END-OF-CODE>
