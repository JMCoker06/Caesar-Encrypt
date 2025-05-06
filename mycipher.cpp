#include <iostream> //importing my library
#include <string> //importing string library
using namespace std; //allows me to use my library
string Input(const string& input) //creating and defining my Input function
{
    string result = ""; //creating string variable called result
    for(char s : input) //loop that goes through each character in my input
    {
        if(isalpha(s)) //condition for checking if the character is an actual letter
        {
            result += toupper(s); //makes the letter uppercase
        }
    }
    return result; //returns my new result after capitalizing each letter
}
string Encrypt(const string& phrase, int shift) //creating and defining my Encrypt function
{
    string result = ""; //creating string variable called result
    for(char s : phrase) //loop that goes through each character in my text phrase
    {
        result += char((s -'A' + shift) % 26 + 'A'); //shifts any uppercase characters and sets that as the result
    }
    return result; //returns my encrypted phrase
}
void Output(const string& encrypted) 
{
  int count = 0; //creating count variable
  for(char s : encrypted) //checks each letter in my encrypted phrase
  {
    cout << s; //printing each letter
    count++; //increasing count
    if(count % 5 == 0) //condition checking if the block has reached 5 letters
    {
        cout << " "; //creates space after every 5 letters
    }
    if(count % 50 == 0) //condition checking if the line has reached 10 blocks or 50 characters
    {
        cout << endl; //creates new line after 10 blocks
    }
  }
  if(count % 50 != 0) //allows a block to be added that isn't 5 letters
  {
    cout << endl; //creates last newline if necessary  
  }
}
int main() //function compiler for my program
{
    string phrase; //creating string variable phrase
    int shift; //creating int variable shift
    cout << "Enter phrase: " << endl; //asks user to enter text
    getline(cin, phrase); //takes the user input for phrase
    cout << "Enter shift: " << endl; //asks user to enter shift value
    cin >> shift; //takes the user input for shift
    shift = (shift % 26 + 26) % 26; //keeps shift within range
    string newInput = Input(phrase); //calling my Input function
    string encrypted = Encrypt(newInput, shift); //calling my encrypt function
    Output(encrypted); //prints my encrypted phrase
    return 0; //ends function
}