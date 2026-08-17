#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence;
    
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string word = "";
    string longest = "";

    for (int i = 0; i <= sentence.length(); i++)
    {
        if (sentence[i] != ' ' && sentence[i] != '\0')
        {
            word = word + sentence[i];
        }
        else
        {
            if (word.length() > longest.length())
            {
                longest = word;
            }

            word = "";
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Number of letters: " << longest.length() << endl;

    return 0;
}