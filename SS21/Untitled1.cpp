#include <stdio.h>
struct Car{
	char model[50];
	int year;
	char prince[50];
};
int main(){
	struct Car xe[]={
		{"Van", 1999, "$3000"},
		{"Mazda 3", 2015, "$2700"},
		{"Honda Civic", 2020, "$8000"}
	};
	int n=3;
	for (int i=0;i<n;i++){
		printf("%-15s | %-10d | %-12s \n",
		        xe[i].model,xe[i].year,xe[i].prince);
	}
}	
