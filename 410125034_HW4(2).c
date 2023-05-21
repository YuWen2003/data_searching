#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

/* 定義學生資料結構 */
struct Student {
    char name[20];
    int id;
    int math;
    int english;
};

/* 讀取檔案中的學生資料 */
int readStudents(struct Student students[], char *filename) {
    FILE *f1;
    int i = 0;

    /* 開啟檔案 */
    f1 = fopen("C:\\111-2\\Input.txt", "r");
    if (f1 == NULL) {
        printf("error\n");
        return 0;
    }

    while (!feof(f1) && i < MAX_SIZE) { /* 未達到檔案結尾且學生數量未超過最大值 */
        fscanf(f1, "%s %d %d %d", students[i].name, &students[i].id, &students[i].math, &students[i].english);
        i++;
    }

    /* 關閉檔案 */
    fclose(f1);
    /* 返回實際讀取到的學生數量 */
    return i;
}

/* 根據ID搜尋學生資料 */
int searchStudent(struct Student students[], int n, int id, struct Student *result) {
    int i;

    for (i = 0; i < n; i++) {
        if (students[i].id == id) { /* 如果找到 */
            *result = students[i]; /* 將學生資料結構複製到儲存搜尋結果的變數中 */
            return 1; /* 返回1，表示有找到指定ID的學生 */
        }
    }

    return 0; /* 返回0，表示沒有找到指定ID的學生 */
}

/* 計算平均 */
float calcAverage(struct Student student) {
    return (student.math + student.english) / 2.0;
}

int main() {
    char filename[] = "Input.txt";
    struct Student students[MAX_SIZE];
    struct Student result;
    int n, id, i;
    float average;

    n = readStudents(students, filename); /* 讀取檔案中的學生資料 */

    while (1) {
        printf("Please enter student ID (0 to exit): ");
        scanf("%d", &id); /* 讀取要搜尋的學生ID */

        if (id == 0) {
              printf("Thanks for use!!!\n" );
            break;
        } /* 輸入0，則結束程式 */

        if (searchStudent(students, n, id, &result)) { /* 根據ID搜尋學生資料 */
            average = calcAverage(result); /* 計算平均 */
            printf("Name: %s\nID: %d\nMath point: %d\nEnglish point: %d\nAverage point: %.2f\n", result.name, result.id, result.math, result.english, average); /* 輸出學生資料和平均 */
        } else {
            printf("error\n" );
        }
    }

    return 0;
}

/*THIS CODE IS MY OWN WORK. IT WAS WRITTEN WITHOUT CONSULTING CODE WRITTEN BY OTHER STUDENTS OR ANY ONE WHO IS NOT AWARE OF MY REFERENCE. 410125034 陳俞妏*/
