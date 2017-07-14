//
// Created by Marius on 7/10/2017.
//

#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct InsensitiveCompare {
    bool operator()(const string s1, const string s2) {
        return stricmp(s1.c_str(), s2.c_str()) < 0;
    }
};

bool IsSentenceCorrect(const char *sentence) {
    char last = sentence[strlen(sentence) - 1];
    if (last == '.' || last == '?' || last == '!') {
        for (int i = 0; i < strlen(sentence) - 2; i++) {
            if (sentence[i] != ' ' && sentence[i] != ',' && sentence[i] != '-' && !isalnum(sentence[i])) {
                return false;
            }
            if (sentence[i] == ' ' || sentence[i] == ',') {
                if (sentence[i + 1] == '-' || sentence[i - 1] == '-') {
                    return false;
                }
            }
            if (sentence[i] == '-' && sentence[i + 1] == '-') {
                return false;
            }
        }
        return true;
    }

    return false;
}

bool IsTextCorrect(const char *fileName) {
    FILE *fp = fopen(fileName, "r");
    char line[1000];
    char sentence[1000];
    char current[2];
    bool currentSentence;

    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp) != NULL) {
            strcpy(sentence, "");
            for (int i = 0; i < strlen(line) - 1; i++) {

                if (line[i] == '\n' ||
                    (!isalnum(line[i - 1]) && line[i] == ' ' && line[i - 1] != ',')) {//upper case letter

                    currentSentence = IsSentenceCorrect(sentence);
                    strcpy(sentence, "");
                    if (!currentSentence) {
                        return false;
                    }
                } else {
                    current[0] = line[i];
                    current[1] = '\0';
                    strcat(sentence, current);
                }
            }
        }

    }

    fclose(fp);

    return true;
}

vector<string> GetSentences(const char *fileName) {
    vector<string> sentences;

    FILE *fp = fopen(fileName, "r");
    char line[1000];
    char sentence[1000];
    char current[2];

    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp) != NULL) {
            strcpy(sentence, "");
            for (int i = 0; i < strlen(line); i++) {
                if (line[i] == '\n' ||
                    (!isalnum(line[i - 1]) && line[i] == ' ' && line[i - 1] != ',') ||
                    i == strlen(line) - 1) {//upper case letter

                    if (i == strlen(line) - 1) {
                        current[0] = line[i];
                        current[1] = '\0';
                        strcat(sentence, current);
                    }
                    sentences.push_back(sentence);
                    strcpy(sentence, "");

                } else {
                    current[0] = line[i];
                    current[1] = '\0';
                    strcat(sentence, current);
                }
            }
        }

    }

    fclose(fp);

    return sentences;
}

map<string, int> GetWordsAndCount(const vector<string> container) {
    map<string, int> mMap;
    map<string, int>::iterator it;

    char word[100], current[2];

    for (unsigned int i = 0; i < container.size(); i++) {
        strcpy(word, "");

        for (int j = 0; j < container.at(i).length(); j++) {
            if (container.at(i)[j] == ' ' || container.at(i)[j] == ',' || container.at(i)[j] == '.' ||
                container.at(i)[j] == '?' || container.at(i)[j] == '!') {
                it = mMap.find(word);
                if (it == mMap.end()) {
                    mMap[word] = 1;
                } else {
                    mMap[word] = it->second + 1;
                }
                strcpy(word, "");
            } else {
                current[0] = container.at(i)[j];
                current[1] = '\0';

                strcat(word, current);
            }
        }
    }

    return mMap;
}

set<string, InsensitiveCompare> SortWords(const vector<string> container) {

    set<string, InsensitiveCompare> words;
    char word[100], current[2];
    for (unsigned int i = 0; i < container.size(); i++) {
        strcpy(word, "");
        for (int j = 0; j < container.at(i).length(); j++) {
            if (container.at(i)[j] == ' ' || container.at(i)[j] == ',' || container.at(i)[j] == '.' ||
                container.at(i)[j] == '?' || container.at(i)[j] == '!') {
                words.insert(word);
                strcpy(word, "");
            } else {
                current[0] = container.at(i)[j];
                current[1] = '\0';
                strcat(word, current);
            }
        }
    }

    return words;
}

int main() {

    vector<string> sentences = GetSentences("C:\\Users\\Marius\\Desktop\\CTraining\\OOP\\stl2.txt");
    map<string, int> wordsAndCount = GetWordsAndCount(sentences);
    set<string, InsensitiveCompare> words = SortWords(sentences);
    cout << IsSentenceCorrect("Home sweet home!") << endl;
    cout << IsTextCorrect("C:\\Users\\Marius\\Desktop\\CTraining\\OOP\\stl2.txt");

    cout << endl;
    for (unsigned int i = 0; i < sentences.size(); i++) {
        cout << sentences.at(i) << endl;
    }

    for (map<string, int>::iterator it = wordsAndCount.begin(); it != wordsAndCount.end(); it++) {
        cout << "word : " << it->first << endl << " count : " << it->second;
        cout << endl;
    }

    for (set<string>::iterator it = words.begin(); it != words.end(); it++) {
        cout << *it << "\t";

    }
    cout << endl;

    return 0;
}