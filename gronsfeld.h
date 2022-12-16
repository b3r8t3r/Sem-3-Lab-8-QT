#ifndef GRONSFELD_H
#define GRONSFELD_H
#include <string>
using  namespace std;

class Gronsfeld
{
private:
    string message;
    int key;
    string lowercase_latin = "abcdefghijklmnopqrstuvwxyz";
    string uppercase_latin = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
    Gronsfeld();
    Gronsfeld(string _message, int _key);
    void SetMessage(string _message);
    void SetKey(int _key);
    void Encrypt();
    void Decrypt();
    string GetMessage();
    ~Gronsfeld();
};

#endif // GRONSFELD_H
