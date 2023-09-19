const int mxn = 1e5+5;

int v[mxn], tree[4*mxn], lazy[4*mxn];

void unlazy(int node, int l, int r){
    if(lazy[node]){
        tree[node]+=(r-l+1)*lazy[node];
        if(l!=r){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void build(int node, int l, int r){ //constroi a seg inicial
    if(l==r){
        tree[node]=v[l];
        return;
    }

    int mid=(l+r)/2;
    
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    tree[node]=tree[2*node]+tree[2*node+1];
}

void upd(int node, int l, int r, int pos, int val){ //update em um ponto
    if(l==r){
        tree[node]=val;
        return;
    }
    int mid=(l+r)/2;

    if(pos<=mid){
        upd(2*node, l, mid, pos, val);
    }else{
        upd(2*node+1, mid+1, r, pos, val);
    }
    tree[node]=tree[2*node]+tree[2*node+1];
}

void upd(int node, int l, int r, int a, int b, int val){ //update em range
    unlazy(node, l, r);

    if(r<a || l>b) return;

    if(l>=a && r<=b){
        lazy[node]=val;
        unlazy(node, l, r);
        return;
    }

    int mid=(l+r)/2;

    upd(2*node, l, mid, a, b, val);
    upd(2*node+1, mid+1, r, a, b, val);

    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node, int l, int r, int a, int b){ //query em range
    unlazy(node, l, r);

    if(r<a || l>b) return 0;

    if(l>=a && r<=b) return tree[node];

    int mid=(l+r)/2;

    return query(2*node, l, mid, a, b)+query(2*node+1, mid+1, r, a, b);
}
