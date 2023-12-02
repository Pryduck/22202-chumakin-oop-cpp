#include "FileReader.h"
#include "Parser.h"
#include "Statistic.h"
#include "Writer.h"

#include <string>
#include <list>

using std::string;

const std::vector<string> CSV_WORD = {"word", "Frequency", "Percent_Frequency"};

int main(int argc, char** document) {

    if (argc != 3) {
        exit(1);
    }

    //считывание
    FileReader file_reader(document[1]);
    Parser parser;
    Statistic statistic;
    file_reader.open();


    while (file_reader.is_next()) {
        //берём и парсим построчно
        string next_string = file_reader.get_next();
        vector<string> words = parser.parsing(next_string);

        for (int j = 0; j < words.size(); j++) {
            string const& word = words[j];
            statistic.adding(word);
        }
    }

    //запись
    Writer writer(document[2]);
    writer.open();

    //получаем отсортированный список и количество слов
    int words_number = statistic.get_number();
    vector<std::pair<string, int>> sorted_list = statistic.sorting();

    writer.writing(CSV_WORD, ',');

    //выводим отсортированный список
    for (int k = 0; k < sorted_list.size(); k++) {
        const pair<string, int>& word_inf = sorted_list[k];

        string word = word_inf.first;
        int Frequency = word_inf.second;
        double Percent_Frequency = (double)word_inf.second / words_number * 100;

        vector<string> all_words_info = {word, to_string(Frequency), to_string(Percent_Frequency)};
        writer.writing(all_words_info, ',');
    }

    file_reader.close();
    writer.close();

    return 0;
}