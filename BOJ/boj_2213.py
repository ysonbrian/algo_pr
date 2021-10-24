import sys
n=int(sys.stdin.readline())
node_value=[0]+list(map(int,sys.stdin.readline().split()))
Tree=[[] for _ in range(n+1)]
DP=[[0,0] for _ in range(n+1)]

for _ in range(n-1):#간선받기
    a,b=map(int,sys.stdin.readline().split())
    Tree[a].append(b)
    Tree[b].append(a)



check=[True for _ in range(n+1)]
def DFS(cur):
    check[cur]=False#방문체크
    DP[cur][0]=node_value[cur]#현재 노드 포함할때
    DP[cur][1]=0#현재 노드 포함하지 않을때
    for i in Tree[cur]:#연결된 노드 탐색
        if check[i]:#방문할수 있다면
            DFS(i)
            DP[cur][0]+=DP[i][1]#해당노드 포함했을때
            DP[cur][1]+=max(DP[i][0],DP[i][1])#해당노드 포함 안했을때


trace_result=[]
trace_check=[True for _ in range(n+1)]
def Trace(cur,pre):#현재노드와 이전노드가 포함되었는지 안되었는지 0:포함됨 1:포함안됨
    trace_check[cur]=False

    if pre==0:#이전노드가 포함되었다면
        for i in Tree[cur]:#현재노드는 포함할수없음
            if trace_check[i]:
                Trace(i,1)
    else:#이전노드가 포함되어있지않다면
        if DP[cur][0] > DP[cur][1]:  # 현재노드를 포함한 부분이 더크다면
            trace_result.append(cur)  # 현재노드 포함
            for i in Tree[cur]:
                if trace_check[i]:
                    Trace(i, 0)
        else:  # 현재노드를 포함하지 않은부분이 크다면
            for i in Tree[cur]:
                if trace_check[i]:
                    Trace(i, 1)



DFS(1)
print(max(DP[1][0],DP[1][1]))
Trace(1,1)#임의의 루트노드지정 ,이전노드가 없으므로 1로 둔다
trace_result.sort()#오름차순정렬
print(*trace_result)