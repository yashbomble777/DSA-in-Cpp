
#include <iostream>
#include <string>
#include <limits>
using namespace std;

#define MAX 100

struct Employee {
    int id;
    string name;
    float salary;
};

struct SNode {
    Employee data;
    SNode* next;
};

struct DNode {
    Employee data;
    DNode* prev;
    DNode* next;
};

SNode* shead = NULL;
DNode* head = NULL;
DNode* tail = NULL;

Employee stack[MAX], queue[MAX];
int top = -1, front = 0, rear = -1, count = 0;

Employee readEmployee() {
    Employee e;

    cout << "Enter ID: ";
    cin >> e.id;

    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, e.name);

    cout << "Enter Salary: ";
    cin >> e.salary;

    return e;
}

void displayEmployee(Employee e) {
    cout << e.id << "\t"
         << e.name << "\t"
         << e.salary << endl;
}

void insertDoubly(Employee e) {
    DNode* n = new DNode;

    n->data = e;
    n->prev = tail;
    n->next = NULL;

    if (head == NULL)
        head = n;
    else
        tail->next = n;

    tail = n;
    cout << "Inserted in doubly linked list.\n";
}

void insertSingly(Employee e) {
    SNode* n = new SNode;
    n->data = e;
    n->next = NULL;

    if (shead == NULL) {
        shead = n;
    } else {
        SNode* p = shead;
        while (p->next != NULL)
            p = p->next;

        p->next = n;
    }

    cout << "Inserted in singly linked list.\n";
}

void displayForward() {
    DNode* p = head;

    if (p == NULL) {
        cout << "List is empty.\n";
        return;
    }

    cout << "ID\tName\tSalary\n";
    while (p != NULL) {
        displayEmployee(p->data);
        p = p->next;
    }
}

void displayBackward() {
    DNode* p = tail;

    if (p == NULL) {
        cout << "List is empty.\n";
        return;
    }

    cout << "ID\tName\tSalary\n";
    while (p != NULL) {
        displayEmployee(p->data);
        p = p->prev;
    }
}

void displaySingly() {
    SNode* p = shead;

    if (p == NULL) {
        cout << "List is empty.\n";
        return;
    }

    cout << "ID\tName\tSalary\n";
    while (p != NULL) {
        displayEmployee(p->data);
        p = p->next;
    }
}

void push(Employee e) {
    if (top == MAX - 1) {
        cout << "Stack overflow!\n";
        return;
    }

    stack[++top] = e;
    cout << "Employee pushed onto stack.\n";
}

void pop() {
    if (top == -1) {
        cout << "Stack underflow!\n";
        return;
    }

    cout << "Popped employee:\n";
    displayEmployee(stack[top--]);
}

void displayStack() {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack (top to bottom):\n";
    cout << "ID\tName\tSalary\n";

    for (int i = top; i >= 0; i--)
        displayEmployee(stack[i]);
}

void enqueue(Employee e) {
    if (count == MAX) {
        cout << "Queue is full!\n";
        return;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = e;
    count++;

    cout << "Employee enqueued successfully.\n";
}

void dequeue() {
    if (count == 0) {
        cout << "Queue is empty!\n";
        return;
    }

    cout << "Dequeued employee:\n";
    displayEmployee(queue[front]);

    front = (front + 1) % MAX;
    count--;

    if (count == 0) {
        rear = -1;
        front = 0;
    }
}

void displayQueue() {
    if (count == 0) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Queue (front to rear):\n";
    cout << "ID\tName\tSalary\n";

    for (int i = 0; i < count; i++) {
        int index = (front + i) % MAX;
        displayEmployee(queue[index]);
    }
}

void freeMemory() {
    while (shead != NULL) {
        SNode* temp = shead;
        shead = shead->next;
        delete temp;
    }

    while (head != NULL) {
        DNode* temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
}

int main() {
    int choice;
    Employee e;

    do {
        cout << "\n--- EMPLOYEE DIRECTORY ---\n";
        cout << "1. Insert Employee in Linked Lists\n";
        cout << "2. Display Forward\n";
        cout << "3. Display Backward\n";
        cout << "4. Display Singly Linked List\n";
        cout << "5. Push onto Stack\n";
        cout << "6. Pop from Stack\n";
        cout << "7. Display Stack\n";
        cout << "8. Enqueue\n";
        cout << "9. Dequeue\n";
        cout << "10. Display Queue\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            break;
        }

        switch (choice) {
            case 1:
                e = readEmployee();
                insertDoubly(e);
                insertSingly(e);
                break;

            case 2:
                displayForward();
                break;

            case 3:
                displayBackward();
                break;

            case 4:
                displaySingly();
                break;

            case 5:
                e = readEmployee();
                push(e);
                break;

            case 6:
                pop();
                break;

            case 7:
                displayStack();
                break;

            case 8:
                e = readEmployee();
                enqueue(e);
                break;

            case 9:
                dequeue();
                break;

            case 10:
                displayQueue();
                break;

            case 0:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    freeMemory();
    return 0;
}
