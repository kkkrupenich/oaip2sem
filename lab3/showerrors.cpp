#include "showerrors.h"

Errors::Errors(string error)
{
    my_error = error;
}

void checkInt(QString s)
{
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] > '9' || s[i] < '0') throw Errors("Incorrent INT number (0..9 digits expected)");
    }
}

void checkDouble(QString s)
{
    int cntDots = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '.')
        {
            if (cntDots > 0) throw Errors("Incorrect DOUBLE number (too many dots)");
            if (i + 1 == s.size()) throw  Errors("Incorrect DOUBLE number (last digit is dot)");
            cntDots++;
            continue;;
        }
        if (s[i] > '9' || s[i] < '0') throw Errors("Incorrent DOUBLE number (0..9 digits expected)");
    }
}
