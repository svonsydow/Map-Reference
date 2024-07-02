#include <bits/stdc++.h>
#include <map>

using namespace std;

//Map to store the word and its frequency.
map<string,int> frequency;

//Pair to store a word and its frequency.
struct keyValuePair
{
    string word;
    int frequency;
};


int main()
{

//Use the ifstream to access the text file and open it.
    ifstream file;
    file.open ("\\Users\\sanda\\Desktop\\TestText.txt"); //make sure full path to file is used.

//Create the variable to hold the words from the text document.
    string word;

//Set 0 to a variable called numWords
    int numWords = 0;

//Use a while-loop to store all the words into the map.
    while (file >> word)
    {

//Remove punctuation marks. Punctuation marks are read as part of the word, so leaving them in
//skews results.
        word.erase(std::remove(word.begin(), word.end(), ','), word.end());
        word.erase(std::remove(word.begin(), word.end(), '.'), word.end());
        word.erase(std::remove(word.begin(), word.end(), '!'), word.end());
        word.erase(std::remove(word.begin(), word.end(), '?'), word.end());
        word.erase(std::remove(word.begin(), word.end(), ';'), word.end());
        word.erase(std::remove(word.begin(), word.end(), ':'), word.end());

//For each iteration of a word, increase its frequency by 1.
        if (frequency.find(word) != frequency.end())
        {
            frequency[word] = frequency[word] +1;
        }

        else
        {
//Else, set frequency to 1.
            frequency[word]=1;
            numWords++;
        }
    }

//Copy all the words and frequency pairs into an array.
    keyValuePair* wordsArray= new keyValuePair[numWords];

//Define a map iterator.
    map<string, int>::iterator iter;

    int i=0;
    for (iter = frequency.begin(); iter != frequency.end(); iter++ )
    {
        wordsArray[i].word = iter->first;
        wordsArray[i].frequency = iter->second;
        i++;
    }

//Sorting the array in descending order from most frequent to least frequent
    sort(wordsArray, wordsArray+numWords, [](keyValuePair const &more, keyValuePair const &less)
    { return more.frequency > less.frequency; });

//Formatting
    cout << setw(25) << "Word" << setw(15) << "\tFrequency" << endl;
    cout <<"\t" <<
    cout.fill('-');
    cout.width(45);
    cout << " " << endl;

//Using a for loop to print the words and their frequency from the array.
    for(int i=0;i<numWords;i++)
    {
        cout << setfill(' ') << setw(25)<<wordsArray[i].word << setw(15) << wordsArray[i].frequency<< endl;

    }
    return 0;
}