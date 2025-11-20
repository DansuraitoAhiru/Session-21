#include <stdio.h>
struct Student{
	char name[50];
	int age;
	float grade;
};
int main(){
	struct Student student1 ={
		"Mat Chinh", 69, 9.69
	};
	printf("Ten: %s | Tuoi: %d | Diem TB: %.2f ",
	       student1.name,student1.age,student1.grade);
}
