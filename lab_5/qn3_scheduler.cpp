//Round-robin scheduling algorithm implementation
#include "qn3_scheduler_header.h"

int main() {
    int time_quantum;
    cout << "Enter time quantum: ";
    cin >> time_quantum;

    RoundRobinScheduler scheduler(time_quantum);
    int choice, exec_time;

    do {
        //menu of the program
        cout << "\n1. Insert Process\n2. Execute\n3. Display Queue\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter execution time: ";
                cin >> exec_time;
                scheduler.insertProcess(exec_time);
                break;
            case 2:
                scheduler.execute();
                break;
            case 3:
                scheduler.displayQueue();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
