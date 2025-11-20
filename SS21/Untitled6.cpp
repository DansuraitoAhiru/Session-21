#include <stdio.h>
#include <string.h>
struct Student{
	char name[50];
	int age;
	float grade;
};
int main(){
	struct Student hs[5]={
		{"Shuten Douji", 10000, 7.69},
		{"Morgan le Fay", 4000, 9.99},
		{"Melusine", 4540000000000, 9.54},
		{"Bao Han", 20, 8.88},
		{"Jeanne d'Arc", 18, 9.44},
	};
	int n=5, found=0;
	char search[50];
	printf("Nhap ten hoc sinh can tim: ");
	fgets(search, sizeof(search), stdin);
	search[strcspn(search, "\n")]=0;
	for(int i=0;i<n;i++){
		if(strcmp(hs[i].name, search)==0){
			found=1;
			printf("Tim thay thong tin hoc sinh: \nTen: %s | Tuoi: %d | Diem TB: %.2f",
	            hs[i].name,hs[i].age,hs[i].grade);
	    }
	}
	if(!found){
		printf("Ko tim thay hoc sinh nay!");
	}
}
