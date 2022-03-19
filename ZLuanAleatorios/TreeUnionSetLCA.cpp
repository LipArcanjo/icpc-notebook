//CODEFORCES EDACATIONAL 91 - E
#include<bits/stdc++.h>

using namespace std;

const int N = 200043;
const int L = 20;

vector<int> g[2 * N];
int p[2 * N];
int up[2 * N][L];
int idx[N];
int psum[N];
int cur[N];
int tin[2 * N];
int tout[2 * N];
int T = 0;

void dfs(int x, int y)
{
	tin[x] = T++;
	p[x] = y;
	up[x][0] = y;
	for(int i = 1; i < L; i++)
		up[x][i] = up[up[x][i - 1]][i - 1];
	for(auto z : g[x]){
        
        dfs(z, x);
    }
		
	tout[x] = T++;
}

bool is_ancestor(int x, int y)
{
	return tin[x] <= tin[y] && tout[x] >= tout[y];
}

int lca(int x, int y)
{
	if(is_ancestor(x, y))
		return x;
	for(int i = L - 1; i >= 0; i--)
		if(!is_ancestor(up[x][i], y))
			x = up[x][i];
	return p[x];
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &idx[i]);
		idx[i]--;
	}
	for(int i = 0; i < m; i++)
		cur[i] = i;
	for(int i = 0; i < m - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		int nidx = m + i;
		g[nidx].push_back(cur[x]);
		g[nidx].push_back(cur[y]);
		//isso funciona pq eh garantido que x e y exista
		cur[x] = nidx;
	}
	int root = m * 2 - 2;
	dfs(root, root);
	for(int i = 0; i < n - 1; i++)
	{
		int t = lca(idx[i], idx[i + 1]);
		if(t < m)
			psum[0]++;
		else
			psum[t - m + 1]++;
	}
	for(int i = 0; i < m - 1; i++)
		psum[i + 1] += psum[i];
	for(int i = 0; i < m; i++)
		printf("%d\n", n - 1 - psum[i]);
}