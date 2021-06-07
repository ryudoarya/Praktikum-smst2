//R. Yudo Arya Kusuma//
//   20051297013   //
//D4MI // 2020A //


//- Membuat Program Tempat Parkir -//

#include <iostream>
#include <malloc.h>



using namespace std;
struct node 
{
	int info;
	struct node *link;
}*front = NULL, *rear = NULL;

void insert ();
int del ();
void display();

void insert (int num)
{
	struct node *temp;
	temp = (struct node*) malloc (sizeof(struct node));
	
	if (temp==NULL){
		cout << "Ruang antrian penuh";
		return;
	}
	
	temp -> info = num;
	temp -> link = NULL;
	
	if (front == NULL){
		front = temp;
	}else {
		rear -> link = temp;
	}
	rear = temp; 
}

int del ()
{
	int num;
	struct node *temp;
	
	if(front == NULL){
		cout << "Ruang antrian kosong";
		return 0;
	}
	temp = front;
	num = temp->info;
	front = front->link;
	free (temp);
	return num;
}

void display ()
{
	struct node *p;
	
	if (front == NULL){
		cout << "Ruang antrian kosong";
		return;
	}
	
	p = front;
	cout << "\nQueue Elements:\n" << endl;
	while (p != NULL){
		cout << p->info << endl;
		p = p->link;
	}
}

int main ()
{
	int pil;
	int num;
	
	do {
	cout << endl;
		cout << "        PROGRAM ANTRIAN MOBIL       " << endl;
		cout << "====================================" << endl;
		cout << "1. Masukkan nomor plat mobil" << endl;
		cout << "2. Mengeluarkan nomor plat mobil" << endl;
		cout << "3. Menampilkan data nomor plat mobil" << endl;
		cout << "4. Keluar" << endl;
		
		cout << "Masukkan Pilihan (1/2/3/4) : ";
		cin >> pil;

		switch (pil){
		case 1 :
		{
			cout << "\nMasukkan Nomor Plat: ";
			cin >> num;
			insert(num);
			break;
		}
		case 2 :
		{
			cout << endl;
			del();
			break;
		}
		case 3 :
 		{
			cout << endl;
			display();
			break;
		}
		}
	}
	while (pil != 4);
}
