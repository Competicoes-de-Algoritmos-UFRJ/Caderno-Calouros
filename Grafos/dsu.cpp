void build(){ // indexado em 1
    for(int i=1; i<=n; i++){
        pai[i]=i;
        peso[i]=1;
    }
}

int find(int x){
    if(x==pai[x]) return x;

    return pai[x]=find(pai[x]);
}

void fusao(int x, int y){
    x = find(x);
    y = find(y);

    if(x==y) return;

    if(peso[x]>=peso[y]){
        pai[y]=x;
        peso[x]+=peso[y];
    }else{
        pai[x]=y;
        peso[y]+=peso[x];
    }
}
