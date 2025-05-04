//Header file
#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H
#include <iostream>
using namespace std;

struct Process {
    int execution_time;
    Process* next;
};

class RoundRobinScheduler {
private:
    Process* tail;
    int time_quantum;

public:
    // Constructor
    RoundRobinScheduler(int tq) {
        tail = nullptr;
        time_quantum = tq;
    }

    // Insert process into circular queue
    void insertProcess(int exec_time) {
        Process* newProcess = new Process();
        newProcess->execution_time = exec_time;

        if (tail == nullptr) {
            newProcess->next = newProcess;
            tail = newProcess;
        } else {
            newProcess->next = tail->next;
            tail->next = newProcess;
            tail = newProcess;
        }

        cout << "Process with execution time " << exec_time << " added.\n";
    }

    // Execute process
    void execute() {
        if (tail == nullptr) {
            cout << "No processes in the queue.\n";
            return;
        }

        Process* current = tail->next;  // First process
        cout << "Executing process with time " << current->execution_time << endl;

        // Subtract time quantum
        current->execution_time -= time_quantum;

        if (current->execution_time <= 0) {
            cout << "Process completed.\n";
            if (current == tail) {
                delete current;
                tail = nullptr;
            } else {
                tail->next = current->next;
                delete current;
            }
        } else {
            cout << "Remaining time: " << current->execution_time << endl;
            tail = current;  // Move tail forward
        }
    }

    // Display the process queue
    void displayQueue() {
        if (tail == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        Process* temp = tail->next;
        cout << "Process Queue: ";
        do {
            cout << temp->execution_time << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }

    // Destructor to free memory
    ~RoundRobinScheduler() {
        while (tail != nullptr) {
            execute();
        }
    }
};

#endif
