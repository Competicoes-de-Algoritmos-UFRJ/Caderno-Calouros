while(m--){
	ll a,b,c; cin >> a >> b >> c; a--; b--;
	graph[a][b] = min(graph[a][b], c);
	graph[b][a] = min(graph[b][a], c);
}

for(int i = 0; i < n; i++) graph[i][i] = 0;

for(int k = 0; k < n; k++){
	for(int i = 0; i < n; i++){
		if(graph[i][k] == 1e18) continue;
		for(int j = 0; j < n; j++){
			if(graph[k][j] == 1e18) continue;
			graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		}
	}
}
