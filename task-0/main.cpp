#include "FileReader.h"
#include "Parser.h"
#include "Statistic.h"
#include "Writer.h"

#include <string>
#include <list>


using namespace std;
const vector<string> CSV_WORD = {"word", "Frequency", "PercentFrequency"};

int main(int argc, char** document) {

    if (argc != 3) {
        exit(1);
    }

    bool sens;
    cout << "Case sensitive? (0/1)";
    cin >> sens;
    
    //считывание
    FileReader fileReader(document[1]);
    Parser parser;
    Statistic statistic;
    fileReader.open();


    while (fileReader.isNext()) {
        //берём и парсим построчно
        string nextString = fileReader.getNext();
        vector<string> words = parser.parse(nextString, sens);

        for (int j = 0; j < words.size(); j++) {
            string const& word = words[j];
            statistic.add(word);
        }
    }

    //запись
    Writer writer(document[2]);
    writer.open();

    //получаем отсортированный список и количество слов
    int wordsAmount = statistic.getAmountOfWords();
    vector<pair<string, int>> sortedList = statistic.sort();

    writer.write(CSV_WORD, ';');

    //выводим отсортированный список
    for (int k = 0; k < sortedList.size(); k++) {
        const pair<string, int>& wordInf = sortedList[k];

        string word = wordInf.first;
        int Frequency = wordInf.second;
        double PercentFrequency = (double)wordInf.second / wordsAmount * 100;

        vector<string> allWordsInfo = {word, to_string(Frequency), to_string(PercentFrequency)};
        writer.write(allWordsInfo, ';');
    }

    fileReader.close();
    writer.close();

    return 0;
}
