#ifndef VIGINER_H
#define VIGINER_H
#include <string>
using namespace std;
class Viginer{
private:
    string message;
    string key;
public:
    Viginer();
    Viginer(string _message, string _key);
    void SetMessage(string _message);
    void SetKey(string _key);
    void Encrypt();
    void Decrypt();
    string GetMessage();
    ~Viginer();
};

#endif // VIGINER_H
