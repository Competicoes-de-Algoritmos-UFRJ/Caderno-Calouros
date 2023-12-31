#include <bits/stdc++.h>

using namespace std;

int main(){

    // funciona como um conjunto, não possui elementos repetidos, (quase) todas as funções são O(logN)
    set<int> s;

    //funciona exatamente como um set, porém aceita elementos repetidos
    multiset<int> s;

    s.insert(1); //insere elemento

    s.erase(1); //remove elemento

    s.clear(); //remove todos os elementos; 0(N)

    s.empty() //checa se o set está vazio; O(1)

    s.size() //tamanho do set; O(1)

    s.count(x); //quantidade de vezes que x está presente no set (O(logN)) ou no multiset (O(N))

    auto it = s.find(x); //ponteiro para um elemento com mesmo valor de x, se não houver aponta para s.end()

    auto it = s.lower_bound(x); //ponteiro para o primeiro elemento com valor maior ou igual a x, se não houver aponta para s.end();

    auto it = s.upper_bound(x); //ponteiro para o primeiro elemento com valor maior que x, se não houver aponta para s.end();

    cout << *it << endl; //printar valor do ponteiro
    
    //também pode usar erase em um iterador, é recomendado esta forma, quando for um multiset, se não, todos os elementos com valor x serão removidos
    s.erase(it);

    //printa todos os elementos; O(N)
    for(int i:s){
        cout << i << " ";
    }
    
    //printa todos os elementos; O(N)
    for(auto it=s.begin(); it!=s.end(); it++){
        cout << *it << " ";
    }

    return 0;
}
