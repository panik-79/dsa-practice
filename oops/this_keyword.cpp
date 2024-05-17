#include<iostream>
using namespace std;

class Student{

    // data members
    bool hasGf; 
    public:
    int id;
    string name;
    int age;

    Student(){
        cout << "default student constructor called"<<endl;
    }

    Student(int id, string name, int age){
        this->id = id;
        this->name = name;
        this->age = age;
        cout<<"parameterized student constructor called"<<endl;
    }

    // 'this' is a pointer to the object that is calling the function (reference to the current object)
    // it is added in class by compiler implicitly as a hidden argument to the function

    // member functions
    void study(){
        cout<<"Studying"<<endl;
    }

    void sleep(){
        cout<<"Sleeping"<<endl;
    }

};


int main(){
    Student s1;
    Student s2;
    s1.id = 1;
    s1.name = "John";
    s1.age = 20;

    s2.id = 2;
    s2.name = "Doe";
    s2.age = 21;

    cout<<s1.id<<" "<<s1.name<<" "<<s1.age<<endl;
    cout<<s2.id<<" "<<s2.name<<" "<<s2.age<<endl;

    Student s3(3, "Alice", 22);
    cout<<s3.id<<" "<<s3.name<<" "<<s3.age<<endl;

    // above 3 objects are created in stack memory (default memory allocation) and are destroyed when they go out of scope (main function ends)  

    // creating object in heap memory
    Student *s4 = new Student(4, "Bob", 23);
    cout<<s4->id<<" "<<s4->name<<" "<<s4->age<<endl;
    // can also be accesed using (*s4).id, (*s4).name, (*s4).age
    // cout<<(*s4).id<<" "<<(*s4).name<<" "<<(*s4).age<<endl;
    // *s4 is a pointer to the object in heap memory and is not destroyed when it goes out of scope (main function ends) 

    // deleting object from heap memory
    delete s4; // ensures that the memory is deallocated and the object is destroyed
    // no memory leak

    return 0;
}