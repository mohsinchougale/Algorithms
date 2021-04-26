def fracknap(arr):
  li={}
  k=W
  cost=0
  for j in vpi:
    temp=dicta[j]
    if arr[temp]!=0:
      if k>=weight[temp]:
        cost=cost+co[temp]
        k=k-weight[temp]
        li[temp+1]=weight[temp]
      else:
        cost=cost+j*k
        li[temp+1]=k
        break
  return cost

def normknap(arr):
  li={}
  k=W
  cost=0
  #print(vpi)
  for i in vpi:
    temp=dicta[i]
    if arr[temp]!=0:
      if k>=weight[temp]:
        cost=cost+co[temp]
        k=k-weight[temp]
        li[temp+1]=weight[temp]
      else: break
  return cost

n=int(input("Enter the number of items: "))
weight = list(map(int,input("Enter their weights: ").strip().split()))[:n]
co = list(map(int,input("Enter their profits: ").strip().split()))[:n]
W=int(input("weight of the sack: "))

dicta={}
vpi=[]
for i in range(n):
  vpi.append(co[i]/weight[i])
  dicta[co[i]/weight[i]]=i
vpi.sort(reverse=True)

print("----------------------------------")
arr=[1,0,1,0]
print(fracknap(arr))
print(normknap(arr))
