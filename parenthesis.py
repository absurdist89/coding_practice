def isValid(s):
	l = [];
	complement = {'(':')', '{':'}', '[':']'};
	revcomplement = {')':'(', '}':'{', ']':'['};
	for c in s:
		if c in complement.keys():
			l.append(c);
		elif c in revcomplement.keys():
                        if ((len(l) != 0) and (complement[l[len(l) - 1]] == c)):
				l.pop();
			else:
				return False;
		else:
			return False;

	return (len(l) == 0);

print "%r" %isValid(raw_input());
