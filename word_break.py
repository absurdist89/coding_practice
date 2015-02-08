#/bin/python

def IsValidText(i, n, d, data, split, is_valid):
	if i in is_valid:
		return is_valid[i];
	for j in range(i,n):
		if data[i:j+1] in d:
			if (IsValidText(j+1, n, d, data, split, is_valid)):
				print "valid text from %d" %i;
				is_valid[i] = True;
				split.append(j);
				return True;
		#else:
			#print data[i:j+1], "not found in dictionary";
	is_valid[i] = False;
	return False;

d = ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"] 
d = set(d);
is_valid = {};
split = [];
data = raw_input();
is_valid[len(data)] = True;

if (IsValidText(0, len(data), d, data, split, is_valid)):
	j = 0;
	split.sort();
	for i in split:
		print data[j:i+1],
		j = i + 1;
else:
	print "Not valid text";
	print split;

