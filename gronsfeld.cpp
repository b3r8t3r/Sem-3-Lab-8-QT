#include "gronsfeld.h"
#include <math.h>
#include <vector>

Gronsfeld::Gronsfeld()
{
    message = "";
    key = 0;
}

Gronsfeld::Gronsfeld(string _message, int _key){
    message = _message;
    key = _key;
}

void Gronsfeld::SetMessage(string _message){
    message = _message;
}
void Gronsfeld::SetKey(int _key){
    key = _key;
}
void Gronsfeld::Encrypt(){

    int keyLen = 0;
    for (int temp = key; temp > 0; keyLen++) {
        temp /= 10;
    }

    for (long long int i = 0, t1, t2, latin_symb_count = 0; i < int(message.size()); i++) {
        if (!((message[i] >= 'A' && message[i] <= 'Z') || (message[i] >= 'a' && message[i] <= 'z'))) continue;

        t2 = keyLen - 1 - latin_symb_count;
        if (t2 < 0)
            t2 = (t2%keyLen + (keyLen))%keyLen;

        t1 = pow(10, t2);

        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] += ((key / t1) % 10);
            if (message[i] > 'Z') message[i] = (message[i] - 'Z') % 26 + 'A' - 1;
        }
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] += ((key / t1) % 10);
            if (message[i] > 'z') message[i] = (message[i] - 'z') % 26 + 'a' - 1;
        }

        latin_symb_count++;
    }

}
void Gronsfeld::Decrypt(){
    int keyLen = 0;
    for (int temp = key; temp > 0; keyLen++) {
        temp /= 10;
    }
    for (long long int i = 0, t1, t2, latin_symb_count = 0; i < int(message.size()); i++) {
        if (!((message[i] >= 'A' && message[i] <= 'Z') || (message[i] >= 'a' && message[i] <= 'z'))) continue;
        t2 = keyLen - 1 - latin_symb_count;
        if (t2 < 0)
            t2 = (t2 % keyLen + (keyLen)) % keyLen;
        t1 = pow(10, t2);

        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] -= ((key / t1) % 10);
            if (message[i] < 'A') message[i] = (message[i] - 'A') % 26 + 'Z' + 1;
        }
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] -= ((key / t1) % 10);
            if (message[i] < 'a') message[i] = (message[i] - 'a') % 26 + 'z' + 1;
        }

        latin_symb_count++;
    }

}
string Gronsfeld::GetMessage(){
    return message;
}
Gronsfeld::~Gronsfeld(){
    message = "";
    key =0;
}
