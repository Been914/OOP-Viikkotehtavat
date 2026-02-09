#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
  private:
    string name;
    int age;

  public:
    Student(string n, int a) : name(n), age(a) {}
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    string getName() const { return name; }
    int getAge() const { return age; }
    void printStudentInfo() const
    {
      cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main ()
{
  int selection =0;
  vector<Student>studentList;

  do
    {
      cout<<endl;
      cout<<"Select"<<endl;
      cout<<"Add students = 0"<<endl;
      cout<<"Print all students = 1"<<endl;
      cout<<"Sort and print students according to Name = 2"<<endl;
      cout<<"Sort and print students according to Age = 3"<<endl;
      cout<<"Find and print student = 4"<<endl;
      cin>>selection;

      switch(selection)
      {
        case 0: {
          cout << "anna nimi ja ikä: " << endl;
          string name;
          int age;
          cin >> name >> age;
          studentList.emplace_back(name, age);
          break;
        }
        case 1: {
          for (const auto& student : studentList)
          {
            student.printStudentInfo();
          }
          break;
        }
        case 2: {
           sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
            return a.getName() < b.getName();
          });
          for (const auto& student : studentList)
          {
            student.printStudentInfo();
          }
         break;
        }
        case 3: {
          sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b)
          {
            return a.getAge() < b.getAge();
          });
          for (const auto& student : studentList)
          {
            student.printStudentInfo();
          }
          break;
        }
        case 4: {
          cout << "anna nimi" << endl;
          string n;
          cin >> n;
          auto it = find_if(studentList.begin(), studentList.end(), [n](const Student& obj) {return obj.getName() == n;
          });
          if (it != studentList.end())
          {
            it-> printStudentInfo();
          }
          else
          {
            cout << "ei löytynyt" << endl;
          }
          break;
        }
        default:
          cout<< "Wrong selection, stopping..."<<endl;
          break;
      }
    }while(selection < 5);

  return 0;
}