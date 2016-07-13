#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N,M;
vector<int> a[32001];
int indgree[32001];

int main() {
  scanf("%d %d",&N,&M);
  for (int i=0; i<M; i++) {
    int ta,tb;
    scanf("%d %d",&ta,&tb);
    a[ta].push_back(tb);
    indgree[tb]+=1;
  }

queue<int> q;
for (int i=1; i<=N; i++) {
  if (indgree[i]==0) q.push(i);
}

for (int k=0; k<N; k++) {
  int x=q.front();
  q.pop();
  printf("%d ",x);

  for (int i=0; i<a[x].size(); i++) {
    int y=a[x][i];
    indgree[y]-=1;
    if (indgree[y]==0) {
      q.push(y);
    }
  }
}

printf("\n");
return 0;
}
