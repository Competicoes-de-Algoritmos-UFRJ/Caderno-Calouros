vector<pair<int, pair<int, int> > > arestas(m);

for(int i=0; i<m; i++){
    cin >> arestas[i].second.first >> arestas[i].second.second >> arestas[i].first;
}

sort(arestas.begin(), arestas.end());

long long int resp=0;

for(int i=0; i<m; i++){
    int a = arestas[i].second.first;
    int b = arestas[i].second.second;
    
    int c = arestas[i].first;

    if(find(a)!=find(b)){
        fusao(a, b);
        resp+=c;
    }
}
