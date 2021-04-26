def quickest(n,s1,s2,t1,t2):
    f1=[]
    f2=[]

    f1.append(int(s1[0]))
    f2.append(int(s2[0]))

    for j in range(1,n):
        if f1[j-1]+s1[j]<=f2[j-1]+t2[j-1]+s1[j]:
            f1.append(int(f1[j-1]+s1[j]))

        else:
            f1.append(int(f2[j-1]+t2[j-1]+s1[j]))


        if f2[j-1]+s2[j]<=f1[j-1]+t1[j-1]+s2[j]:
            f2.append(int(f2[j-1]+s2[j]))

        else:
            f2.append(int(f1[j-1]+t1[j-1]+s2[j]))


    cost=0
    if f1[n-1]<= f2[n-1]:
        cost=f1[n-1]
    else:
        cost=f2[n-1]
    print("\nOutput\n")
    print(cost)
    print("\n")


cases=int(input())
while(cases-1):
    n=int(input())
    s1=list(map(int,input().split()))
    s2=list(map(int,input().split()))
    t1=list(map(int,input().split()))
    t2=list(map(int,input().split()))

    quickest(n,s1,s2,t1,t2)
