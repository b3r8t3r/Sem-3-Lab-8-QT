#ifndef ATBASH_H
#define ATBASH_H
#include <string>
using namespace std;

class Atbash
{
private:
    string message;
    string lowercase_latin = "abcdefghijklmnopqrstuvwxyz";
    string uppercase_latin = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
    Atbash();
    Atbash(string _message);
    void SetMessage(string _message);
    void Encrypt();
    void Decrypt();
    string GetMessage();
    ~Atbash();
};

#endif // ATBASH_H
