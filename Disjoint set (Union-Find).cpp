
int find(int par[], int x) {
    if(par[x]==x){
        return x;
    }
    return par[x]=find(par,par[x]);
}

void unionSet(int par[], int x, int z) {
    int x_parent=find(par,x);
    int z_parent=find(par,z);
    if(x_parent!=z_parent){
        par[x_parent]=z_parent;
    }
    
}
