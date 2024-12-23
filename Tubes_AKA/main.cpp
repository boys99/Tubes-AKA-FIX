#include <iostream>
#include "HEADER.h"
using namespace std;

int main() {
    TaskData_103052300096 taskList[10000];
    int numberOfTasks = 0;
    while (true) {
        cout << "\nSelamat Datang di Sistem Manajemen Tugas:\n";
        cout << "\nSilahkan Memilih Menu :\n";
        cout << "1. Tambah tugas\n";
        cout << "2. Generate tugas\n";
        cout << "3. Cari tugas untuk (Iteratif)\n";
        cout << "4. Cari tugas untuk (Rekursif)\n";
        cout << "5. Urutkan tugas (Iteratif)\n";
        cout << "6. Urutkan tugas (Rekursif)\n";
        cout << "7. Tampilkan semua tugas\n";
        cout << "8. Pengukuran Performansi\n";
        cout << "9. Keluar\n";
        cout << "Pilih opsi: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                addTask(taskList, numberOfTasks);
                break;
            case 2: {
                int taskCount;
                cout << "Masukkan jumlah tugas yang akan di-generate: ";
                cin >> taskCount;
                generateTasks(taskList, numberOfTasks, taskCount);
                break;
            }
            case 3: {
                string name;
                cout << "Masukkan nama tugas yang dicari: ";
                cin >> name;
                int index = searchTaskIterative(taskList, numberOfTasks, name);
                cout << "Operasi: " << operationCount << endl;
                if (index != -1) {
                    cout << "Tugas ditemukan di indeks " << index + 1 << ".\n";
                } else {
                    cout << "Tugas tidak ditemukan.\n";
                }
                break;
            }
            case 4: {
                string name;
                cout << "Masukkan nama tugas yang dicari: ";
                cin >> name;
                operationCount = 0;
                int index = searchTaskRecursive(taskList, numberOfTasks, name);
                cout << "Operasi: " << operationCount << endl;
                if (index != -1) {
                    cout << "Tugas ditemukan di indeks " << index + 1 << ".\n";
                } else {
                    cout << "Tugas tidak ditemukan.\n";
                }
                break;
            }
            case 5:
                bubbleSortIterative(taskList, numberOfTasks);
                cout << "Tugas berhasil diurutkan secara iteratif. Operasi: " << operationCount << endl;
                break;
            case 6:
                operationCount = 0;
                bubbleSortRecursive(taskList, numberOfTasks);
                cout << "Tugas berhasil diurutkan secara rekursif. Operasi: " << operationCount << endl;
                break;
            case 7:
                displayTaskList(taskList, numberOfTasks);
                break;
            case 8:
                measurePerformance(taskList, numberOfTasks);
                break;
            case 9:
                cout << "Keluar dari program.\n";
                return 0;
            default:
                cout << "Opsi tidak valid. Coba lagi.\n";
        }
    }
}
