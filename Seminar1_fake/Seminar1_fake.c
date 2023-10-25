#include <stdio.h>
#include <stdlib.h>

// Structure to hold details about a process
typedef struct Process {
    int process_id;
    char name;
    int length;
} process;

process * newProcess(int id, char name, int length){
    process *pnew = NULL;
    pnew = (process*)malloc(sizeof(process));

    pnew->process_id = id;
    pnew->name = name;
    pnew->length = length;

    return pnew;
}
int main() {
    // Create an array to hold 10 processes
    process* processArray[10];

    // Create 10 new processes and save them in the array
    for (int i = 0; i < 10; i++) {
        // Call newProcess function to create a new process
        processArray[i] = newProcess(i + 1, 'a' + i, 50);
    }

    // Print the details of the created processes
    for (int i = 0; i < 10; i++) {
        // Access and print the details of each process
        printf("Process ID: %d, Name: %c, Length: %d\n",
               processArray[i]->process_id, processArray[i]->name, processArray[i]->length);

        // Free the allocated memory for each process to prevent memory leaks
        free(processArray[i]);     
    }

    return 0;
}

