vector<ll> dist(n, 1e18);

priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
pq.push({0,0});
dist[0] = 0;

// achar o menor caminho entre o 0 e o n-1

// vector<int> pre(n, -1);

while(!pq.empty()){

	int atual = pq.top().second; ll custo_total = pq.top().first;
	pq.pop();
	
	if(custo_total > dist[atual]) continue;

	for(pair<ll,int> next: graph[atual]){
	
		ll prox = next.second, peso = next.first;
		if(custo_total + peso < dist[prox]){
			ll prox_custo = custo_total + peso;
			pq.push({prox_custo, prox});
			dist[prox] = prox_custo;
		}
	}
}
