import heapq as hq

def conv(li_dict,m):
  heap_dict=[i for i in li_dict.values()]
  if m==0: hq.heapify(heap_dict)
  elif m==1:
    a=hq.heappop(heap_dict)
    for key, value in li_dict.items():
      if a == value:
        temp=key
  new_dict=[]
  for i in range(0,len(heap_dict)):
    for k,v in li_dict.items():
      if v==heap_dict[i] and (k,v) not in new_dict:
        new_dict.append((k,v))
  new_dict=dict(new_dict)
  if m==1: return (new_dict,a,temp)
  return (new_dict)


n=int(input("Enter source vertex: "))
rows, cols = (9,9)
G = [[0 for i in range(cols)] for j in range(rows)]
G[0][1]=4;G[0][7]=8;G[1][0]=4;G[1][2]=8;G[1][7]=11;G[2][1]=8;G[2][3]=7;G[2][5]=4;G[2][8]=2;G[3][2]=7;
G[3][4]=9;G[3][5]=14;G[4][3]=9;G[4][5]=10;G[5][2]=4;G[5][3]=14;G[5][4]=10;G[5][6]=2;G[6][5]=2;G[6][7]=1;
G[6][8]=6;G[7][0]=8;G[7][1]=11;G[7][6]=1;G[7][8]=7;G[8][2]=2;G[8][6]=6;G[8][7]=7;
dist={}
par={}
vis=[]
buff={}
for i in range(0,9):
  dist[i]=float('inf')
  par[i]=None
dist[n]=0
dist=conv(dist,0)

for i in range(0,9):
  dist,a,temp=conv(dist,1)
  print("Node finished = ",temp)
  for j in range(0,9):
    if G[temp][j]!=0 and j not in vis:
      if dist[j]>=a+G[temp][j]:
        par[j]=temp
        dist[j]=a+G[temp][j]
        dist=conv(dist,0)
  vis.append(temp)
  buff[temp]=a

print("Visited nodes: ",vis)
print("Shortest distance of nodes from source: ",buff)
print("Parent of nodes: ",par)
