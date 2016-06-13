//
//  main.cpp
//  FinalAlgoritmos
//
//  Created by Miguel Cuellar on 5/6/16.
//  Copyright © 2016 Miguel Cuellar. All rights reserved.
//

#include <iostream>
#import <vector>
#include <stack>
using namespace std;

int n;
pair<int, string> arr[100];
struct persona{
    string nombre;
    string nombrehijo;
    string nombrepadre;
    int edad;
    int edadacta;
    bool encontrado;
    bool hijo;
    
    persona(){
        nombre="";
        nombrepadre="";
        edad=0;
        encontrado=false;
        hijo=false;
        edadacta=0;
        
    }
    
};

vector<persona> personas;


void profundidad(persona pers){
    stack<int> encontrados;
    for (int i=0; i<=personas.size(); i++) {
        if(personas[i].nombrepadre==pers.nombre){
            personas[i].edad=pers.edad-personas[i].edadacta;
            personas[i].edadacta=personas[i].edad;
            encontrados.push(i);
        }
    }
    while (!encontrados.empty()) {
        profundidad(personas[encontrados.top()]);
        encontrados.pop();
    }
}

int main() {
    
    
    string nombrepadre, nombrehijo;
    int edad, Berny;
    cin>>n;
    
    for (int i=0; i<n*2; i++) {
        personas.push_back(persona());
    }
    int icont=0;
    
    do {
        
        cin>>nombrepadre>>nombrehijo>>edad;
        if (nombrepadre=="Berny") {
            Berny=icont;
            personas[icont].edad=100;
        }
        personas[icont].nombre=nombrepadre;
        personas[icont].nombrehijo=nombrehijo;
        
        icont++;
        personas[icont].nombre=nombrehijo;
        personas[icont].nombrepadre=nombrepadre;
        personas[icont].hijo=true;
        personas[icont].edadacta=edad;
        icont++;
        
    } while (icont<n*2);
    
    profundidad(personas[Berny]);
    
    int ic=0;
    for (int i=0; i<personas.size(); i++) {
        if (personas[i].hijo) {
            arr[ic].first=personas[i].edad;
            arr[ic].second=personas[i].nombre;
            ic++;
        }
    }
    sort(arr,arr+ic);
    for (int i=ic-1; i>=0; i--) {
        cout<<arr[i].second<<" "<<arr[i].first<<endl;
        cout<<endl;
    }
    
    
    
    

    return 0;
}
