


//===================================================================================
// Anish Banswada
//September 2022 
// Caesar Cipher
// This program decrypts cipher text using a given key to undo a shift cipher. The 
//program reads the ciphertext through stdin and the key through a command-line 
//argument and prints the result.
//===================================================================================
#include <iostream>
#include <string>
using namespace std;
string decipher(string message, int key); // declaration of the decode function
//=============================================
// MAIN
//=============================================
int main(int argc, char *argv[])
{
    int key; 
    if ( argc > 1 ) 
        key = atoi(argv[1]); // argument specified 
    else 
        key = 3;     // default if no argument 
    
    string message, temp; 
    while ( getline(cin,temp)) // reads text line by line from file 
    {
     message = message + temp; // copies text into a string variable
     message = message + "\n";
    }
    
    string plain_text = decipher(message, key);
    cout << plain_text << endl; //prints deciphered text
    return 0;
    
}
//==================================
// decipher
// This function deciphers the given shift ciphered text using the given key
// Parameters:
// - message: a string containing the ciphertext.
// - key: an integer specifying the key i.e the number of alphbets to be shifted
// Return:
// - text: a string containing the message deciphered using key
//======================================
string decipher(string message, int key)
{
    string text;
    for (int i = 0; i < message.length(); i++) //loops through every character
    
    {
        if ((int(message[i]) >= 65 && int(message[i]) <= 90) || (int(message[i]) >=
97 && int(message[i]) <= 122)) //checks if the current character is an 
alphabet irrespective of case
            {
                int l = int(message[i]) - key;
                if (isupper(message[i])) //checks if character is uppercase
                    l = l + 32; //adds 32 to change ascii number to 
represent lowercase
                if (l < 97)
                {
                    l = 122 - (96-l); // changes ascii number by given 
key to find original character
                }
                text = text + char(l);
            }
            
        
        else 
         text = text + message[i];       //preserves non-alphabetical characters
as is
    }
    return text;
}    for (int i = 0; i < message.length(); i++) //loops through every character
    
    {
        if ((int(message[i]) >= 65 && int(message[i]) <= 90) || (int(message[i]) >=
97 && int(message[i]) <= 122)) //checks if the current character is an 
alphabet irrespective of case
            {
                int l = int(message[i]) - key;
                if (isupper(message[i])) //checks if character is uppercase
                    l = l + 32; //adds 32 to change ascii number to 
represent lowercase
                if (l < 97)
                {
                    l = 122 - (96-l); // changes ascii number by given 
key to find original character
                }
                text = text + char(l);
            }
            
        
        else 
         text = text + message[i];       //preserves non-alphabetical characters
as is
    }
    return text;
}
