#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void addTask(std::vector<Task>& taskList, const std::string& description) {
    taskList.push_back(Task(description));
    std::cout << "Task added: " << description << std::endl;
}

// Function to view tasks in the list
void viewTasks(const std::vector<Task>& taskList) {
    std::cout << "Task List:" << std::endl;
    for (size_t i = 0; i < taskList.size(); i++) {
        std::cout << (i + 1) << ". [" << (taskList[i].completed ? "X" : " ") << "] " << taskList[i].description << std::endl;
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(std::vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(taskList.size())) {
        taskList[taskIndex - 1].completed = true;
        std::cout << "Task marked as completed: " << taskList[taskIndex - 1].description << std::endl;
    } else {
        std::cout << "Invalid task index. No task marked as completed." << std::endl;
    }
}

// Function to remove a task from the list
void removeTask(std::vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(taskList.size())) {
        std::cout << "Task removed: " << taskList[taskIndex - 1].description << std::endl;
        taskList.erase(taskList.begin() + taskIndex - 1);
    } else {
        std::cout << "Invalid task index. No task removed." << std::endl;
    }
}

int main() {
    std::vector<Task> taskList;

    while (true) {
        std::cout << "To-Do List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Quit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cin.ignore(); // Clear newline from previous input
            std::string taskDescription;
            std::cout << "Enter the task description: ";
            std::getline(std::cin, taskDescription);
            addTask(taskList, taskDescription);
        } else if (choice == 2) {
            viewTasks(taskList);
        } else if (choice == 3) {
            int taskIndex;
            std::cout << "Enter the task index to mark as completed: ";
            std::cin >> taskIndex;
            markTaskAsCompleted(taskList, taskIndex);
        } else if (choice == 4) {
            int taskIndex;
            std::cout << "Enter the task index to remove: ";
            std::cin >> taskIndex;
            removeTask(taskList, taskIndex);
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    std::cout << "Goodbye! Thanks for using the To-Do List Manager." << std::endl;

    return 0;
}
