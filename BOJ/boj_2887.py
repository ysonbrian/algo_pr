import sys

#크루스칼에 필요한 유니온 파인드
def Find(x):
    if p[x]==x:
        return x
    else:
        y=Find(p[x])
        p[x]=y
        return y

def Union(x,y):
    x=Find(x)
    y=Find(y)
    if x!=y:
        p[y]=x


N=int(sys.stdin.readline())
s_location=[]
p=[i for i in range(N)]
e=[]
for i in range(N):
    x,y,z=map(int,sys.stdin.readline().split())
    s_location.append([x,y,z])


for i in range(N-1):
    for j in range(i+1,N):
        #모든 경우의 간선을 구해준다.
        x=abs(s_location[i][0]-s_location[j][0])
        y=abs(s_location[i][1]-s_location[j][1])
        z=abs(s_location[i][2]-s_location[j][2])
        e.append([min(x,y,z),i,j])

#크루스칼 알고리즘
e.sort(key=lambda x:x[0])#거리를 기준으로 정렬
count=0
result=0
for dis,s,e in e:
    if Find(s)!=Find(e):
        result+=dis
        Union(s,e)
    if count==N-1:
        break

print(result)