#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <string>
using namespace std;

struct TaskData_103052300096 {
    string taskName;
    int taskPriority;
    string dueDate;
};

int operationCount = 0;

void displayTaskList(TaskData_103052300096 tasks[], int size);
void addTask(TaskData_103052300096 tasks[], int &size);
void generateTasks(TaskData_103052300096 tasks[], int &size, int numberOfTasks);
int searchTaskIterative(TaskData_103052300096 tasks[], int size, string name);
int searchTaskRecursive(TaskData_103052300096 tasks[], int size, string name, int index = 0);
void bubbleSortIterative(TaskData_103052300096 tasks[], int size);
void bubbleSortRecursive(TaskData_103052300096 tasks[], int size);
void measurePerformance(TaskData_103052300096 tasks[], int size);

#endif // HEADER_H_INCLUDED
