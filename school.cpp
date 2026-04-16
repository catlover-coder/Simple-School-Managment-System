#include<iostream>
#include<string>
#include<vector>

using namespace std;

int nextId = 1;

class student{
    public:
    string name;
    int id;
    int age;
    int marksOfMath;
    int marksOfScience;
    int marksOfComputer;
    int marksOfEnglish;

    student(string n, int i, int a) : name(n), id(i), age(a) {}

    void marks(int mM, int mS, int mC, int mE) {
        this->    marksOfMath = mM;
        this->    marksOfScience = mS;
        this->    marksOfComputer = mC ;
        this->    marksOfEnglish = mE;
    }

    int totalMarks() {
        return (marksOfMath + marksOfComputer + marksOfEnglish + marksOfScience) / 4;
    }
};

void addStudent(vector<student> &cf);
void veiwStudents(vector<student> &d);
void deleteStudents(vector<student> &c);
void marksCalculator(vector<student> &f);

int main() {
    vector<student> cf;
    int choice;

    while(true) {

        cout << "1.add a new student detail" << endl;
        cout << "2.marks calculation" << endl;
        cout << "3.veiw all student" << endl;
        cout << "4.delete student detail" << endl;
        cout << "5.exit" << endl;

        cout << "what you want first? " << endl;        
        cin >> choice;

        switch(choice) {
            case 1:
            addStudent(cf);
            break;

            case 2:
            marksCalculator(cf);
            break;

            case 3:
            veiwStudents(cf);
            break;

            case 4:
            deleteStudents(cf);
            break;

            case 5:
            cout << "thanks for using our program!!!";
            return 0;
        }

    }
}

void addStudent(vector<student> &cf) {
    string na;
    int ag;

    cout << "Enter the student name: " << endl;
    cin >> na;

    cout << "Enter the student age: " << endl;
    cin >> ag;
    //automatically it will generate ID
    int iD = nextId;  
    nextId++;  
    
    cout << "student id: " << iD << endl;

    student A(na, iD, ag);
    cf.push_back(A);
}

void veiwStudents(vector<student> &d) {
    if(d.size() == 0) {//throw an problem
        cout << "no student detail available";
    }else {
        //loop and prints all student details
        for(int i = 0; i < d.size(); i++) {
        cout << "ID: " << d[i].id << ", Name: " << d[i].name << ", Age: " << d[i].age << endl;  // Fixed: can't output object directly
        }

    }
}

void deleteStudents(vector<student> &c) {
    int DeleteIDS;
    
    cout << "write the student ID to delete: ";
    cin >> DeleteIDS;
    
    if(c.size() == 0) {
        cout << "no student detail available";
        return;  // Exit early if empty
    }
    
    for(auto it = c.begin(); it != c.end(); ++it) {
        if(DeleteIDS == it->id) {
            c.erase(it);
            cout << "Student deleted successfully" << endl;
            return;  // Exit after deleting (assuming unique IDs)
        }
    }
    cout << "no student found!" << endl;
}

void marksCalculator(vector<student> &f) {
    string sname;
    int maths, computer, english, science;
    bool found = false;

    cout << "For which student do you want to calculate marks?" << endl;
    cin >> sname;

    if(f.size() == 0) {
        cout << "No student details available" << endl;
        return;
    }

    for(auto it2 = f.begin(); it2 != f.end(); ++it2) {
        if(sname == it2->name) {
            found = true;
            
            cout << "How many marks did " << sname << " get in maths: ";
            cin >> maths;
            
            cout << "How many marks did " << sname << " get in computer: ";
            cin >> computer;

            cout << "How many marks did " << sname << " get in science: ";
            cin >> science;

            cout << "How many marks did " << sname << " get in english: ";
            cin >> english;

            // Assuming student class has a method to set/add marks
            it2->marks(maths, science, computer, english);
            cout << "The total marks of " << sname << " is " << it2->totalMarks() << endl;
            return;  // Exit after finding and updating
        }
    }
    
    if(!found) {
        cout << "Student with name " << sname << " not found!" << endl;
    }
}
