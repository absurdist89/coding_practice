from random import *

def next_greater_element(a, out):
	s = [];
	for i in range(0, len(a)):
		if (len(s) == 0) or (a[i] <= a[s[0]]):
			s.insert(0, i);
		else:
			while len(s) and (a[s[0]] < a[i]):
				out[s[0]] = a[i];
				s.pop(0);
			s.insert(0, i);
	del s;
	return;

a = (randint(0, (1 << 30)) for x in range(0, 1 << 30))
out = [-1 for x in a];
next_greater_element(a, out);
print [(a[i], out[i]) for i in range(0, len(a))];
	

