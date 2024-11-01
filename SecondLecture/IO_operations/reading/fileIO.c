#include <stdio.h>
#include <stdlib.h>

#define LEN 1000

int main(){
    FILE *fp;
    char row[LEN+1];
    fp = fopen("file.txt","r");
    if(fp == NULL){
        printf("Mother fucker");
        exit(1);
    }
    //Method:1  Reading row-by-row
    printf("Reading row by row\n");
    while(fgets(row,LEN,fp)!= NULL){
        printf("%s\n",row);
    }
    rewind(fp);

    //Merhod:2 Reading word-by-word
    printf("Reading word by word\n");
    while(fscanf(fp,"%s",row)!= EOF){
        printf("%s\n",row);
    }
    rewind(fp);

    //Merhod:3 Reading character-by-character
    char ch;
    printf("Reading character-by-character\n");
    while((ch=getc(fp))!=EOF){
        printf("%c\n",ch);
    }
    fclose(fp);


    return 0;
}
