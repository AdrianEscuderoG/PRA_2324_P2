#include <vector>
#include <iostream>
int min(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}
void cambio(int N,int v[], int M,int S[]){
	int** matriz= new int* [N];
        for(int i=0;i<N;i++)
                matriz[i]= new int[M+1];
        for(int i=0;i<N;i++)
                matriz[i][0]=0;
	std::cout<<"Hasta aqui bien \n";
        for(int i=0;i<N;i++){
                for(int j=1;j<(M+1);j++)
                        matriz[i][j]=-1;
	}
	std::cout<<"Hasta aqui bien \n";

	for(int i=1;i<(M+1);i++){
		if(i>=v[0] && matriz[0][i-v[0]]!=-1)
			matriz[0][i]=1+matriz[0][i-v[0]];
	}
	std::cout<<"Hasta aqui bien \n";

	for(int i=1;i<N;i++){
		for (int j=1;j<(M+1);j++){
			if(j<v[i] || matriz[i][j-v[i]]==-1){
				matriz[i][j]=matriz[i-1][j];
			}else if(matriz[i-1][j]!=-1){
				matriz[i][j]=min(matriz[i-1][j],1+matriz[i][j-v[i]]);
			}else{
				matriz[i][j]=1+matriz[i][j-v[i]];
			}
		}
	}
	for(int i=0;i<N;i++){
		S[i]=0;
	}
	int i=N-1;
	int j=M;
	while(i>=0 && j!=0){
		if(i==0 || matriz[i][j]!=matriz[i-1][j]){
			S[i]++;
			j-=v[i];
		}else{
		i--;
		}
	}
	return;
}



int main(){
	int N;
	int cantidad;
	std::cout<<"¿Cuántas monedas diferentes?:\n";
	std::cin>>N;
	int v[N];
	for(int i=0;i<N;i++){
		std::cout<<"Moneda nº"<<i+1<<": ";
		std::cin>>v[i];
	}
	std::cout<<"¿Cuánto a devolver?:\n";
        std::cin>>cantidad;
	int solucion[N];
	cambio(N,v,cantidad,solucion);
	for(int i=0;i<N;i++)
		std::cout<<v[i]<<":"<<solucion[i]<<"\n";
	return 0;
}
