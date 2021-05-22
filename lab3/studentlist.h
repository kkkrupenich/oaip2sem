#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <QString>

class Student
{
public:
    QString firstname, lastname, fathersname, group;
    int salary;
    double marks;

    Student *next = nullptr;

    QString toString()
    {
        QString result;
        result += "Ф.И.О. : " + lastname + ' ' + firstname + ' ' + fathersname + " \n";
        result += "Группа: " + group + " \n";
        result += "Доход на члена семьи: " + QString::number(salary) + " \n";
        result += "Средний балл: " + QString::number(marks) + " \n";
        return result;
    }
};


class studentlist
{
public:
    studentlist();

    Student *head = nullptr;
    Student *tail = nullptr;

    void push(Student *item)
    {
        if(!head)
        {
            head = item;
            tail = item;
        }
        else
        {
            tail->next = item;
            tail = item;
        }
    }

    QString getAll()
    {
        QString result;
        Student *student = new Student;
        student = head;
        while(student)
        {
            result += student->toString();
            result += '\n';
            student = student->next;
        }
        return result;
    }

    QString getByName(QString value)
    {
        QString result;
        Student *student = head;
        while(student)
        {
            if(student->lastname == value)
            {
                result += student->toString();
                result += '\n';
            }
            student = student->next;
        }
        return result;
    }
    void delByIndex(int index)
    {
        if(!head) return;
        if(index == 0)
        {
            Student *oldHead = head;
            head = head->next;
            delete oldHead;
            return;
        }
        Student *prev = head;
        Student *current = head->next;
        for(int i = 1; current; i++)
        {
            if(i == index)
            {
                if(!current->next) tail = prev;
                prev->next = current->next;
                delete current;
                return;
            }
        }
        prev = current;
        current = current->next;
    }
    QString getMoreThanSalary(int value)
    {
        QString result;
        Student *student = head;
        while(student)
        {
            if(student->salary > value)
            {
                result += student->toString();
                result += '\n';
            }
            student = student->next;
        }
        return result;
    }
    QString getLowMarks(double marks)
    {
        QString result;
        Student *student = head;
        while(student)
        {
            if(student->marks < marks && student->salary > 800)
            {
                result += student->toString();
                result += '\n';
            }
            student = student->next;
        }
        return result;
    }

};

#endif // STUDENTLIST_H
