#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

/* �w�q�ǥ͸�Ƶ��c */
struct Student {
    char name[20];
    int id;
    int math;
    int english;
};

/* Ū���ɮפ����ǥ͸�� */
int readStudents(struct Student students[], char *filename) {
    FILE *f1;
    int i = 0;

    /* �}���ɮ� */
    f1 = fopen("C:\\111-2\\Input.txt", "r");
    if (f1 == NULL) {
        printf("error\n");
        return 0;
    }

    while (!feof(f1) && i < MAX_SIZE) { /* ���F���ɮ׵����B�ǥͼƶq���W�L�̤j�� */
        fscanf(f1, "%s %d %d %d", students[i].name, &students[i].id, &students[i].math, &students[i].english);
        i++;
    }

    /* �����ɮ� */
    fclose(f1);
    /* ��^���Ū���쪺�ǥͼƶq */
    return i;
}

/* �ھ�ID�j�M�ǥ͸�� */
int searchStudent(struct Student students[], int n, int id, struct Student *result) {
    int i;

    for (i = 0; i < n; i++) {
        if (students[i].id == id) { /* �p�G��� */
            *result = students[i]; /* �N�ǥ͸�Ƶ��c�ƻs���x�s�j�M���G���ܼƤ� */
            return 1; /* ��^1�A��ܦ������wID���ǥ� */
        }
    }

    return 0; /* ��^0�A��ܨS�������wID���ǥ� */
}

/* �p�⥭�� */
float calcAverage(struct Student student) {
    return (student.math + student.english) / 2.0;
}

int main() {
    char filename[] = "Input.txt";
    struct Student students[MAX_SIZE];
    struct Student result;
    int n, id, i;
    float average;

    n = readStudents(students, filename); /* Ū���ɮפ����ǥ͸�� */

    while (1) {
        printf("Please enter student ID (0 to exit): ");
        scanf("%d", &id); /* Ū���n�j�M���ǥ�ID */

        if (id == 0) {
              printf("Thanks for use!!!\n" );
            break;
        } /* ��J0�A�h�����{�� */

        if (searchStudent(students, n, id, &result)) { /* �ھ�ID�j�M�ǥ͸�� */
            average = calcAverage(result); /* �p�⥭�� */
            printf("Name: %s\nID: %d\nMath point: %d\nEnglish point: %d\nAverage point: %.2f\n", result.name, result.id, result.math, result.english, average); /* ��X�ǥ͸�ƩM���� */
        } else {
            printf("error\n" );
        }
    }

    return 0;
}

/*THIS CODE IS MY OWN WORK. IT WAS WRITTEN WITHOUT CONSULTING CODE WRITTEN BY OTHER STUDENTS OR ANY ONE WHO IS NOT AWARE OF MY REFERENCE. 410125034 ���\ʹ*/
