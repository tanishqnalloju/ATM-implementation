#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(void);
int view(void);
int menu(void);
/*Student Marks Program using files
*/


//structure for a student marks
/*struct student{
//int math, social, science, english, language;
int marks[5];
int age, section, grade;
char name[30];
float average;
}ssample, student;*/


int view(void){

    FILE *fp;
    fp = fopen("details.txt","rb");

    int vname, vgrade, vsection, vmarks[5], vtotal;
    float vaverage;

    int vnum;

    fscanf(fp, "%d", num);

    float vClassAverage=0;
    printf("\nName\tGrade\tSection\tMath\tScience\tSocial\tEnglish\tSports\tTotal\tAverage");

    do
    {
        fscanf(fp,"%s %d %d", vname, vgrade, vsection );
        printf("%s\t%d\t%d", vname, vgrade, vsection);
        for(int k=0;k<5;k++){
            fscanf(fp,"%d",vmarks[k]);
            printf("\t%d",vmarks[k]);
        }
        fscanf(fp, "%d %f", vtotal, vaverage);
        vClassAverage += vaverage;
        printf("\t%d\t%f", vtotal, vaverage);

    }
    while(!feof(fp));

    printf("%.2f", vClassAverage/total);

    /*char ch;
    while((ch = getc(fp))!= EOF){
        printf("%c",ch);
    }*/

    fclose(fp);


return 0;
}

int menu(void){
    char sname[30];
    int ssection, sgrade;
    int smarks[5];
    int num;

    int stotal = 0;
    float saverage= 0;

    printf("Enter number of students");
    scanf("%d",&num);
	FILE *fp;
    fp = fopen("details.txt","a+");

    fprintf(fp, "%d ", num);

    for(int i=0; i<num;i++){

    int stotal = 0;
    float saverage= 0;

    printf("Enter name");
    scanf("%s", sname);
    printf("\ngrade");
    scanf("%d",&sgrade);
    printf("\nsection");
    scanf("%d",&ssection);
    printf("\nMarks:");
    for(int j=0;j<5;j++){
        printf("Subject %d: ",j+1);
        scanf("%d",&smarks[j]);
        total+=smarks[j];
    }



	fprintf(fp, "%s",sname);
	fprintf(fp, "%d", sgrade);
	fprintf(fp, "%d", ssection);

	for(int j=0;j<5;j++)
	fprintf(fp, "%d", smarks);

	saverage = stotal/5;
	fprintf(fp, "%d %d", stotal, saverage);

    //fwrite(sname, sizeof(char), strlen(sname), fp);
    //fwrite(sgrade, sizeof(int), 1, fp);
    //fwrite(ssection, sizeof(int), 1, fp);
    //fwrite(smarks[5], sizeof(int), 5, fp);


    }
    fclose(fp);

    view();

return 0;
}

int main(void)
{
    //printf("Hello world!\n");
    printf("\nMenu:");
    printf("\n1.Record\n2.View");
    int mainop;
    scanf("%d",&mainop);
    if(mainop==1){
        menu();
    }
    else{
        view();
    }
    return 0;
}
