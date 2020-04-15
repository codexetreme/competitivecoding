s = input()

s = s.lower()

k = ['a','e','i','o','u','y']

p = ''
for i in s:
    if i not in k:
        p+='.' +i

print (p)