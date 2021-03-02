//R. Yudo Arya Kusuma//
   //20051397013//
   ///2020-A///
   
#include<iostream>
#include<string.h>
using namespace std;

int main(){
	cout << "PROGRAM STACK MEMBALIK KALIMAT" << endl;
	cout << "============================" << endl;
		char kalimat[100];
		cout <<"Masukan Kalimat :"; 
		cin.getline (kalimat , sizeof (kalimat) );
		cout <<"Hasil Pembalikan	:";
		int x = strlen(kalimat);
		for(int i=x-1;i>=0;i--){
		cout <<kalimat[i];
 }
}
