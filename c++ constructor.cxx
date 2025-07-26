#include <iostream>
class Student
{
  public:
    std::string name;
    int age;
    double gpa;
    Student(std::string x, int y, double z)
    {
        name = x;
        age = y;
        gpa = z;
    }
    void eating(std:: string food = "apple"){
        std::cout<< name << " is eating "<<food<< "😻🥣"<<std::endl;
        }
};

int main()
{
    Student student1("Bibek", 19, 3.15);
    std::cout << student1.name<< std::endl;
    student1.eating();
    return 0;
}
