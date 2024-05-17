#include<iostream>
using namespace std;

class Student{

    // data members
    bool hasGf; // default access specifier is private . So, we can't access it outside the class
    public: // we need to specify access specifier to make it public and accessible outside the class
    int id;
    string name;
    int age;


    // default constructor (if not declared, compiler will create one for us)
    // default constructor is a constructor that doesn't take any arguments. It assigns garbage values to the data members.
    Student(){
        cout << "default student constructor called"<<endl;
    }

    // constructor(ctor) is the only function that doesn't have return type (not even void)
    // public 
    // constructor is used to initialize the object and therefore it cannot be private
    Student(int _id, string _name, int _age){
        id = _id;
        name = _name;
        age = _age;
        cout<<"parameterized student constructor called"<<endl;
    }

    // many more constructors can be created with different number of arguments
    // this is called constructor overloading (function overloading) or basically polymorphism


    // member functions
    void study(){
        cout<<"Studying"<<endl;
    }

    void sleep(){
        cout<<"Sleeping"<<endl;
    }

    void bunk(){
        cout<<"Bunking"<<endl;
    }

    private:
    void chattingWithGf(){
        if(hasGf){
            cout<<"Chatting with gf"<<endl;
        }else{
            cout<<"No gf"<<endl;
        }
    }
};

int main(){
    Student s1;
    Student s2;
    // accessing public members
    s1.name = "Pujan";
    s2.name = "Ishita";
    s1.age = 20;
    s2.age = 19;
    s1.id = 1;
    s2.id = 2;

    // above method is very combursome. We can use constructor to initialize the object

    Student s3(3, "Rahul", 21);

    cout << s3.age;
}