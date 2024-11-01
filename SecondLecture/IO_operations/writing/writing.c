#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEN 50
#define N_STUD 2

typedef struct student {
    char name[LEN+1];
    unsigned int student_id;
    float average;
}student_t;

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

    fp = fopen("file.txt","w");
    if(fp == NULL){
        printf("File does not exist");
        exit(1);
    }
    fprintf(fp,"Students:\n");
    for(int i = 0; i<N_STUD;i++){
        fprintf(fp,"%s %d %f\n",students[i].name, students[i].student_id,students[i].average);
    }
    fclose(fp);

    return 0;
}