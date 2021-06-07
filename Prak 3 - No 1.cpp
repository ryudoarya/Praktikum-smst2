//R. Yudo Arya Kusuma//
//   20051297013   //
//D4MI // 2020A //


//- Membuat Program Perpustakaan -//

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>




using namespace std;
struct databuku
{
	char judul[20],pengarang[20],penerbit[10],tahun[10];
	struct databuku *back;
	struct databuku *next;
};

struct databuku *head,*tail;

int input_data() 
{
	struct databuku *tampung,*awal;
	int j=0;char jawab[2];
	while(1) 
	{
		awal=(struct databuku*)malloc(sizeof(struct databuku));
		fflush(stdin);
		printf("Judul Buku     		: ");gets(awal->judul);
		printf("Nama Pengarang      : ");gets(awal->pengarang);
		printf("Nama Penerbit       : ");gets(awal->penerbit);
		printf("Tahun Input Data	: ");gets(awal->tahun);
		puts("");
		if(j==0)
		{
			awal->next=NULL;
			awal->back=NULL;
			head=awal;
			tampung=head;
			tail=awal;
		} else {
			tampung->next=awal;
			awal->next=NULL;
			awal->back=tampung;
			tail=awal;
			tampung=awal;
		}
		printf("Ada data lagi (y/t)  :");scanf("%s",&jawab);
		if((strcmp(jawab,"Y")==0) || (strcmp(jawab,"y")==0)) {
			j++;continue;
		}else if((strcmp(jawab,"T")==0) || (strcmp(jawab,"t")==0))
		break;
	}
}

int hapus_buku(){
	struct databuku *hapus,*sbl,*stl;
	char cari[20];
	if(head==NULL)
	puts("List Belum Ada. Silahkan buat data!");
	else{
		fflush(stdin);
		printf("Data yang akan dihapus? (judul);  ");gets(cari);
		hapus=head;
		if(strcmp(hapus->judul,cari)==0){
			head=head->next;
			free(hapus);
		}
	}
}

int tambah_data(){
	struct databuku *baru;
	int j=0;char jawab[2];
	while(1){
		baru=(struct databuku*)malloc(sizeof(struct databuku));
		fflush(stdin);
		printf("Judul Buku     	 : ");gets(baru->judul);
		printf("Nama Pengarang 	 : ");gets(baru->pengarang);
		printf("Nama Penerbit  	 : ");gets(baru->penerbit);
		printf("Tahun Input Data : ");gets(baru->tahun);
		puts("");
		if(j==0||j!=0){
			baru->next=NULL;
		tail->next=baru;
		baru->back=tail;
		tail=baru;
		}
		printf("Ada data lagi (y/t)  :");scanf("%s",&jawab);
		if((strcmp(jawab,"Y")==0 || (strcmp(jawab,"y")==0))) {
			j++;continue;
		}else if((strcmp(jawab,"T")==0) || (strcmp(jawab,"t")==0))
		break;
	}
}


int tampil_buku(){
	struct databuku *tampil;
	printf("      Judul Buku\t\tPengarang\t\tPenerbit\t\tTahun\n");
	tampil=head;
	while(tampil!=NULL) {
		printf("%s\t\t%s\t\t%s\t\t%s\n",tampil->judul,tampil->pengarang,tampil->penerbit,tampil->tahun);
		tampil=tampil->next;
	}
	return 0;
}

int cari_buku(){
	struct dtbuku *cari;
	char telusur[20];
	printf("      Judul Buku\t\tPengarang\t\tPenerbit\t\tTahun\n");
	printf("Data yang dicari? (judul):  ");gets(telusur);
	
}

int main(){
	int a;
	char b[2];
	ulang :
		puts("                                  Menu :");
		puts("<1> input data <2> tambah data <3> edit data <4> hapus data <5> tampil list");
		puts("<6> cari data  <7> keluar");
		    printf("Masukkan menu yang ingin dipilih ");scanf("%d",&a);
		    switch(a){
		    	case 1 : 
				{
				input_data();
				puts("");
				break;
				}
				
		    	case 2 : 
				{
				tambah_data();
				puts("");
				break;
			    }
			    
		    	case 3 : 
				{
				puts("");
				break;
			    }
			    
		    	case 4 : 
				{
				goto hapus;
				break;
			    }
			    
		    	case 5 : 
				{
				goto hapus;
				break;
			    }
			    
		    	case 6 : 
				{
				puts("");
				break;
				}
				
		    	case 7 : 
				{
				goto exit;
				break;
			    }
			}
			goto ulang;
			hapus :
				tampil_buku();
				puts("Apakah ingin mengolah data? (y/t)");fflush(stdin);scanf("%s",&b);
				if((strcmp(b,"Y")==0)||(strcmp(b,"y")==0))
				    goto ulang;
				else goto exit;
				exit :
				puts("                        Anda akan keluar dari program ");
				puts("                 Silahkan pencet tombol enter pada keyboard ");
				getch();
				return 0;
			}
