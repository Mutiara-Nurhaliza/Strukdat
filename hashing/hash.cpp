#include <iostream>
#include <map>
#include <bitset>
using namespace std;


map<string, string> dataAkun;

string hashFunction(const string &password)
{
    int hash = 0;

    for (char c : password)
    {
        hash ^= static_cast<int>(c);
    }

    bitset<32> binaryHash(hash);

    return binaryHash.to_string();
}

void printAll()
{
    for (auto i = dataAkun.begin(); i != dataAkun.end(); i++)
    {
        cout << "Key: " << i->first << " \t\t\t"
             << "Value: " << i->second << endl;
    }
}

void menu()
{
    while (true)
    {
        int input_user;

        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Register" << endl;
        cout << "3. Exit" << endl
             << endl;

        cout << "Pilih: " << endl;
        cin >> input_user;
        cout << endl;

        if (input_user == 1)
        {
            string username, password;

            cout << "Masukkan Username: " << endl;
            cin >> username;
            cout << "Masukkan Password: " << endl;
            cin >> password;

            string hashedPassword = hashFunction(password);
            dataAkun[username] = hashedPassword;
        }
        else if (input_user == 2)
        {
            cout << "Menu Login" << endl;
        }
        else if (input_user == 3)
        {
            printAll();

            break;
        }
        else
        {
            cout << "Invalid!" << endl;
        }
    }
}

int main()
{
    menu();
}
