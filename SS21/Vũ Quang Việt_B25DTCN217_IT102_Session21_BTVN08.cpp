#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	int id;
	char name[50];
	float importPrice;
	float exportPrice;
	int stock;
}Product;

void enterInfo(Product *sp, int *length, int *currentId){
	int n;
	printf("Nhap so luong san pham: ");
	scanf("%d", &n);
	getchar();
	for(int i=0;i<n;i++){
		Product product;
		product.id=*currentId;
		(*currentId)++;
		
		printf("Nhap thong tin san pham %d: \n", i+1);
		printf("Nhap ten san pham: ");
		fgets(product.name, sizeof(product.name), stdin);
		product.name[strcspn(product.name, "\n")]=0;
		printf("Nhap gia goc cua san pham: ");
		scanf("%f", &product.importPrice);
		printf("Nhap gia ban san pham: ");
		scanf("%f", &product.exportPrice);
		while(getchar() != '\n');
		product.stock=0;
		sp[*length+i]=product;
	}
	*length+=n;
	printf("Nhap san pham thanh cong!\n");
}

void displayMenu(Product *sp, int length){
	if(length<-0){
		printf("Danh sach san pham rong");
		return;
	}
	printf("======================= Danh sach san pham ======================");
	for(int i=0;i<length;i++){
		printf("\nID: %d | Ten: %s | Gia nhap: %.2f | Gia ban: %.2f | So luong: %d \n",
		        sp[i].id,sp[i].name,sp[i].importPrice,sp[i].exportPrice,sp[i].stock);
	}
}

void addProduct(Product *sp, int length, float *revenue){
	int id, quantity;
	printf("Nhap id san pham muon them so luong: ");
	scanf("%d", &id);
	for(int i=0;i<length;i++){
		if(sp[i].id==id){
			printf("Nhap so luong muon mua: ");
			scanf("%d", &quantity);
			float totalMoney=sp[i].importPrice*quantity;
			if(*revenue-totalMoney<0){
				printf("Ko du tien\n");
				return;
			} else {
				sp[i].stock += quantity;
				*revenue -= totalMoney;
				printf("Nhap hang thanh cong!\n");
				return;
			}
		}
	}
	printf("Ko tim thay san pham co id=%d\n",id);
}

void updateProduct(Product *sp, int length){
	int id;
	printf("Nhap vao id muon sua: ");
	scanf("%d", &id);
	getchar();
	for(int i=0;i<length;i++){
		if(sp[i].id==id){
			Product product;
			product.id = sp[i].id;
			printf("Cap nhat ten san pham: ");
			fgets(product.name,sizeof(product.name),stdin);
			product.name[strcspn(product.name,"\n")] = 0 ;
			printf("Cap nhat gia goc cua san pham: ");
			scanf("%f",&product.importPrice);
			printf("Cap nhat gia ban san pham: ");
			scanf("%f",&product.exportPrice);
			while(getchar() != '\n');
			product.stock=sp[i].stock ;
			sp[i]=product ;
			printf("Cap nhat thanh cong \n");
			return ;
		}
	}
	printf("khong tim thay san pham co id = %d \n");
}

void sortPrice(Product *sp, int length){
	printf("1. Sap xep gia ban tang dan \n");
	printf("2. Sap xep gia ban giam dan \n");
	int choose ;
	printf("Lua chon cua ban la gi ? : ");
	scanf("%d",&choose);
	
	if(choose==1){
		for(int i=0 ;i<length-1 ;i++){
			for(int j=0 ;j<length-1-i ;j++ ){
				if(sp[j].exportPrice > sp[j+1].exportPrice){
					Product tmp = sp[j];
					sp[j] = sp[j+1];
					sp[j+1] = tmp ;
				}
			}
		}
		printf("Sap xep tang dan thanh cong \n");
	}else if (choose == 2){
		for(int i=0 ;i<length-1 ;i++){
			for(int j=0 ;j<length-1-i ;j++ ){
				if(sp[j].exportPrice < sp[j+1].exportPrice){
					Product tmp = sp[j];
					sp[j] = sp[j+1];
					sp[j+1] = tmp ;
				}
			}
		}
		printf("Sap xep giam dan thanh cong \n");
	} else {
		printf("Ko co lua chon %d \n", choose);
	}
}

void search(Product *sp,int length){
	while(getchar() != '\n');
	char name[50];
	printf("Nhap ten san pham muon tim : ");
	fgets(name,sizeof(name),stdin);
	name[strcspn(name,"\n")] = 0 ;
	for(int i=0;i<length ;i++){
		if(strcmp(sp[i].name, name) == 0){
			printf("Tim thay san pham : \n");
			printf("\nID: %d | Ten: %s | Gia nhap: %.2f | Gia ban: %.2f | So luong: %d \n",
		        sp[i].id,sp[i].name,sp[i].importPrice,sp[i].exportPrice,sp[i].stock);
				return ;
		}
	}
	printf("Khong tim thay san pham : %s \n",name);
}

void sellProduct(Product *sp, int length ,float *revenue){
	int id , quantity ;
	printf("Nhap ma san pham muon ban : ");
	scanf("%d",&id);
	for(int i=0 ;i<length ;i++){
		if(sp[i].id == id){
			printf("Nhap so luong san pham muon ban : ");
			scanf("%d",&quantity);
			if(sp[i].stock < quantity){
				printf("Khong du san pham \n");
				return ;
			}else {
				sp[i].stock -= quantity ;
				*revenue += (sp[i].exportPrice * quantity);
				if(sp[i].stock == 0){
					printf("Sau khi ban xong thì san pham nay het hang \n");
				}
				return ;
			}
		}
	}
	printf("Khong tim thay san pham co id = %d \n",id);
}			

int main(){
	float revenue=100000;
	Product sp[100];
	int length=0;
	int currentId=1;
	int choice;
	int flag=0;
	do{
		printf("\n================== Menu ===================");
		printf("\n1. Nhap thong tin san pham");
		printf("\n2. Hien thi danh sach san pham");
		printf("\n3. Nhap ten san pham");
		printf("\n4. Cap nhat thong tin san pham");
		printf("\n5. Sap xep san pham");
		printf("\n6. Tim kiem san pham");
		printf("\n7. Ban san pham (co the nhap so luong)");
		printf("\n8. Doanh thu hien tai");
		printf("\n9. Thoat");
		printf("\nLua chon cua ban la: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:{
				enterInfo(sp,&length,&currentId);
				flag=1;
				break;
			}
			case 2:{
				if(flag==0) printf("Chua nhap thong tin san pham! Vui long chon 1!\n");
				else displayMenu(sp,length);
				break;
			}
			case 3:{
				if(flag==0) printf("Chua nhap thong tin san pham! Vui long chon 1!\n");
				else addProduct(sp,length,&revenue);
				break;
			}
			case 4 : {
				if(flag==0) printf("Chua nhap thong tin san pham! Vui long chon 1!\n");
				else updateProduct(sp,length);
				break;
			}
			case 5 : {
				if(flag==0) printf("Chua nhap thong tin san pham! Vui long chon 1!\n");
				else sortPrice(sp,length);
				break;
			}
			case 6 : {
				if(flag==0) printf("Chua nhap thong tin san pham! Vui long chon 1!\n");
				else search(sp,length);
				break;
			}
			case 7 : {
				if(flag==0) printf("Chua nhap thong tin san pham! Vui long chon 1!\n");
				else sellProduct(sp,length,&revenue);
				break;
			}
			case 8 : {
				if(flag==0) printf("Chua nhap thong tin san pham! Vui long chon 1!\n");
				else printf("Doanh thu hien tai : %.2f \n",revenue);
				break;
			}
			case 9 : {
				printf("Thoat chuong trinh!");
				exit(0);
			}
			default : {
				printf("Lua chon khong dung !!!\n");
				break;
			}
		}
	}while(choice!=9);
}

