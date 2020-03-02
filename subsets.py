A = [1, 2, 3, 4, 5]

S = []
for a in A:
	curr = [[a]]
	for s in S:
		curr.append(s + [a])

	S += curr

print(S)