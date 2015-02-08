from bisect import *

def print_triangles(a):
	for i in  range(0, len(a)):
		for j in range(i + 1, len(a) - 1):
			plausible_end = bisect(a, a[i] + a[j] - 1);
#			print "for (%d, %d), index = %d" %(a[i], a[j], plausible_end);
			for k in range(j + 1, plausible_end):
					print (a[i], a[j], a[k]);

arr = [10, 21, 22, 100, 101, 200, 300]
arr.sort();
print arr;
print_triangles(arr);


