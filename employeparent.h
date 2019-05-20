#include <iostream>
#include "class.h"
#ifndef EMPLOYE_H
#define EMPLOYE_H

class Employee{
    private:
        string Name;
        int eId;
    public:
        Employee(string Name, int eId){
            this->Name=Name;
            this->eId=eId;
        }
        int getEmployeId(){
            return eId;
        }
        string getName(){
            return Name;
        }
};

class FullTimeEmployee: public Employee{
    private:
        int salary;
    public:
        FullTimeEmployee(string Name, int eId, int salary=0):Employee(Name,eId){
            this->salary = salary;
        }
        int getSalary(){ return salary;}
        friend ostream& operator<<(ostream& os, FullTimeEmployee emp){
            os<<"Salary of "<<emp.getName()<<" is "<<emp.getSalary();
            return os;
        }
};

class PartTimeEmployee: public Employee{
    private:
        int wage;
    public:
        PartTimeEmployee(string Name, int eId, int wage=0):Employee(Name,eId){
            this->wage = wage;
        }
        int getWage(){ return wage;}
        friend ostream& operator<<(ostream& os, PartTimeEmployee emp){
            os<<"Wage of "<<emp.getName()<<" is "<<emp.getWage();
            return os;
        }
};

#endif