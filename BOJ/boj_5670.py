import sys

class Node:
    def __init__(self,chr):
        self.chr=chr#해당 노드의 문자
        self.child={}#해당 노드의 자식들
        # self.len=0#해당 노드의 자식수
        self.check=False#문자열의 끝인지.

class Trie:
    def __init__(self):
        self.root=Node('')

    #트라이 구조 만들기
    def insert_Word(self,word):
        node = self.root
        for w in word:
            if w not in node.child:#해당노드의 자식들에 해당 문자가없다면
                #노드만들기
                new=Node(w)
                node.child[w]=new
                node=new
            else:#있다면 노드만 교체
                node=node.child[w]
        node.check=True

    #최소입력
    def search(self,word):
        cnt=0
        current=self.root
        for w in word:
            current=current.child[w]
            if len(current.child)>1 or current.check:#해당노드의 자식이 둘 이상이거나 다른단어의 끝이라면
                cnt+=1
        return cnt

while 1:
    t = Trie()
    words=[]
    #입력처리
    try:n=int(sys.stdin.readline())
    except:break

    for _ in range(n):
        s=sys.stdin.readline().rstrip()
        t.insert_Word(s)
        words.append(s)
    result = 0
    for word in words:
        result+=t.search(word)

    print("%.2f" % (result/n))
