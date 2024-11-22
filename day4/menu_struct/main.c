#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define MAX_EMPLOYEES 5
#define MAX_NAME 50

// Structure for employee data
struct Employee {
    int code;
    char name[MAX_NAME];
    float netSalary;
};

// Function prototypes
void displayMenu(int selectedOption);
void clearScreen();
char getChar();
void clearInputBuffer();
void handleSingleEmployee();
void handleMultipleEmployees();

// Platform-independent keyboard input function
char getChar() {
    char buf = 0;
    struct termios old = {0};
    struct termios new = {0};

    if (tcgetattr(0, &old) < 0)
        perror("tcgetattr()");

    new = old;
    new.c_lflag &= ~ICANON; // Disable buffered I/O
    new.c_lflag &= ~ECHO;   // Disable echo
    new.c_cc[VMIN] = 1;
    new.c_cc[VTIME] = 0;

    if (tcsetattr(0, TCSANOW, &new) < 0)
        perror("tcsetattr ICANON");

    if (read(0, &buf, 1) < 0)
        perror("read()");

    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");

    return buf;
}

// Platform-independent screen clearing
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int selectedOption = 1;
    char key;

    while(1) {
        clearScreen();
        printf("\033[?25l"); // Hide cursor

        // Display menu
        printf("\n\n");
        printf("     %s New\n", selectedOption == 1 ? ">" : " ");
        printf("     %s Display\n", selectedOption == 2 ? ">" : " ");
        printf("     %s Exit\n", selectedOption == 3 ? ">" : " ");
        printf("\nUse arrow keys (↑/↓) to navigate, Enter to select, ESC to exit\n");

        key = getChar();

        // Handle escape sequences
        if (key == 27) {
            key = getChar(); // Get [
            if (key == '[') {
                key = getChar(); // Get actual code
                switch(key) {
                    case 'A': // Up arrow
                        if (selectedOption > 1) selectedOption--;
                        break;
                    case 'B': // Down arrow
                        if (selectedOption < 3) selectedOption++;
                        break;
                }
            } else {
                // ESC was pressed
                printf("\033[?25h"); // Show cursor
                clearScreen();
                printf("Exiting program...\n");
                return 0;
            }
        }
        // Handle Enter key
        else if (key == '\n' || key == '\r') {
            printf("\033[?25h"); // Show cursor
            switch(selectedOption) {
                case 1:
                    clearScreen();
                    printf("New Option Selected\n");
                    handleSingleEmployee();
                    printf("\nPress Enter to continue...");
                    clearInputBuffer();
                    getchar();
                    break;
                case 2:
                    clearScreen();
                    printf("Display Option Selected\n");
                    handleMultipleEmployees();
                    printf("\nPress Enter to continue...");
                    clearInputBuffer();
                    getchar();
                    break;
                case 3:
                    clearScreen();
                    printf("Exiting program...\n");
                    return 0;
            }
        }
    }
    return 0;
}

void handleSingleEmployee() {
    struct Employee emp;

    printf("\nEnter Employee Details:\n");
    printf("Code: ");
    scanf("%d", &emp.code);
    clearInputBuffer();

    printf("Name: ");
    fgets(emp.name, MAX_NAME, stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; // Remove trailing newline

    printf("Net Salary: ");
    scanf("%f", &emp.netSalary);
    clearInputBuffer();

    printf("\nEmployee Details:\n");
    printf("Code: %d\n", emp.code);
    printf("Name: %s\n", emp.name);
    printf("Net Salary: %.2f\n", emp.netSalary);
}

void handleMultipleEmployees() {
    struct Employee employees[MAX_EMPLOYEES];
    int i;

    printf("\nEnter Details for %d Employees:\n", MAX_EMPLOYEES);

    for(i = 0; i < MAX_EMPLOYEES; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Code: ");
        scanf("%d", &employees[i].code);
        clearInputBuffer();

        printf("Name: ");
        fgets(employees[i].name, MAX_NAME, stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = 0;

        printf("Net Salary: ");
        scanf("%f", &employees[i].netSalary);
        clearInputBuffer();
    }

    printf("\nEmployee Details:\n");
    printf("\nCode\tName\t\tNet Salary\n");
    printf("--------------------------------\n");

    for(i = 0; i < MAX_EMPLOYEES; i++) {
        printf("%d\t%-15s\t%.2f\n",
               employees[i].code,
               employees[i].name,
               employees[i].netSalary);
    }
}
