for(int i = 0; i < m; i++){
	cin >> edges[i][0] >> edges[i][1] >> edges[i][2]; edges[i][0]--; edges[i][1]--;
}

int N = n-1;
while(N--){
	for(int i = 0; i < m; i++){
		ll a = edges[i][0], b = edges[i][1], custo = edges[i][2];        
		// if(dist[a] == 1e18) continue;
		
		if(dist[a] + custo < dist[b]){
			dist[b] = dist[a] + custo;
			pre[b] = a;
		}
	}
}

int ciclo = -1;

for(int i = 0; i < m; i++){
	int a = edges[i][0], b = edges[i][1], custo = edges[i][2];        
	// if(dist[a] == 1e18) continue;
	
	if(dist[a] + custo < dist[b]){
		dist[b] = dist[a] + custo;
		pre[b] = a;
		ciclo = a;
	}
}

if(ciclo == -1){
	cout << "NO\n";
	return 0;
}

cout << "YES\n";
