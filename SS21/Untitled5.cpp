#include <stdio.h>
struct Product{
	char name[50];
	float price;
	int quatity;
};
int main(){
	struct Product sp[5]={
		{"Snack", 10.000, 50},
		{"Miruku", 20.000, 69},
		{"Cheese", 45.000, 201},
		{"Bottle", 18.000, 99},
		{"Lemon", 4.000, 999}
	};
	int n=5;
	float sum=0;
	for(int i=0;i<n;i++){
		int money=sp[i].price*sp[i].quatity;
		sum+=money;
    }
    printf("Tong gia tri cac san pham la: %.3f VND", sum);
}
