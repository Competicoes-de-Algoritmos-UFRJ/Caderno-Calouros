#include <bits/stdc++.h>

using namespace std;

int main(){

    // funciona como um array dinâmico
    vector<int> v;

    v.push_back(1); //insere elemento no final do vector; O(1)

    v.pop_back(); //remove o último elemento do vector; O(1)

    sort(v.begin(), v.end()); //ordena vector em ordem crescente; O(NlogN)

    vector<int> v(10); //cria vector de 10 posições com o valor 0; O(N)

    vector<int> v(10, -1); //cria vector de 10 posições com o valor -1; O(N)

    // printa todos os elementos do vector
    for(int i:v){
        cout << i << " ";
    }

    // printa todos os elementos do vector
    for(int i=0; i<(int)v.size(); i++){
        cout << v[i] << " ";
    }

    //ponteiro para o primeiro elemento com valor maior ou igual a x, se não houver aponta para v.end()
    auto it = lower_bound(v.begin(), v.end(), x);

    if(it!=v.end()){ //se o elemento existir
    
        cout << *it << endl; //printa o valor do elemento

        cout << it-v.begin() << endl; //printa a posição do elemento indexada em 0
    }

    //ponteiro para o primeiro elemento com valor maior que x, se não houver aponta para v.end()
    auto it = upper_bound(v.begin(), v.end(), x);

    return 0;
}
