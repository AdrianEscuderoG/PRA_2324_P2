#include <iostream>
#include <vector>

int max(int a, int b){
	if(a<b){
		return b;
	}else{
		return a;
	}
}
void mochila(int N,int p[], int b[], int M,int s[]){
	int** matriz= new int* [N+1];
        for(int i=0;i<=N;i++)
                matriz[i]= new int[M+1];
        for(int i=0;i<=N;i++){
		matriz[i][0]=0;
	}
	for(int i=0;i<=M;i++){
		matriz[0][i]=0;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++)
			matriz[i][j]=-1;
	}
        std::cout<<"Hasta aqui bien \n";
	for(int i=1;i<=M;i++){
		if(i>=p[0])
			matriz[1][i]=b[0];	
	}
	for(int i=1;i<N;i++){
		for(int j=1;j<=M;j++){
			if(j<p[i]){
				matriz[i+1][j]=matriz[i][j];
			}else if(j>=p[i]){
				matriz[i+1][j]=max(matriz[i][j],b[i]+matriz[i][j-p[i]]);
			}
		}
	}
	int i=N;
	int j=M;
	while(i>0 && j!=0){
		if(matriz[i][j]>matriz[i-1][j]){
			s[i-1]=1;
			j-=p[i-1];
		}
		i--;
	}
}

int main(){

	int N, M;
	std::cout<<"¿Cuántos objetos?: ";
	std::cin>>N;
	std::cout<<"¿Cuánto peso máximo?: ";
        std::cin>>M;
	int p[N];
	int b[N];
	for(int i=0;i<N;i++){
		std::cout<<"\nObjeto nº"<<i+1<<":\npeso: ";
		std::cin>>p[i];
		std::cout<<"\nvalor: ";
                std::cin>>b[i];
	}
	int s[N];
	for(int i=0;i<N;i++)
                s[i]=0;
	mochila(N,p,b,M,s);
	std::cout<<"Objetos a llevar:\n";
	for(int i=0;i<N;i++)
		if(s[i]){
			std::cout<<"Objeto nº"<<i+1<<" con peso "<<p[i]<<"\n";
		}
	for(int i=0;i<N;i++)
		std::cout<<s[i]<<" ";	
	return 0;
}
