def printing(line_1,line_2,last):
     i=last
     print("\n(Line number, Station number)\n")
     print("("+str(i)+","+str(n)+")",end=" ")
     for j in range(n-2,-1,-1):
         if i==1:
             i=line_1[j]
             print("--> ("+str(i)+","+str(j+1)+")",end=" ")
         else:
             i=line_2[j]
             print("--> ("+str(i)+","+str(j+1)+")",end=" ")

def quickest(e,x,a1,a2,t1,t2,n):
     f1=[]
     f2=[]
     line_1=[]
     line_2=[]
     f1.append(e[0]+a1[0])
     f2.append(e[1]+a2[0])
     for j in range(1,n):
         if f1[j-1]+a1[j]<=f2[j-1]+t2[j-1]+a1[j]:
             f1.append(f1[j-1]+a1[j])
             line_1.append(1)
         else:
             f1.append(f2[j-1]+a1[j]+t2[j-1])
             line_1.append(2)
         if f1[j-1]+a2[j]+t1[j-1]>=f2[j-1]+a2[j]:
             f2.append(f2[j-1]+a2[j])
             line_2.append(2)
         else:
             f2.append(f1[j-1]+a2[j]+t1[j-1])
             line_2.append(1)
     if f1[n-1]+x[0]<=f2[n-1]+x[1]:
         fast=f1[n-1]+x[0]
         last=1
     else:
         fast=f2[n-1]+x[1]
         last=2
     printing(line_1[:],line_2[:],last)
     return(fast)

n=int(input())
e=list(map(int,input().strip().split()))[:2]
x=list(map(int,input().strip().split()))[:2]
a1 = list(map(int,input().strip().split()))[:n]
a2 = list(map(int,input().strip().split()))[:n]
t1 = list(map(int,input().strip().split()))[:n-1]
t2 = list(map(int,input().strip().split()))[:n-1]
min=quickest(e[:],x[:],a1[:],a2[:],t1[:],t2[:],n)
print("\nOptimal Cost :",min)
