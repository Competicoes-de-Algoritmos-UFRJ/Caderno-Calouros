#include <bits/stdc++.h>

using namespace std;

int main(){

    // funciona como um dicionário, podemos declarar valores a chaves, (quase) todas as funções são O(logN)
    map<string, int> m;

    //primeiro tipo de dado será o da chave, e o segundo o do valor

    //insere elemento
    m["Tiago"] = 10;
    m.insert({"Tiago", 1});

    m.erase("Tiago"); //remove elemento

    m.clear(); //remove todos os elementos; 0(N)

    m.size(); //tamanho do map; O(1)

    auto it = m.find("Tiago"); //ponteiro para um elemento com mesmo valor de x, se não houver aponta para m.end()

    //também pode usar erase em um iterador
    m.erase(it);

    //printa todos os elementos; O(N)
    for(pair<string, int> i:m){
        cout << i.first << " " << i.second << "  ";
    }
    
    //printa todos os elementos; O(N)
    for(auto it=m.begin(); it!=m.end(); it++){
        cout << it->first << " " << it->second << "  ";
    }

    return 0;
}
