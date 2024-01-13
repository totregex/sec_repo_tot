X=[1,2,3,4,5]
def reverse(X):
    for k in reversed(range(len(X))):
        print(2*X[k], end=' ')
reverse(X)
l=[100,900,300,400,500]
print()
start=1
sum=0
for c in range(start,4):
    sum=sum+l[c]
    print(c,":",sum)
    sum=sum+l[0]*10
    print(sum)
s="banana"
print(s[3:3])
A=['SDP','Sensors','DLD','Probability','C']
A.pop(2)
A=set(A)
A.discard("Probability")
print(A)
s=s[::-1]
print(s)


