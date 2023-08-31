//problem: https://cses.fi/problemset/task/1158/
//top-down leva TLE ):

const int mxn = 1e3+5;
const int mxm = 1e5+5;

int n, k, values[mxn], prices[mxn], dp[mxn][mxm];

// Top-Down Approach
int solve(int i, int cap){ // i é o índice do livro atual, e cap é a capacidade atual da mochila

    //definindo os casos bases
    if(cap<0) return -INF; //impossible case
    if(i>n) return 0; // no more books

    //aplicando a dp
    if(dp[i][cap]!=-1) return dp[i][cap]; //state already calculated

    //definindo as alternativas(transições)
    int pega = values[i] + solve(i+1, cap-prices[i]); //pego o livro atual, incluo o valor do livro e diminuo a capacidade da minha mochila
    int nao = solve(i+1, cap); //não pego o livro, capacidade continua a mesma

    return dp[i][cap]=max(pega, nao); //a resposta é o máximo entre as duas alternativas
}

// Bottom-Up Approach
void build(){
    
    //IMPORTANTE:
    //lembrar que dp[i][cap] SEMPRE define a melhor resposta com os estados i e cap
    //Tente usar a intuição quando for montar as transições

    //definindo casos bases
    dp[0][0]=0; //quando eu não tenho nenhum livro e a capacidade é 0, a resposta é 0

    for(int i=1; i<=n; i++){ //vou passando por cada livro
        for(int cap=0; cap<=k; cap++){ //e por cada capacidade possível
            
            int nao = dp[i-1][cap]; //se eu não pegar o livro de indice i, 
                                    //a melhor resposta será aquela, que não conta com o livro atual,
                                    //e tem a mesma capacidade da mochila

            int pega = -INF;

            if(prices[i]<=cap){ //se eu consigo comprar o livro

                pega = values[i] + dp[i-1][cap-prices[i]]; //quando eu pego, eu adiciono o valor do livro e acrescento
                                                           //a melhor resposta sem contar o livro atual, e com a capacidade reduzida de
                                                           //prices[i], já que para eu pegar o livro atual, eu vou gastar prices[i] de capacidade
            }

            dp[i][cap]=max(pega, nao); //máximo entre pegar ou não pegar
        }
    }
}

int main(){
    fastio;
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> values[i];
    }
  
    for(int i=1; i<=n; i++){
        cin >> prices[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(1, k) << endl;


    memset(dp, 0, sizeof(dp));
    build();

    cout << dp[n][k] << endl;
    return 0;
}
