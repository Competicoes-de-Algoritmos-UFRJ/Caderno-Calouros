//v é o vector no qual estão os elementos
//x é o número que eu quero procurar

int busca(vector<int> &v, int x){
    int l = 0, r = (int)v.size()-1; //declaro o intervalo da busca binária

    while(l<=r){
        int mid = (l+r)/2;

        if(v[mid]==x){
            return mid;

        }else if(v[mid]>x){
            r = mid-1;
            
        }else{
            l = mid+1;
        }
    }

    return -1;
}
