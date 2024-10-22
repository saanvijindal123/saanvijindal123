#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int attendance; // 1 for present, 0 for absent
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }
    
    printf("Enter student name: ");
    scanf(" %[^\n]", students[studentCount].name);
    students[studentCount].attendance = 0; // Default to absent
    studentCount++;
}

void markAttendance() {
    char name[NAME_LENGTH];
    printf("Enter student name to mark attendance: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, name) == 0) {
            students[i].attendance = 1; // Mark as present
            printf("%s marked as present.\n", students[i].name);
            return;
        }
    }
    printf("Student not found.\n");
}

void displayAttendance() {
    printf("\nAttendance Record:\n");
    printf("Name\t\tAttendance\n");
    printf("-----------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t\t%s\n", students[i].name, students[i].attendance ? "Present" : "Absent");
    }
}

int main() {
    int choice;
    
    do {
        printf("\nAttendance Management System\n");
        printf("1. Add Student\n");
        printf("2. Mark Attendance\n");
        printf("3. Display Attendance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                markAttendance();
                break;
            case 3:
                displayAttendance();
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}



