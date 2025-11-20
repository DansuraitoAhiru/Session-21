#include <stdio.h>
struct Book{
	char title[100];
	char author[50];
	float price;
};

int main(){
	struct Book books[3]={
		{"Yuri la 1 nen van minh xau", "Nguoi thich dua xe", 128.000},
		{"Duy Cong Truong va cuoc chinh phat dia cau", "Ngiu be nho cua Duy", 390.000},
		{"Holy Trinity: Dark rising", "Dansuraito Ahiru", 75.500}
	};
	int n=3;
	for(int i=0;i<n;i++){
	    printf("%-45s | %-40s | %-10.3f\n",
		    books[i].title,books[i].author,books[i].price);
	}
}	
