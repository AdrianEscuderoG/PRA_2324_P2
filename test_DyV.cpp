#include "DyV.h"
using namespace std;

int main(){
	vector<int>a={2,6,3,7,8,9,1,4,5,0};
        for(int i=0;i<a.size();i++){
                cout<<a[i]<<" ";
        }
	cout<<endl;
	Quicksort(a,0,9);
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}cout<<endl;
	cout<<Busqueda_binaria(0,a,0,9)<<endl;
	cout<<endl;
	float c=0.2;
	vector<float>b={0.2,0.6,0.3,0.7,0.8,0.9,0.1,0.4,0.5,0.0};
        for(int i=0;i<b.size();i++){
                cout<<b[i]<<" ";
        }
	cout<<endl;
	Quicksort(b,0,9);
        for(int i=0;i<b.size();i++){
                cout<<b[i]<<" ";
        }cout<<endl;
	cout<<Busqueda_binaria(c,b,0,9)<<endl;
        cout<<endl;
	return 0;
}
