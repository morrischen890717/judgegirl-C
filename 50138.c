#include <stdio.h>


typedef struct{
    int rawScore;
    double scaledScore;
}Score;

typedef struct{
    char id[10];
    Score score[18];
    double finalScore;
}Student;

typedef struct{
    int numStudent;
    Student student[1000];
}Classes;

void computeGrade(Classes classes[2]);
void computeGrade(Classes classes[2]){
    double average[2];
    double sum[2] = {};
    int lower_class;
    int higher_class;
    double ratio;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < classes[i].numStudent; j++){
            classes[i].student[j].finalScore = 0;
        }
    }
    for(int m = 0; m < 18; m++){
        sum[0] = sum[1] = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < classes[i].numStudent; j++){
                sum[i] += classes[i].student[j].score[m].rawScore;
            }
            average[i] = sum[i] / classes[i].numStudent;
        }
        if(average[0] < average[1]){
            ratio = average[1] / average[0];
            lower_class = 0;
            higher_class = 1;
        }
        else{
            ratio = average[0] / average[1];
            lower_class = 1;
            higher_class = 0;
        }
        for(int j = 0; j < classes[lower_class].numStudent; j++){
            classes[lower_class].student[j].score[m].scaledScore = ratio * classes[lower_class].student[j].score[m].rawScore;
            if(classes[lower_class].student[j].score[m].scaledScore > 100){
                classes[lower_class].student[j].score[m].scaledScore = 100;
            }
            classes[lower_class].student[j].score[m].scaledScore *= 0.06;
        }
        for(int j = 0; j < classes[higher_class].numStudent; j++){
            classes[higher_class].student[j].score[m].scaledScore = classes[higher_class].student[j].score[m].rawScore;
            classes[higher_class].student[j].score[m].scaledScore *= 0.06;
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < classes[i].numStudent; j++){
            for(int m = 0; m < 18; m++){
                classes[i].student[j].finalScore += classes[i].student[j].score[m].scaledScore;
            }
            if(classes[i].student[j].finalScore > 100){
                classes[i].student[j].finalScore = 100;
            }
            printf("%s %f\n", classes[i].student[j].id, classes[i].student[j].finalScore);
        }
    }
    return;
}




int main()
{
    Classes classes[2];
    scanf("%d", &classes[0].numStudent);
    for (int i = 0; i < classes[0].numStudent; i++) {
        scanf("%s", classes[0].student[i].id);
        for (int j = 0; j < 18; j++) {
            scanf("%d", &classes[0].student[i].score[j].rawScore);
        }
    }
    scanf("%d", &classes[1].numStudent);
    for (int i = 0; i < classes[1].numStudent; i++) {
        scanf("%s", classes[1].student[i].id);
        for (int j = 0; j < 18; j++) {
            scanf("%d", &classes[1].student[i].score[j].rawScore);
        }
    }
    computeGrade(classes);
    return 0;
}
