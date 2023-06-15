#include <bits/stdc++.h>

using namespace std;

int main(){

    // funciona como um conjunto, não possui elementos repetidos, (quase) todas as funções são O(logN)
    set<int> s;

    s.insert(1); //insere elemento

    s.erase(1); //remove elemento(se não houver esse elemento, vai ocorrer um erro, logo se não tiver certeza, utilizar o find e checar primeiro)

    s.clear(); //remove todos os elementos; 0(N)

    auto it = s.find(1); //ponteiro para um elemento com mesmo valor de x, se não houver aponta para s.end()

    auto it = s.lower_bound(1); //ponteiro para o primeiro elemento com valor maior ou igual a x, se não houver aponta para s.end();

    auto it = s.upper_bound(1); //ponteiro para o primeiro elemento com valor maior que x, se não houver aponta para s.end();

    s.erase(it); //também pode usar erase em um iterador

    return 0;
}
