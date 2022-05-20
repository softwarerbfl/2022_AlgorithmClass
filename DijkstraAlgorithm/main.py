import math
inf=math.inf #무한대값

def dijkatra(n, w, visited):
    vnear=0

    #인덱스의 값을 vertex의 인덱스와 맞추기 위해 n+1개의 배열로 선언
    touch=[0]*(n+1) #경로에서 마지막 node의 index
    length=[inf]*(n+1) #최단 경로
    v=[0]*(n+1) #방문 여부

    for i in range(2,n+1):
        touch[i]=1
        length[i]=w[1][i]

    #i로 가는 길이가 최소일 때 min값을 바꾸어 준다.
    for a in range(n-1):
        min=inf
        for i in range(2,n+1):
            if length[i]>0 and length[i]<min:
                min=length[i]
                vnear=i
        for i in range(2,n+1):
            #i번째 vertex와 vnear번째 vertex를 잇는 선이 기존의 i번째 vertex까지의 최단경로보다 작으면 변경해준다.
            if length[vnear]+w[vnear][i]<length[i]:
                length[i]=length[vnear]+w[vnear][i]
                #최단 경로에 업데이트가 필요한 경우 초기화
                if v[i]==1:
                    visited[touch[i]][i]=False
                    visited[vnear][i] = True
                #처음 방문한 node인 경우 일반적으로 처리
                else:
                    visited[vnear][i] = True  # 해당 간선 방문 처리
                    v[i] = 1
                touch[i] = vnear

        #vnear의 최단 경로가 1에서 vnear까지의 길이와 같은 경우
        #즉 최단 경로가 시작점에서 자기 자신까지의 거리인 경우
        if length[vnear]==w[1][vnear]:
            visited[1][vnear]=True
            v[vnear]=1 #vnear방문 처리
        length[vnear]=-1 #방문한 vertex까지의 최단경로를 -1로 변경

#최단 경로의 edge들을 출력해주는 함수
def printEdge(v,n):
    print(n,"개의 node에 대한 경로 출력")
    for p in range(1, n+1):
        for q in range(n+1):
            if v[p][q] == True:
                print(p, "->", q)
######여기서부터 test case 확인######
w1={
    1:[0,0,7,4,6,1],
    2:[0,inf,0,inf,inf,inf],
    3:[0,inf,2,0,5,inf],
    4:[0,inf,3,inf,0,inf],
    5:[0,inf,inf,inf,1,0]
}
w2={
    1:[0,0,2,inf,1,3,inf],
    2:[0,inf,0,3,inf,inf,2],
    3:[0,inf,3,0,inf,inf,inf],
    4:[0,inf,inf,1,0,3,inf],
    5:[0,inf,5,2,inf,0,inf],
    6:[0,inf,inf,5,4,1,0]
}
w3={
    1:[0,0,6,2,inf],
    2:[0,inf,0,inf,1],
    3:[0,inf,3,0,5],
    4:[0,inf,inf,inf,0]
}
#edge방문 처리용 배열
visited1={
    1:[False,False,False,False,False,False],
    2:[False,False,False,False,False,False],
    3:[False,False,False,False,False,False],
    4:[False,False,False,False,False,False],
    5:[False,False,False,False,False,False]
}
visited2={
    1:[False,False,False,False,False,False,False],
    2:[False,False,False,False,False,False,False],
    3:[False,False,False,False,False,False,False],
    4:[False,False,False,False,False,False,False],
    5:[False,False,False,False,False,False,False],
    6:[False,False,False,False,False,False,False]
}
visited3={
    1:[False,False,False,False,False],
    2:[False,False,False,False,False],
    3:[False,False,False,False,False],
    4:[False,False,False,False,False]
}
dijkatra(5,w1,visited1)
printEdge(visited1,5)
dijkatra(6,w2,visited2)
printEdge(visited2,6)
dijkatra(4,w3,visited3)
printEdge(visited3,4)
