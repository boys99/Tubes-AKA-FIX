#include "HEADER.h"
#include <iostream>
using namespace std;

void displayTaskList(TaskData_103052300096 tasks[], int size) {
    if (size == 0) {
        cout << "Daftar tugas kosong.\n";
        return;
    }
    cout << "-----------------------------------------------\n";
    cout << "No | Nama Tugas   | Prioritas | Tenggat Waktu\n";
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << "  | " << tasks[i].taskName << "\t  | "
             << tasks[i].taskPriority << "\t      | " << tasks[i].dueDate << "\n";
    }
    cout << "-----------------------------------------------\n";
}

void addTask(TaskData_103052300096 tasks[], int &size) {
    cin.ignore();
    cout << "Tugas baru:\n";
    cout << "Nama tugas: ";
    getline(cin, tasks[size].taskName);
    cout << "Prioritas tugas (1: Tinggi, 2: Sedang, 3: Rendah): ";
    cin >> tasks[size].taskPriority;
    cin.ignore();
    cout << "Tenggat waktu (YYYY-MM-DD): ";
    getline(cin, tasks[size].dueDate);
    ++size;
    cout << "Tugas berhasil ditambahkan.\n";
}

void generateTasks(TaskData_103052300096 tasks[], int &size, int numberOfTasks) {
    for (int i = 0; i < numberOfTasks; ++i) {
        tasks[size].taskName = "Tugas" + to_string(size + 1);
        tasks[size].taskPriority = ((size + 1) % 3) + 1;
        tasks[size].dueDate = "2024-06-" + to_string((size % 30) + 1);
        ++size;
    }
    cout << numberOfTasks << " tugas berhasil di-generate.\n";
}

int searchTaskIterative(TaskData_103052300096 tasks[], int size, string name) {
    operationCount = 0;
    for (int i = 0; i < size; ++i) {
        operationCount++;
        if (tasks[i].taskName == name) {
            return i;
        }
    }
    return -1;
}

int searchTaskRecursive(TaskData_103052300096 tasks[], int size, string name, int index) {
    operationCount++;
    if (index >= size) return -1;
    if (tasks[index].taskName == name) return index;
    return searchTaskRecursive(tasks, size, name, index + 1);
}

void bubbleSortIterative(TaskData_103052300096 tasks[], int size) {
    operationCount = 0;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            operationCount++;
            if (tasks[j].taskPriority > tasks[j + 1].taskPriority) {
                swap(tasks[j], tasks[j + 1]);
            }
        }
    }
}

void bubbleSortRecursive(TaskData_103052300096 tasks[], int size) {
    operationCount++;
    if (size == 1) return;
    for (int i = 0; i < size - 1; ++i) {
        operationCount++;
        if (tasks[i].taskPriority > tasks[i + 1].taskPriority) {
            swap(tasks[i], tasks[i + 1]);
        }
    }
    bubbleSortRecursive(tasks, size - 1);
}

void measurePerformance(TaskData_103052300096 tasks[], int size) {
    if (size == 0) {
        cout << "Tidak ada data tugas yang di-generate.";
        return;
    }
    cout << "\nPerformance Measurement:\n";
    cout << "Size\tIterative Ops\tRecursive Ops\n";
    operationCount = 0;
    bubbleSortIterative(tasks, size);
    int iterativeOps = operationCount;
    operationCount = 0;
    bubbleSortRecursive(tasks, size);
    int recursiveOps = operationCount;
    cout << size << "\t" << iterativeOps << "\t\t" << recursiveOps << "\n";
}
