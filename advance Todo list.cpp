#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include<ctime>
#include<iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Task {
    string title;
    string description;
    string targetTime;
    bool completed;
    string priority;
    Task* next;

    Task(const string& t, const string& desc, const string& time, const string& prio, bool comp = false)
        : title(t), description(desc), targetTime(time), completed(comp), priority(prio), next(nullptr) {}
};

class ToDoList {
private:
    Task* head;

public:
    ToDoList() : head(nullptr) {}

    ~ToDoList() {
        clearTasks();
    }

    void addTask(const string& title, const string& description, const string& targetTime, const string& priority) {
        Task* newTask = new Task(title, description, targetTime, priority);
        if (head == nullptr) {
            head = newTask;
        } else {
            Task* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newTask;
        }
        cout << "Task added: " << title << endl;
    }

    void deleteTask(int index) {
        if (index < 0) {
            cout << "Invalid task index." << endl;
            return;
        }

        Task* temp = head;
        Task* prev = nullptr;

        for (int i = 0; i < index && temp != nullptr; ++i) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid task index." << endl;
            return;
        }

        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        cout << "Task deleted: " << temp->title << endl;
        delete temp;
    }

    void viewTasks() const {
        if (head == nullptr) {
            cout << "No tasks to display." << endl;
            return;
        }

        Task* temp = head;
        int index = 1;

        while (temp != nullptr) {
            cout << index << ". " << temp->title
                << " [" << (temp->completed ? "Completed" : "Not Completed") << "]" << endl;
            cout << "   Description: " << temp->description << endl;
            cout << "   Target Time: " << temp->targetTime << endl;
            cout << "   Priority: " << temp->priority << endl;
            cout << "   Overdue: " << (isOverdue(temp->targetTime) ? "Yes" : "No") << endl;
            temp = temp->next;
            ++index;
        }
    }

    void markCompleted(const vector<int>& indices) {
        for (int index : indices) {
            Task* temp = head;

            for (int i = 0; i < index && temp != nullptr; ++i) {
                temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "Invalid task index: " << index + 1 << endl;
                continue;
            }

            temp->completed = true;
            cout << "Task marked as completed: " << temp->title << endl;
        }

        if (allTasksCompleted()) {
            cout << "Congratulations! All tasks are completed!" << endl;
        }
    }

    bool allTasksCompleted() const {
        Task* temp = head;

        while (temp != nullptr) {
            if (!temp->completed) {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }

    void editTask(int index, const string& newTitle, const string& newDescription, const string& newTargetTime, const string& newPriority) {
        Task* temp = head;

        for (int i = 0; i < index && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid task index." << endl;
            return;
        }

        temp->title = newTitle;
        temp->description = newDescription;
        temp->targetTime = newTargetTime;
        temp->priority = newPriority;
        cout << "Task edited: " << temp->title << endl;
    }

    void searchTask(const string& title) const {
        Task* temp = head;
        int index = 1;
        bool found = false;

        while (temp != nullptr) {
            if (temp->title == title) {
                cout << index << ". " << temp->title
                    << " [" << (temp->completed ? "Completed" : "Not Completed") << "]" << endl;
                cout << "   Description: " << temp->description << endl;
                cout << "   Target Time: " << temp->targetTime << endl;
                cout << "   Priority: " << temp->priority << endl;
                found = true;
            }
            temp = temp->next;
            ++index;
        }

        if (!found) {
            cout << "Task not found: " << title << endl;
        }
    }

    bool isOverdue(const string& targetTime) const {
  
    time_t now = time(0);
    tm target = {};

    istringstream ss(targetTime);
    ss >> get_time(&target, "%Y-%m-%d %H:%M");

    if (ss.fail()) {
        cerr << "Failed to parse date/time: " << targetTime << endl;
        return false;
    }

    time_t targetTimeT = mktime(&target);

    return difftime(now, targetTimeT) > 0;
}


    void saveToFile(const string& filename) const {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error: Unable to open file: " << filename << endl;
            return;
        }

        Task* temp = head;
        while (temp != nullptr) {
            outFile << temp->title << endl;
            outFile << temp->description << endl;
            outFile << temp->targetTime << endl;
            outFile << temp->priority << endl;
            outFile << (temp->completed ? "true" : "false") << endl;
            temp = temp->next;
        }

        outFile.close();
        cout << "Tasks saved to file: " << filename << endl;
    }

    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error: Unable to open file: " << filename << endl;
            return;
        }

        clearTasks();

        string line;
        while (getline(inFile, line)) {
            string title = line;
            string description, targetTime, priority;
            bool completed;

            getline(inFile, description);
            getline(inFile, targetTime);
            getline(inFile, priority);
            getline(inFile, line); 
            completed = (line == "true");

            addTask(title, description, targetTime, priority);
            head->completed = completed; 
        }

        inFile.close();
        cout << "Tasks loaded from file: " << filename << endl;
    }

private:
    void clearTasks() {
        while (head != nullptr) {
            Task* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class User {
public:
    string username;
    string password;

    User(const string& uname, const string& pwd) : username(uname), password(pwd) {}
};

class AuthenticationService {
private:
    unordered_map<string, string> users;

public:
    bool registerUser(const string& username, const string& password) {
        if (users.find(username) != users.end()) {
            cout << "Username already exists." << endl;
            return false;
        }
        users[username] = password;
        cout << "User registered successfully." << endl;
        return true;
    }

    bool loginUser(const string& username, const string& password) {
        if (users.find(username) == users.end() || users[username] != password) {
            cout << "Invalid username or password." << endl;
            return false;
        }
        cout << "User logged in successfully." << endl;
        return true;
    }
};

int main() {
    AuthenticationService authService;
    ToDoList todo;
    string username, password;
    int choice;

    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (!authService.registerUser(username, password)) {
            return 0;
        }
    }

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if (!authService.loginUser(username, password)) {
        return 0;
    }

    do {
        cout << "\nTo-Do List Application" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Delete Task" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Mark Tasks as Completed" << endl;
        cout << "5. Edit Task" << endl;
        cout << "6. Search Task" << endl;
        cout << "7. Save Tasks to File" << endl;
        cout << "8. Load Tasks from File" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string title, description, targetTime, priority, filename;
        int index;
        string input;

        switch (choice) {
            case 1:
                cout << "Enter task title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter target time to complete the task (YYYY-MM-DD HH:MM): ";
                getline(cin, targetTime);
                cout << "Enter task priority (High, Medium, Low): ";
                getline(cin, priority);
                todo.addTask(title, description, targetTime, priority);
                break;
            case 2:
                cout << "Enter task index to delete: ";
                cin >> index;
                todo.deleteTask(index - 1);
                break;
            case 3:
                todo.viewTasks();
                break;
            case 4:
                cout << "Enter task indices to mark as completed (comma separated): ";
                cin.ignore();
                getline(cin, input);
                {
                    vector<int> indices;
                    stringstream ss(input);
                    while (ss >> index) {
                        indices.push_back(index - 1);
                        if (ss.peek() == ',') ss.ignore();
                    }
                    todo.markCompleted(indices);
                }
                break;
            case 5:
                cout << "Enter task index to edit: ";
                cin >> index;
                cout << "Enter new task title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter new task description: ";
                getline(cin, description);
                cout << "Enter new target time to complete the task (YYYY-MM-DD HH:MM): ";
                getline(cin, targetTime);
                cout << "Enter new task priority (High, Medium, Low): ";
                getline(cin, priority);
                todo.editTask(index - 1, title, description, targetTime, priority);
                break;
            case 6:
                cout << "Enter task title to search: ";
                cin.ignore();
                getline(cin, title);
                todo.searchTask(title);
                break;
            case 7:
                cout << "Enter filename to save tasks: ";
                cin.ignore();
                getline(cin, filename);
                todo.saveToFile(filename); 
                break;
            case 8:
                cout << "Enter filename to load tasks from: ";
                cin.ignore();
                getline(cin, filename);
                todo.loadFromFile(filename); 
                break;
            case 9:
                cout << "Exiting application." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}