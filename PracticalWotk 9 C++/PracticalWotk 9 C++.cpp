#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file\n";
        return 1;
    }

    map<string, int> word_count;

    string word;
    while (file >> word)
    {
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());

        transform(word.begin(), word.end(), word.begin(), tolower);

        ++word_count[word];
    }

    // Сортировка
    multimap<int, string, greater<int>> count_word;
    for (const auto& pair : word_count)
    {
        count_word.emplace(pair.second, pair.first);
    }

    // Вывод слов после сортировки
    for (const auto& pair : count_word)
    {
        cout << pair.second << ": " << pair.first << '\n';
    }

    return 0;
}