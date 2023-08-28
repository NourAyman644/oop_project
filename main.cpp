#include <bits/stdc++.h>

using namespace std;
class  Department{
private:
    string name;
    int capacity;
    double requiredGpa;
public:
    Department(){
        name="";
        capacity=0;
        requiredGpa=0;

    }
    void setName(string name){
        this->name=name;
    }
    void setCapacity(int capacity){
        this->capacity=capacity;
    }
    void setRequiredGpa(double requiredGpa){
        this->requiredGpa=requiredGpa;
    }
    string getName(){ return name;}
    int getCapacity(){return capacity;}
    double getReqiredGpa(){ return requiredGpa;}
    Department(string name,int capacity,double requiredGpa){
        setCapacity(capacity);
        setName(name);
        setRequiredGpa(requiredGpa);
    }

};
class Person {

protected:
    // Data members
    string name;
    int id;
    char gender;
    int age;

public:

    //  string university;

    // Member functions
    Person() {
        name = "";
        id = 0;
        age = 0;
        //  university = "";
        gender='f';
    }

    Person(int id , string name , int age, char gender ) {

        // this->university = university;
    }

    void setName(string name) {
        this->name = name;
    }

    void setId(int id) {
        this->id = id;
    }

    void setGender(char gender) {
        this->gender = gender;
    }

    void setAge(int age) {
        this->age = age;
    }

//    void setUniversity(string university) {
//        this->university = university;
//    }

    string getName() {
        return name;
    }

    int getId() {
        return id;
    }

    char getGender() {
        return gender;
    }

    int getAge() {
        return age;
    }

//    string getUniversity() {
//        return university;
//    }

//    void print() {
//        cout << "Name: " << name << endl;
//        cout << "ID: " << id << endl;
//        cout << "Gender: " << gender << endl;
//        cout << "Age: " << age << endl;
////        cout << "University: " << university << endl;
//    }
};
class Student : public Person
{

private:
    int level;
    double gpa;

public:


    // parameterized constructor
    Student(int id , string name ,int age, char gender  ,int level , double gpa)
    {
        this-> level = level ;
        this-> gpa = gpa ;
        this->name=name;
        this->age=age;
        this->gender=gender;
        this->id=id;

    }

    // Seter & Geter Functions
    void set_level (int level)
    {
        this-> level = level ;
    }
    int get_level ()
    {
        return level ;
    }
    void set_gpa (double gpa)
    {
        this-> gpa = gpa ;
    }
    double get_gpa ()
    {
        return gpa;
    }
    void attend()
    {
        cout<<"student "<<name<<" "<<"atended\n";
    }
};
class Professor : public Person {
private:
    string degree;
    double salary;
    Department *department;
public:
    Professor()
    {

    }
    //          1,"Mohamed Ali", 56, 'M', &d1, 12000, "Masters"
    Professor(int id, string name, int age, char gender, Department* department , double salary, string degree) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->degree = degree;
        this->salary = salary;
        this->department = department;
    }

    ///// Setters /////

    void setDegree(string g ) {
        degree = g;
    }
    void setDepartment(Department *d) {
        department = d;
    }
    void setSalary(double s) {
        salary = s;
    }

    ///// Getters /////
    string getDegree() {
        return degree;
    }
    Department *getDepartment() {
        return department;
    }
    double getSalary() {
        return salary;
    }
};

class Course
{

private:
    string courseName, courseCode ;
    int courseHours ;
    vector<Course*> prerequisites ;
    Professor *professor_obj ;
    vector<Student*>  students_obj ;

public:

    Course( string Name , string Code , int Hours , vector<Course*> courses , Professor *professor , vector<Student*> students ) {

        courseName = Name ;
        courseCode = Code ;
        courseHours = Hours;
        prerequisites = courses ;
        professor_obj = professor ;
        students_obj = students;
    }


    // Setters & Getters of  prerequisites
    void set_prerequisites( vector<Course*> courses)
    {
        prerequisites = courses ;
    }
    vector<Course*> get_prerequisites()
    {
        return prerequisites ;
    }

    // Setters & Getters of  Professor
    void set_professor( Professor *professor)
    {
        professor_obj = professor ;
    }
    Professor* get_Professor()
    {
        return professor_obj ;
    }

    // Setters & Getters of  students
    void set_students( vector<Student*> students)
    {
        students_obj = students ;
    }
    vector<Student*> get_students()
    {
        return students_obj ;
    }


    // Name setters & getters
    void setCourseName(string coursName)
    {
        courseName = coursName ;
    }

    string getCourseName()
    {
        return courseName ;
    }


    //  Code setters & getters
    void setCourseCode(string coursCode)
    {
        courseCode = coursCode ;
    }

    string getCourseCode()
    {
        return courseCode ;
    }


    // Hours setters & getters
    void setCourseHours(int coursHours)
    {
        courseHours = coursHours ;
    }

    int getCourseHours()
    {
        return courseHours ;
    }




};


class Universty {

    static Universty *instancePtr;
    vector<Department > departments;
    vector<Course> courses;
    vector<Professor> professors;
    vector<Student> students;
    Universty() {addData();}

    // Universty(const Universty &obj) = delete;
public:
    static Universty *getInstance() {
        if (instancePtr == NULL) {
            instancePtr = new Universty();
        }
        return instancePtr;
    }
    // department

    void addDepartment(const Department &newDepartment){
        departments.push_back(newDepartment);
    }
    void deleteDepartment(const string name){
        for ( int it=0;it<departments.size();it++) {
            if(departments[it].getName()==name){
                departments.erase(departments.begin()+it);
                return;
            }
        }
        cout<<"No Deparment with exit name\n";

    }
    void updateDeparment(const string oldName,int capacity){

        for ( int it=0;it<departments.size();it++) {
            if(departments[it].getName()==oldName){
                departments[it].setCapacity(capacity);
                return;
            }
        }
        cout<<"No Deparment with exit name\n";

    }
// proffesor
    void addProffesor(int id, string name, int age, char gender, Department* department , double salary, string degree) {
        Professor newProfessor(id, name, age, gender, department, salary, degree);
        professors.push_back(newProfessor);
    }
    void updateProfessor(int id, double salary) {
        for (Professor newProfessor : professors) {
            if (newProfessor.getId() == id) {
                newProfessor.setSalary(salary);
            }
        }

    }
    void deleteProfessor(int id, string name, int age, char gender, Department* department , double salary, string degree) {
        for (int i = 0; i < professors.size(); i++) {
            if (professors[i].getId() == id) {
                professors.erase(professors.begin() + i);
                break;
            }
        }

    }

//student
    // to Add_student
    void add_student(int id , string name ,int age, char gender  ,int level , double gpa)
    {
        Student obj (id , name  ,age,gender ,level , gpa);

        students.push_back(obj);
    }

    // to update_student by level
    void update_student(int id ,int level)
    {
        for (int i = 0 ; i<students.size();++i )
        {

            if (students[i].getId()==id)
                students[i].set_level(level);
            return;
        }
        cout<<"NOT FOUND!!\n";
    }

    // to remove_student by level
    void remove_student(int id)
    {
        for (int i = 0 ; i<students.size();++i )
        {
            if (students[i].getId ()==id)
            {
                students.erase(students.begin()+i);
                return;
            }


        }

    }

    // string Name , string Code , int Hours , vector<Course> courses , Professor professor , vector<Student> students
    // -- add Course --
    void add_course( string name , string code , int hours , vector<Course*> courses ,Professor *professor , vector<Student*> students )
    {
        Course new_course( name , code , hours , courses , professor , students) ;
        courses.push_back(&new_course);
    }


    void update_course( string course_code , int course_hours  )
    {
        for ( int i=0 ; i< courses.size() ; i++ )
        {
            if( courses[i].getCourseCode() == course_code)
            {
                courses[i].setCourseHours(course_hours);
                return ;
            }
        }
        cout << " This Course does not exist \n";
    }


    void remove_course ( string code)
    {
        for( int i=0 ; i< courses.size() ; i++ )
        {
            if( courses[i].getCourseCode() == code)
            {
                courses.erase(courses.begin() + i ) ;
                return ;
            }

        }
        cout << " This Course does not exist \n" ;
    }




    void addData()
    {
        Department d1("Web Development", 50, 3.2);
        departments.push_back(d1);
        Department d2("Cyber Security", 33, 3.5);
        departments.push_back(d2);
        Department d3("Artificial Intelligence", 20, 3.0);
        departments.push_back(d3);
        Department d4("Information Systems", 125, 2.5);
        departments.push_back(d4);

        Student s1(1,"Ahmed Ali", 19, 'M', 2, 2.74);
        students.push_back(s1);
        Student s2(2,"Mirna Hussein", 22, 'F', 4, 3.68);
        students.push_back(s2);
        Student s3(3,"Hamada Hossam", 28, 'M', 3, 2.37);
        students.push_back(s3);
        Student s4(4,"Taghreed Mohsen", 20, 'F', 3, 3);
        students.push_back(s4);
        Student s5(5,"Yasmin Belal", 18, 'F', 1, 3.71);
        students.push_back(s5);
        Student s6(6,"Amr Diab", 50, 'M', 4, 2.01);
        students.push_back(s6);
        Student s7(7,"Tamer Hosny", 30, 'M', 3, 2.02);
        students.push_back(s7);
        Student s8(8,"Ahmed Alaa", 21, 'M', 2, 2.49);
        students.push_back(s8);

        Professor p1(1,"Mohamed Ali", 56, 'M', &d1, 12000, "Masters");
        professors.push_back(p1);
        Professor p2(2,"Ehsan Ahmed", 43, 'M', &d2, 8500, "Masters");
        professors.push_back(p2);
        Professor p3(3,"Ahmed Mohsen", 68, 'M', &d3, 19380, "Masters");
        professors.push_back(p3);
        Professor p4(4,"Abdelhady", 61, 'M', &d4, 22728, "Masters");
        professors.push_back(p4);
        Professor p5(5,"Taghreed Mohsen", 49, 'F', &d2, 11068, "Masters");
        professors.push_back(p5);


        vector<Student*> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student*> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1("HTML", "HTML123", 12, vector<Course*>(), &p1, st1);
        courses.push_back(c1);
        vector<Course*> crs1;
        crs1.push_back(&c1);
        Course c2("CSS", "CSS123", 9, crs1,&p3, st2);
        courses.push_back(c2);
        Course c3("Networks", "Net521", 18, crs1, &p5, st2);
        courses.push_back(c3);
    }

    void printAll()
    {
        for(int i=0; i<departments.size(); i++)
        {
            cout<<"Department: "<<departments[i].getName()<<endl;
        }
        for(int i=0; i<professors.size(); i++)
        {
            cout<<"Professor Name: "<<professors[i].getName()<<endl;
        }
        for(int i=0; i<students.size(); i++)
        {
            cout<<"Student Name: "<<students[i].getName()<<endl;
        }
        for(int i=0; i<courses.size(); i++)
        {
            cout<<"Course Name: "<<courses[i].getCourseName()<<endl;
        }
    }

};


Universty *Universty::instancePtr = NULL;


int main(){


    Universty *uni = Universty::getInstance();
    uni->printAll();
}