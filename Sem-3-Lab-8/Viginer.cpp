#include "Viginer.h"

Viginer::Viginer(){
    message = "";
    key = "";
}

Viginer::Viginer(string _message, string _key){
    message = _message;
    key = _key;
}

void Viginer::SetMessage(string _message){
    message = _message;
}

void Viginer::SetKey(string _key){
    key = _key;
}

void Viginer::Encrypt(){
    int keyLen = key.size();

        for (int i = 0, j = 0; i < int(message.size()); i++)
        {
            if (message[i] == 32) continue;
            if (message[i] > 64 && message[i] < 91)
            {
                message[i] += key[j % keyLen] - 'a';
                j++;
                if (message[i] > 90)
                    message[i] -= 26;
            }
            else if (message[i] > 96 && message[i] < 123)
            {
                message[i] -= 32;
                message[i] += key[j % keyLen] - 'a';
                j++;
                if (message[i] > 90)
                {
                    message[i] -= 26;
                }
                message[i] += 32;
            }
        }
}

void Viginer::Decrypt(){
    int keyLen = key.size();
        for (int i = 0, j = 0; i < int(message.size()); i++)
        {
            if (message[i] == 32) continue;
            if (message[i] > 64 && message[i] < 91)
            {
                message[i] -= key[j % keyLen] - 'a';
                j++;
                if (message[i] < 65)
                    message[i] += 26;
            }
            else if (message[i] > 96 && message[i] < 123)
            {
                message[i] -= 32;
                message[i] -= key[j % keyLen] - 'a';
                j++;
                if (message[i] < 65)
                    message[i] += 26;

                message[i] += 32;
            }
        }
}

string Viginer::GetMessage(){
    return message;
}

Viginer::~Viginer(){
    message = "";
    key = "";
}
