#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

const int mxn = 1e5+5;

int n, dist[mxn], excen[mxn];
vector<int> adj[mxn];

void calc_dist(int x){
    for(int i=1; i<=n; i++){
        dist[i]=0;
    }
    dfs(x, 0);
}

void dfs(int x, int pai){
    for(int i:adj[x]){
        
        if(i==pai) continue;

        dist[i]=dist[x]+1;

        dfs(i, x);
    }
}

int main(){

    cin >> n;

    for(int i=1; i<n; i++){
        int a, b;

        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    int maior=0, menor=INF, ponta_1=0, ponta_2=0;
    int diam, centro;

    calc_dist(1); //calculando distância para o vértice 1

    //o vértice mais distante do vértice 1, será a primeira ponta do diâmetro
    for(int i=1; i<=n; i++){
        if(dist[i]>maior){
            maior = dist[i];

            ponta_1 = i;
        }
    }

    calc_dist(ponta_1); //calculando distância para a primeira ponta

    //o vértice mais distante da primeira ponta, será a segunda ponta do diâmetro, e distância entre as duas será igual ao diâmetro
    //a excentricidade do vértice será igual ao máximo entre a distância dele da primeira com a segunda ponta
    
    maior=0;
    for(int i=1; i<=n; i++){
        //nesse momento estamos igualando a excentricidade a distância da primeira ponta, e depois iremos comparar com a segunda
        excen[i]=dist[i];

        if(dist[i]>maior){
            maior=dist[i];

            ponta_2=i;
        }
    }
    diam = maior;

    cout << ponta_1 << " " << ponta_2 << " " << diam << endl;

    calc_dist(ponta_2); //calculando distância para a segunda ponta

    //como havia dito, a excentricidade será o máximo entre as distâncias da primeira e segunda ponta
    for(int i=1; i<=n; i++){
        excen[i]=max(excen[i], dist[i]);
    }

    //o centro será o vértice com a menor excentricidade
    for(int i=1; i<=n; i++){
        if(excen[i]<menor){
            menor=excen[i];
            centro=i;
        }
    }
    cout << centro << endl;
    return 0;
}
