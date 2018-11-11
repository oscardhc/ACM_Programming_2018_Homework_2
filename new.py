def g(a, b):
	if b == 0 : 
		return a;
	else :
		return g(b, a%b);

a = 1000
b = 245

print g(a, b);

ans = 1
for i in range(1, 101):
	ans = ans * i

print ans
