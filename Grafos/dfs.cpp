void dfs(int x){
    vis[x]=1;

    for(int i:vizinhos[x]){
        if(vis[i]==0){
            dfs(i);
        }
    }
}
