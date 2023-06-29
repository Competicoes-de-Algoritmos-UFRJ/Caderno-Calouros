const int mxn = 1e5+5;

// vis[i] indica se o vértice i já foi visitado, se for igual a 1, quer dizer que sim, se for igual a 0, não
// adj[i] é a lista de adjacência do vértice i
int vis[mxn];
vector<int> adj[mxn];

void dfs(int x){
    vis[x]=1;

    for(int i:adj[x]){
        if(vis[i]==0){
            dfs(i);
        }
    }
}
