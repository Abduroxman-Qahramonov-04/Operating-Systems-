#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50
#define N_STUD 2

typedef struct student{
    char name[LEN+1];
    unsigned int student_id;
    float average;
} student_t;

int main(){
    FILE *fp;
    student_t students[N_STUD];
    //Filling the array
    strcpy(students[0].name,"Abdurokhman");
    students[0].student_id = 14252;
    students[0].average = 25.9;

    strcpy(students[1].name,"Jack");
    students[1].student_id = 14322;
    students[1].average = 23.5;

    fp = fopen("file.bin","w");
    if(fp == NULL){
        printf("File does not exists");
        exit(1);
    }
    fwrite(students,sizeof(student_t),N_STUD,fp);
    fclose(fp);

    fp = fopen("file.bin","r");
    if(fp == NULL){
        printf("File does not exists");
        exit(1);
    }
    int index = 0;
    while(fread(&students[index],sizeof(student_t),1,fp)==1){
        index++;
    }
    fclose(fp);
    for(int i = 0; i<index;i++){
        printf("%s %d %f\n",students[i].name,students[i].student_id,students[i].average);
    }

    return 0;
}