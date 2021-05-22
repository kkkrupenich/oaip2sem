#ifndef SHOWERRORS_H
#define SHOWERRORS_H
#include <exception>
#include <string>
#include <QString>

using namespace std;

class Errors: exception
{
private:
    string my_error;

public:
    Errors(string error);

    const char* what() const noexcept {return my_error.c_str();}
};

void checkInt(QString s);

void checkDouble(QString s);

#endif // SHOWERRORS_H
