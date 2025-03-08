#include <iostream>
#include <fstream>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

// Function for reading students.txt
unordered_set<string> get_applicantsnames() {
    unordered_set<string> students;
    string filename = "students.txt"; 

    ifstream file(filename);
    if (!file) {  
        cerr << "Error opening the file: " << filename << endl;
        return students;
    }

    string name;
    while (getline(file, name)) {
        students.insert(name);
    }

    file.close();
    return students;
}

// Function to obtain the initials of the names
string get_initials(const string& name) {
    if (name.empty()) return "";
    
    size_t space = name.find(' ');
    if (space == string::npos) return ""; 

    return string(1, name[0]) + string(1, name[space + 1]);  // First letter of the first name and the first letter of the last name
}

// Code to find matches between initials
queue<const string*> find_matches(const unordered_set<string>& students, const string& my_name) {
    queue<const string*> matches;
    string my_initials = get_initials(my_name);

    for (const string& student : students) {
        if (get_initials(student) == my_initials) {
            matches.push(&student);  
        }
    }

    return matches;
}

// Function to get a match from the queue
void get_match(queue<const string*>& matches) {
    if (matches.empty()) {
        cout << "NO MATCHES FOUND. Better luck next year :(" << endl;
        return;
    }

    const string* match = matches.front();  
    matches.pop();
    
    cout << "Your match is: " << *match << endl;  
}

int main() {
    string my_name = "Adrián Quel";  

    // Get the list of applicants
    unordered_set<string> students = get_applicantsnames();

    // Find coincidence based on initials
    queue<const string*> matches = find_matches(students, my_name);

    // Find the match
    get_match(matches);

    return 0;
}
