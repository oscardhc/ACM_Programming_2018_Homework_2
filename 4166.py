from random import *

with open('4166.in','w') as f:
	T = 3
	print >>f,T
	for _ in range(T):
		n = 300
		m = 300
		p = 4
		print >>f,n,m,p
		for i in range(n):
			for j in range(m):
				if i == 0 and j == 0 :
					print >>f,1,
				elif i == n-1 and j == n-1 :
					print >>f,4,
				else :
					print >>f,randint(2,3),
			print >>f,' '

