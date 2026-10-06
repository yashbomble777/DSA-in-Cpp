#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;

    struct Employee *prev;
    struct Employee *next;
};

// Create a new employee node
struct Employee* createEmployee(int id, char name[], float salary) {
    struct Employee *newNode =
        (struct Employee*)malloc(sizeof(struct Employee));

    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->salary = salary;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert employee at the end
void insertEmployee(struct Employee **head, int id, char name[], float salary) {
    struct Employee *newNode = createEmployee(id, name, salary);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Employee *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Display from beginning to end
void displayForward(struct Employee *head) {
    struct Employee *temp = head;

    printf("\nEmployees (Beginning to End):\n");

    while (temp != NULL) {
        printf("ID: %d | Name: %s | Salary: %.2f\n",
               temp->id, temp->name, temp->salary);
        temp = temp->next;
    }
}

// Display from end to beginning
void displayBackward(struct Employee *head) {
    if (head == NULL)
        return;

    struct Employee *temp = head;

    // Move to the last node
    while (temp->next != NULL)
        temp = temp->next;

    printf("\nEmployees (End to Beginning):\n");

    while (temp != NULL) {
        printf("ID: %d | Name: %s | Salary: %.2f\n",
               temp->id, temp->name, temp->salary);
        temp = temp->prev;
    }
}

int main() {
    struct Employee *head = NULL;
    int n, id;
    char name[50];
    float salary;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of employee %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &id);

        printf("Name: ");
        scanf("%s", name);

        printf("Salary: ");
        scanf("%f", &salary);

        insertEmployee(&head, id, name, salary);
    }

    displayForward(head);
    displayBackward(head);

    return 0;
}