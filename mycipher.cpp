#include <iostream> //importing my library
#include <string> //importing string library
using namespace std; //allows me to use my library
string Encrypt(string phrase, int shift) //creating and defining my Encrypt function
{
    string result = ""; //creating string variable called result
    for(char s : phrase) //loop that goes through each character in my text phrase
    {
        if(isupper(s)) //checks for uppercase letters
        {
            result += char(int(s + shift - 'A') % 26 + 'A'); //shifts any uppercase characters and sets that as the result
        }
        else if(islower(s)) //checks for lowercase letters
        {
            result += char(int(s + shift - 'a') % 26 + 'a'); //shifts any lowercase characters and sets that as the result
        }
        else //if there's no letters to check
        {
            result += s; //keeps characters unchanged
        }
    }
    return result; //returns my encrypted phrase
}
int main() //function compiler for my program
{
    string phrase; //creating string variable phrase
    int shift; //creating int variable shift
    cout << "Enter phrase: " << endl; //asks user to enter text
    getline(cin, phrase); //takes the user input for phrase
    cout << "Enter shift: " << endl; //asks user to enter shift value
    cin >> shift; //takes the user input for shift
    string encrypted = Encrypt(phrase, shift); //calling my encrypt function
    cout << "Encrypted phrase: " << encrypted << endl; //prints my encrypted phrase
    return 0; //ends function
}