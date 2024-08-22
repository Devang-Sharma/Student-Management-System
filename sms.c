#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h> 
#include<time.h>
#include<stdbool.h>

#define FILE_NAME0 "students.txt"
#define FILE_NAME1 "rollno.txt"
#define FILE_NAME2 "temp.txt"

typedef struct {
    int rollNumber;
    char firstName[10];    //first name
    char lastName[10];  //last name
    int age;
    int marks;
    int class;
    char section;
    char guardian[10];    //Guardian First Name
    int guardianNo;     //Guardian phone number
    char address[50];
} Student;

int adds(int count){
    FILE *file0 = fopen(FILE_NAME0, "a");
    if (!file0){
        printf("Unable to open file0.\n");
        return 0;
    }
    FILE *file1 = fopen(FILE_NAME1, "r");
    if (!file1){
        printf("Unable to open file1.\n");
    }
    // printf("Reading student count\n");
    fscanf(file1, "%d", &count);
    // printf("%d is the student count\n", count);
    fclose(file1);
    printf("file1 closed");
    FILE *file2 = fopen(FILE_NAME1, "w");
    // printf("file2 opened, write mode\n");
    if(!file2){
        printf("Unable to open file1.\n");
    }
    ++count;
    fprintf(file2, "%d", count);
    printf("Updated student count\n");
    Student student;
    student.rollNumber = count;
    printf("Enter First Name: ");
    scanf("%s", student.firstName);
    printf("Enter Last Name: ");
    scanf("%s", student.lastName);
    printf("Enter your Age: ");
    scanf("%d", &student.age);
    printf("Enter your Marks:\n");
    scanf("%d", &student.marks);
    student.class = student.age - 5;
    if(student.rollNumber > 10){
        student.section = 'B';
    }
    else{
        student.section = 'A';
    }
    printf("Enter your Guardian's Name:\n");
    scanf("%s", student.guardian);
    printf("Enter your Guardian's Phone Number:\n");
    scanf("%d", &student.guardianNo);
    printf("Enter your Address:\n");
    scanf("%s", &student.address);

    fprintf(file0, "%d %s %s %d %d %d %c %s %d %s\n", student.rollNumber, student.firstName, student.lastName, student.age, student.marks, student.class, student.section, student.guardian, student.guardianNo, student.address);
    fclose(file0);
    printf("Student added successfully.\n");
    printf("%d", count);
    return count;
}

bool finds(){
    bool found = false;
    char nf[10];
    char nl[10];
    int rollNo;
    FILE *file = fopen(FILE_NAME0, "r");
    if (!file) {
        printf("Unable to open file.\n");
        return false;
    }
    printf("Do you know the student's rollNo? Press 1 if yes and 0 if no\n");
    int chk;
    scanf("%d", &chk);
    if(chk == 0){
        printf("Enter the student's first name\n");
        scanf("%s", nf);  // use %9s to prevent buffer overflow
        printf("Enter the student's last name\n");
        scanf("%s", nl);  // use %9s to prevent buffer overflow
        printf("Finding %s %s", nf, nl);
        Student student;
        while (fscanf(file, "%d %s %s %d %d %d %c %s %d %s", &student.rollNumber, student.firstName, student.lastName, &student.age, &student.marks, &student.class, &student.section, student.guardian, &student.guardianNo, student.address) != EOF){
            // printf("%d %s %s %d %0.1f %d %s %s %d %s\n", &student.rollNumber, student.firstName, student.lastName, student.age, student.marks, student.class, student.section, student.guardian, student.guardianNo, student.address);
            if (strcmp(student.firstName, nf) == 0 && strcmp(student.lastName, nl) == 0){
                printf("Student found:\n");
                printf("Roll Number: %d\n", student.rollNumber);  
                printf("First Name: %s\n", student.firstName);
                printf("Last Name: %s\n", student.lastName);
                printf("Age: %d\n", student.age);
                printf("Marks: %d\n", student.marks);
                printf("Class: %d\n", student.class);
                printf("Section: %c\n", student.section);
                printf("Guardian Name: %s\n", student.guardian);
                printf("Guardian's Phone No: %d\n", student.guardianNo);
                printf("Address: %s\n", student.address);
                found = true;
                break;
            }
            else{
                printf(".");
                // printf("Roll Number: %d\n", student.rollNumber);
                // printf("First Name: %s\n", student.firstName);
                // printf("Last Name: %s\n", student.lastName);
            }
        }
        fclose(file);
    }
    else{
        printf("Enter the student's roll number:\n");
        scanf("%d", &rollNo);
        FILE *file = fopen(FILE_NAME0, "r");
        if (!file) {
            printf("Unable to open file.\n");
            return false;
        }
        Student student;
        printf("Finding Student");
        while (fscanf(file, "%d %s %s %d %d %d %c %s %d %s", &student.rollNumber, student.firstName, student.lastName, &student.age, &student.marks, &student.class, &student.section, student.guardian, &student.guardianNo, student.address) != EOF) {
            // printf("Inside While");
            // printf("Current Student Details: %d %s %s %d %0.1f %d %s %s %d %s\n", student.rollNumber, student.firstName, student.lastName, student.age, student.marks, student.class, student.section, student.guardian, student.guardianNo, student.address);
            if (student.rollNumber == rollNo){
                printf("\nStudent found:\n");
                printf("Roll Number: %d\n", student.rollNumber);
                printf("First Name: %s\n", student.firstName);
                printf("Last Name: %s\n", student.lastName);
                printf("Age: %d\n", student.age);
                printf("Marks: %d\n", student.marks);
                printf("Class: %d\n", student.class);
                printf("Section: %c\n", student.section);
                printf("Guardian Name: %s\n", student.guardian);
                printf("Guardian's Phone No: %d\n", student.guardianNo);
                printf("Address: %s\n", student.address);
                found = true;
                break;
            }
            else{
                printf(".");
                // printf("Roll Number: %d\n", student.rollNumber);
                // printf("First Name: %s\n", student.firstName);
                // printf("Last Name: %s\n", student.lastName);
            }
        }
    }
    fclose(file);
    return found;
}

// bool finds(){
//     bool chk;
//     bool found=0;
//     char nf[10];
//     char nl[10];
//     char l[20];
//     FILE *file = fopen(FILE_NAME0, "r");
//     if (!file) {
//         printf("Unable to open file.\n");
//         return 0;
//     }
//     printf("Do you know the student's rollNo? Press 1 if yes and 0 if no\n");
//     scanf("%d", &chk);
//     printf("Outside if\n");
//     if(chk == 0){
//         printf("Inside if\n");
//         printf("Enter the student's first name\n");
//         scanf("%s", nf);
//         printf("Enter the student's last name\n");
//         scanf("%s", nl);
//         printf("Outside if\n");
//         Student student;
//         while (fscanf(file, "%d %s %s %d", &student.rollNumber, student.firstName, student.lastName, &student.age) != EOF){
//             printf("Inside while\n");
//             if (strcmp(student.firstName, nf) == 0){
//                 printf("Inside if\n");
//                 printf("Student found:\n");
//                 printf("Roll Number: %d\n", student.rollNumber);
//                 printf("First Name: %s\n", student.firstName);
//                 printf("Last Name: %s\n", student.lastName);
//                 printf("Age: %d\n", student.age);
//                 found = 1; 
//             }
//             fclose(file);
//         }
//         printf("Outside loop\n");
//     }

//     else{
//         int rollNo;
//         printf("Enter the student's roll number:\n");
//         scanf("%d", &rollNo);
//         Student student;
//         student.rollNumber = rollNo;
//         while (fscanf(file, "%d %s %s %d", &student.rollNumber, student.firstName, student.lastName, &student.age) != EOF) {
//             printf("Inside while\n");
//             if (student.rollNumber == rollNo){
//                 printf("Inside if\n");
//                 printf("Student found:\n");
//                 // displayStudent(&student);
//                 printf("Roll Number: %d\n", student.rollNumber);
//                 printf("First Name: %s\n", student.firstName);
//                 printf("Last Name: %s\n", student.lastName);
//                 printf("Age: %d\n", student.age);
//                 printf("Roll Number: %d\n", student.rollNumber);
//                 printf("Address: %s\n", student.address);
//                 printf("Guardian Name: %s\n", student.guardian);
//                 printf("Guardian's Phone No: %d\n", student.guardianNo);
//                 printf("Marks: %d\n", student.marks);
//                 printf("Roll Number: %d", student.rollNumber);
//                 printf("Class: %d\n", student.class);
//                 printf("Section: %c\n", student.section);                
//                 found = 1;
//                 break;
//             }
//         }
//     }
//     printf("Outside if\n");
//     fclose(file);
//     return found;
// }

void deletes() {
    int rollNumber;
    int found = 0;
    printf("Enter Roll Number of Student: ");
    scanf("%d", &rollNumber);
    printf("\nOkay");

    FILE *file0 = fopen(FILE_NAME0, "r");
    FILE *file1 = fopen("temp.txt", "w");
    if (!file0 || !file1) {
        printf("Unable to open file.\n");
        return;
    }
    printf("Opened files\n");
    int i = 0;
    Student student;
    while (fscanf(file0, "%d %s %s %d %d %d %c %s %d %s", &student.rollNumber, student.firstName, student.lastName, &student.age, &student.marks, &student.class, &student.section, student.guardian, &student.guardianNo, student.address) != EOF) {
        if (student.rollNumber == rollNumber){
            printf("Inside if\n");
            found = 1;
            continue;
        } else {
            printf("Inside else");
            printf("RollNo:%d", student.rollNumber);
            fprintf(file1, "%d %s %s %d %d %d %c %s %d %s\n", student.rollNumber, student.firstName, student.lastName, student.age, student.marks, student.class, student.section, student.guardian, student.guardianNo, student.address);
        }
        printf("%d", i++);
    }
    fclose(file0);
    fclose(file1);

    if (found) {
        remove(FILE_NAME0);
        rename("temp.txt", FILE_NAME0);
        printf("Student with Roll Number %d deleted successfully.\n", rollNumber);
    } else {
        remove("temp.txt");
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}


// void deletes(){
//     int rollNumber;
//     int found = 0;
//     printf("Enter Roll Number of Student: ");
//     scanf("%d", &rollNumber);
//     printf("\nOkay");

//     FILE *file0 = fopen(FILE_NAME0, "r");
//     FILE *file1 = fopen(FILE_NAME2, "w");
//     if (!file0 || !file1) {
//         printf("Unable to open file.\n");
//         return;
//     }
//     printf("Opened files\n");
//     Student student;
//     while(fscanf(file0, "%d %s %s %d %d %d %c %s %d %s", &student.rollNumber, student.firstName, student.lastName, &student.age, &student.marks, &student.class, &student.section, student.guardian, &student.guardianNo, student.address) != EOF) {
//         printf("Inside loop\n");
//         printf("PRINTING:%d %s %s %d %d %d %s %s %d %s\n", student.rollNumber, student.firstName, student.lastName, student.age, student.marks, student.class, student.section, student.guardian, student.guardianNo, student.address);
//         printf("Can't Print");
//         if (student.rollNumber == rollNumber){
//             printf("Inside if\n");
//             found = 1;
//         } 
        
//         else {
//             // fprintf(tempFile, "%d %s %s %d\n", student.rollNumber, student.firstName, student.lastName, student.age);
//             fprintf(file1, "%d %s %s %d %d %d %s %s %d %s", &student.rollNumber, student.firstName, student.lastName, student.age, student.marks, student.class, student.section, student.guardian, student.guardianNo, student.address);
//             // printf("%d %s %s %d %0.1f %d %s %s %d %s\n", &student.rollNumber, student.firstName, student.lastName, student.age, student.marks, student.class, student.section, student.guardian, student.guardianNo, student.address);
//             // printf("Req. rollNo: %d\n", rollNumber);
//             // printf("RollNo: %d\n", student.rollNumber);
//         }
//         printf("Outside if\n");
//     }
//     printf("Outside loop");

//     fclose(file0);
//     fclose(file1);

//     if (found) {
//         printf("Inside if");
//         remove(FILE_NAME0);
//         rename("temp.txt", FILE_NAME0);
//         printf("Student with Roll Number %d deleted successfully.\n", rollNumber);
//     } else {
//         remove("temp.txt");
//         printf("Student with Roll Number %d not found.\n", rollNumber);
//     }
// }

void updates(){
    int rollNumber;
    int found = 0;
    printf("Enter Roll Number of Student to Update: ");
    scanf("%d", &rollNumber);

    FILE *file0 = fopen(FILE_NAME0, "r");
    FILE *file1 = fopen(FILE_NAME2, "w");
    if (!file0 || !file1){
        printf("Unable to open file.\n");
        return;
    }

    Student student;
    while (fscanf(file0, "%d %s %s %d %d %d %c %s %d %s", &student.rollNumber, student.firstName, student.lastName, &student.age, &student.marks, &student.class, &student.section, student.guardian, &student.guardianNo, student.address) != EOF) {
        if (student.rollNumber == rollNumber) {
            found = 1;
            printf("Enter new First Name: ");
            scanf("%s", student.firstName);
            printf("Enter new Last Name: ");
            scanf("%s", student.lastName);
            printf("Enter new Age: ");
            scanf("%d", &student.age);
            printf("Enter new Marks: ");
            scanf("%d", &student.marks);
            printf("Enter new Class: ");
            scanf("%d", &student.class);
            printf("Enter new Section: ");
            scanf("%c", &student.section);
            printf("Enter new Guardian: ");
            scanf("%s", student.guardian);
            printf("Enter new Guardian No: ");
            scanf("%d", &student.guardianNo);
            printf("Enter new Address: ");
            scanf("%s", student.address);
        }
        fprintf(file1, "%d %s %s %d %d %d %c %s %d %s\n", student.rollNumber, student.firstName, student.lastName, student.age, student.marks, student.class, student.section, student.guardian, student.guardianNo, student.address);
    }

    fclose(file0);
    fclose(file1);

    if (found) {
        remove(FILE_NAME0);
        rename(FILE_NAME2, FILE_NAME0);
        printf("Student with Roll Number %d updated successfully.\n", rollNumber);
    } else {
        remove("temp.txt");
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

int main(){

    // FILE* fptr;
    // fptr = fopen("studentsList.txt", "w");
    int command;
    int count = 0;
    int strength;
    bool status2 = false;

    FILE *file = fopen(FILE_NAME1, "r");
    if (!file){
        printf("Unable to open file1.\n");
    }
    // printf("Reading student count\n");
    fscanf(file, "%d", &strength);
    // printf("%d is the student count\n", count);
    fclose(file);
    // printf("file1 closed");

    printf("Welcome to xyz Public School!\n");
    printf("How can we help you?\n");
    printf("Press 1 for New Admissionn\n");
    printf("Press 2 to Find student details\n");
    printf("Press 3 for an inquiry about the school's strength\n");
    printf("Press 4 to leave the school permanently\n");
    printf("Press 5 to update student details\n");
    scanf("%d", &command);
    switch(command){
        case 1:
            // bool status1;
            count = adds(count);
            // count = strength;
            // if(status1 == 1){
            //     printf("Student added successfully!");
            // }
            // else{
            //     printf("Student not added!");
            // }
            break;
        case 2:
            status2 = finds();  
            // printf("Inside int main\n");
            if(status2 != 1){
                printf("Student not found");
            }
            break;
        case 3: 
            printf("There are a total of %d students studying in xyz Public School", strength);
            break;
        case 4:
            deletes();
            break;
        case 5:
            updates();
            break;
        default:
        printf("Invalid choice!");

    }

    return 0;

}