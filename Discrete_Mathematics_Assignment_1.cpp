#include <iostream>
#include <string>
using namespace std;

int digit_length(string digit);
int binary_to_decimal(string digit, int length);
int octal_to_decimal(string digit, int length);
int hexa_to_decimal(string digit, int length);
int decimal_string_to_decimal(string digit, int length);
string decimal_to_binary(int decimal);
string decimal_to_octal(int decimal);
string decimal_to_hexa(int decimal);
string encrypt_message(string message, int base);
string decrypt_message(string encrypted, int base);
int get_base();

int main()
{
    int choice;
    do
    {
        system("cls");
        cout << "\nMenu:\n";
        cout << "1. Number System Conversion\n";
        cout << "2. Encrypt a Message\n";
        cout << "3. Decrypt a Message\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            string digit;
            int b;
            int decimal = 0;
            cout << "Enter the digit: ";
            cin >> digit;
            b = get_base();
            int length = digit_length(digit);

            if (b == 2)
            {
                decimal = binary_to_decimal(digit, length);
            }
            else if (b == 8)
            {
                decimal = octal_to_decimal(digit, length);
            }
            else if (b == 16)
            {
                decimal = hexa_to_decimal(digit, length);
            }
            else if (b == 10)
            {
                decimal = decimal_string_to_decimal(digit, length);
            }
            else
            {
                cout << "Invalid base!" << endl;
                system("pause");
                continue;
            }
            cout << "Decimal number: " << decimal << endl;

            if (b != 2)
            {
                string binary = decimal_to_binary(decimal);
                cout << "Binary number: " << binary << endl;
            }
            if (b != 8)
            {
                string octal = decimal_to_octal(decimal);
                cout << "Octal number: " << octal << endl;
            }
            if (b != 16)
            {
                string hexa = decimal_to_hexa(decimal);
                cout << "Hexadecimal number: " << hexa << endl;
            }
            if (b != 10)
            {
                cout << "Decimal number: " << decimal << endl;
            }
            system("pause");
        }
        else if (choice == 2)
        {
            system("cls");
            cin.ignore();
            string message;
            cout << "Enter the message to encrypt: ";
            getline(cin, message);
            int base = get_base();

            if (base == 2 || base == 8 || base == 10 || base == 16)
            {
                string encrypted = encrypt_message(message, base);
                cout << "Encrypted message: " << encrypted << endl;
            }
            else
            {
                cout << "Invalid base for encryption!" << endl;
            }
            system("pause");
        }
        else if (choice == 3)
        {
            system("cls");
            cin.ignore();
            string encrypted;
            cout << "Enter the encrypted message: ";
            getline(cin, encrypted);
            int base = get_base();

            if (base == 2 || base == 8 || base == 10 || base == 16)
            {
                string decrypted = decrypt_message(encrypted, base);
                cout << "Decrypted message: " << decrypted << endl;
            }
            else
            {
                cout << "Invalid base for decryption!" << endl;
            }
            system("pause");
        }
        else if (choice == 4)
        {
            cout << "Exiting the program." << endl;
        }
        else
        {
            cout << "Invalid choice! Please try again." << endl;
            system("pause");
        }
    } while (choice != 4);

    return 0;
}

int get_base()
{
    int b;
    cout << "Enter the value of base (2, 8, 10, 16): ";
    cin >> b;
    return b;
}

int digit_length(string digit)
{
    int length = 0;
    for (int i = 0; digit[i] != '\0'; i++)
    {
        length = length + 1;
    }
    return length;
}

int binary_to_decimal(string digit, int length)
{
    int decimal = 0;
    int base = 1;
    for (int i = length - 1; i >= 0; i--)
    {
        if (digit[i] == '1')
        {
            decimal = decimal + base;
        }
        base = base * 2;
    }
    return decimal;
}

int octal_to_decimal(string digit, int length)
{
    int decimal = 0;
    int base = 1;
    for (int i = length - 1; i >= 0; i--)
    {
        int n = digit[i] - '0';
        decimal = decimal + n * base;
        base = base * 8;
    }
    return decimal;
}

int hexa_to_decimal(string digit, int length)
{
    int decimal = 0;
    int base = 1;
    for (int i = length - 1; i >= 0; i--)
    {
        int value = 0;

        if (digit[i] == '0') value = 0;
        else if (digit[i] == '1') value = 1;
        else if (digit[i] == '2') value = 2;
        else if (digit[i] == '3') value = 3;
        else if (digit[i] == '4') value = 4;
        else if (digit[i] == '5') value = 5;
        else if (digit[i] == '6') value = 6;
        else if (digit[i] == '7') value = 7;
        else if (digit[i] == '8') value = 8;
        else if (digit[i] == '9') value = 9;
        else if (digit[i] == 'A' || digit[i] == 'a') value = 10;
        else if (digit[i] == 'B' || digit[i] == 'b') value = 11;
        else if (digit[i] == 'C' || digit[i] == 'c') value = 12;
        else if (digit[i] == 'D' || digit[i] == 'd') value = 13;
        else if (digit[i] == 'E' || digit[i] == 'e') value = 14;
        else if (digit[i] == 'F' || digit[i] == 'f') value = 15;

        decimal = decimal + value * base;
        base = base * 16;
    }
    return decimal;
}

int decimal_string_to_decimal(string digit, int length)
{
    int decimal = 0;
    int base = 1;
    for (int i = length - 1; i >= 0; i--)
    {
        int n = digit[i] - '0';
        decimal = decimal + n * base;
        base = base * 10;
    }
    return decimal;
}

string decimal_to_binary(int decimal) {
    if (decimal == 0) return "0";

    string binary = "";
    while (decimal > 0) {
        char binary_digit = (decimal % 2) + '0';
        binary = binary_digit + binary;
        decimal = decimal / 2;
    }
    return binary;
}

string decimal_to_octal(int decimal) {
    if (decimal == 0) return "0";

    string octal = "";
    while (decimal > 0) {
        char octal_digit = (decimal % 8) + '0';
        octal = octal_digit + octal;
        decimal = decimal / 8;
    }
    return octal;
}

string decimal_to_hexa(int decimal) {
    if (decimal == 0)
        return "0";

    string hexa = "";
    while (decimal > 0) {
        int rem = decimal % 16;
        char hexa_digit;
        if (rem < 10) {
            hexa_digit = rem + '0';
        } else {
            hexa_digit = rem - 10 + 'A';
        }
        hexa = hexa_digit + hexa;
        decimal = decimal / 16;
    }
    return hexa;
}

string encrypt_message(string message, int base)
{
    string encrypted = "";
    for (int i = 0; message[i] != '\0'; i++)
    {
        int ascii_value = message[i];
        string converted = "";

        if (base == 2)
        {
            converted = decimal_to_binary(ascii_value);
            while (converted.length() < 8)
            {
                converted = '0' + converted;
            }
        }
        else if (base == 8)
        {
            converted = decimal_to_octal(ascii_value);
        }
        else if (base == 10)
        {
            converted = to_string(ascii_value);
        }
        else if (base == 16)
        {
            converted = decimal_to_hexa(ascii_value);
        }
        else
        {
            return "Invalid base! Use 2, 8, 10, or 16.";
        }

        encrypted = encrypted + converted + " ";
    }
    return encrypted;
}

string decrypt_message(string encrypted, int base)
{
    string decrypted = "";
    string value = "";

    for (int i = 0; i <= encrypted.length(); i++)
    {
        if (i == encrypted.length() || encrypted[i] == ' ')
        {
            if (value.length() > 0)
            {
                int decimal_value = 0;

                if (base == 2)
                {
                    decimal_value = binary_to_decimal(value, value.length());
                }
                else if (base == 8)
                {
                    decimal_value = octal_to_decimal(value, value.length());
                }
                else if (base == 10)
                {
                    decimal_value = stoi(value);
                }
                else if (base == 16)
                {
                    decimal_value = hexa_to_decimal(value, value.length());
                }
                else
                {
                    return "Invalid base! Use 2, 8, 10, or 16.";
                }

                decrypted = decrypted + char(decimal_value);
                value = "";
            }
        }
        else
        {
            value = value + encrypted[i];
        }
    }
    return decrypted;
}
