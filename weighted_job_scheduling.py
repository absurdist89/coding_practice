from operator import itemgetter
import bisect

def bin_search(arr, val):
	#print arr;
	i  = bisect.bisect_left(arr, val);
	#print val,"at index",i
	return i;

def find_max_profit(arr, n, prof):
	global stimes;
	if (n >= len(arr)):
		return 0;
	if prof[n]:
		return prof[n];
	(start_time, finish_time, profit) = arr[n]
	if (n == (len(arr) - 1)):
		prof[n] = profit;
		return profit;
	prof[n] = max(find_max_profit(arr, n+1, prof), 
		find_max_profit(arr, bin_search(stimes, finish_time), prof) + profit);
	return prof[n];

arr = [];
for i in range(0,1000):
	arr.append((i, i+2, i*10 + 1));

prof = [None for x in arr];
arr.sort(key=itemgetter(0))
stimes = [start_time for (start_time,_,_) in arr]
print stimes
print find_max_profit(arr, 0, prof)
