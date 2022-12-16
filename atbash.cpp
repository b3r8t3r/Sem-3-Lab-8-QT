#include "atbash.h"

Atbash::Atbash()
{
    message = "";
}

Atbash::Atbash(string _message){
    message = _message;
}

void Atbash::SetMessage(string _message){
    message = _message;
}

void Atbash::Encrypt(){
    int num = 0;
    for (int count = 0; count < int(message.length()); count++) {
        if (!(((message[count]>64)&&(message[count]<91))||((message[count]>96)&&(message[count]<123)))) continue;
        for (int i = 0; i < int(lowercase_latin.length()); i++) {
            if (message[count] == lowercase_latin[i]) {
                if (i != int(lowercase_latin.length())) {
                    num = lowercase_latin.length() - i - 1;
                }
                message[count] = lowercase_latin[num];
                break;
            }
            if (message[count] == uppercase_latin[i]) {
                if (i != int(uppercase_latin.length())) {
                    num = uppercase_latin.length() - i - 1;
                }
                message[count] = uppercase_latin[num];
                break;
            }
        }
    }
}

void Atbash::Decrypt(){
    int num;
        for (int count = 0; count < int(message.length()); count++) {
            if (!(((message[count]>64)&&(message[count]<91))||((message[count]>96)&&(message[count]<123)))) continue;
            for (int i = 0; i < int(lowercase_latin.length()); i++) {
                if (message[count] == lowercase_latin[i]) {
                    num = int(lowercase_latin.length()) - i - 1;
                    message[count] = lowercase_latin[num];
                    break;
                }
                if (message[count] == uppercase_latin[i]) {
                    num = int(uppercase_latin.length()) - i - 1;
                    message[count] = uppercase_latin[num];
                    break;
                }
            }
        }
}

string Atbash::GetMessage(){
    return message;
}

Atbash::~Atbash(){
    message = "";
    lowercase_latin = "";
    uppercase_latin = "";
}
