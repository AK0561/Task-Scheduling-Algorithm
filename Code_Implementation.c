#include <stdio.h>
#include <stdlib.h>
// Define a task struct to store task information
typedef struct {
int id;
int processing_time;
} task;
// Define a resource struct to store resource information
typedef struct {
int id;
int finish_time;
} resource;
// Define a function to compare two tasks based on processing time (for
sorting)
int compare_tasks(const void* a, const void* b) {
task* task_a = (task*)a;
task* task_b = (task*)b;
return task_b->processing_time - task_a->processing_time;
}
// Define the main function for task scheduling
int main() {
int n = 5; // number of tasks
int m = 2; // number of resources
// Initialize tasks and resources
task tasks[] = { {1, 5}, {2, 3}, {3, 7}, {4, 2}, {5, 4} };
resource resources[] = { {1, 0}, {2, 0} };
// Sort tasks in decreasing order of processing time
qsort(tasks, n, sizeof(task), compare_tasks);
// Assign tasks to resources in greedy manner
for (int i = 0; i < n; i++) {
// Find the resource with earliest finish time
int r = 0;
for (int j = 1; j < m; j++) {
if (resources[j].finish_time < resources[r].finish_time) {
r = j;
}
}
// Assign task i to resource r
printf("Task %d assigned to resource %d\n", tasks[i].id,
resources[r].id);
// Update finish time of resource r
resources[r].finish_time += tasks[i].processing_time;
}
return 0;
}