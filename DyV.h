#include <vector>
#include <iostream>
 template <typename T>
 int Busqueda_binaria(T x, std::vector<T>&a, int ini, int fin){
	if(ini<=fin){
		int mid=(ini+fin)/2;
		if(a[mid]==x){
			return mid;
		}else if(a[mid]>x){
			return Busqueda_binaria(x,a,ini,mid-1);
		}else{
			return Busqueda_binaria(x,a,mid+1,fin);
		}
	}
	std::cout<<"No encontrado\n";
	return -1;
 }
template <typename T>
int Busqueda_binaria_INV(T x, std::vector<T>&a, int ini, int fin){
        if(fin> ini){
                std::cout<<"Elemento no encontrado"<<std::endl;
                return -1;
        }else{
                int mid=(ini+fin)/2;
                if(a[mid]==x){
                        return mid;
                }else if(a[mid]<x){
                        return Busqueda_binaria_INV(x,a,ini,mid-1);
                }else{
                        return Busqueda_binaria_INV(x,a,mid+1,fin);
                }
        }
 }
template <typename T>
int Partition(std::vector<T>&v,int ini,int fin){
        T x= v[fin];
        int i = ini;
        for(int j=ini;j<fin;j++){
                if(v[j]<=x){
                        T aux = v[i];
                        v[i]=v[j];
                        v[j]=aux;
                        i++;
                }
        }
        T aux=v[i];
        v[i]=v[fin];
        v[fin]=aux;
        return i;
}
template <typename T>
void Quicksort(std::vector<T>&v,int ini, int fin){
	if(ini<fin){
		int pivot= Partition(v,ini,fin);
		Quicksort(v,ini,pivot-1);
		Quicksort(v,pivot+1,fin);
	}
}

