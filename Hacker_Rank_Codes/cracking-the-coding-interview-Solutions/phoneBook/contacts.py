# For each find "partial" operation, print the number of contact names starting with partial on a new line.
# 4
# add hack
# add hackerrank
# find hac
# find hak
# 2
# 0

def main():
	n = int(input())
	i = 0
	contactsList = list()
	while i < n:
		string = input().split(" ")
		if string[0] == "add":
			contactsList.append(string[1])
		
		else:
			count = 0
			# for item in contactsList:
			# 	if string[1] not in item:
			# 		continue
			# 	else:
			# 		count = count + 1
			# print(count)
			temp = [s for s in contactsList if string[1] in s]
			print(len(temp))
		i = i+1

	
if __name__=="__main__":
	main()
