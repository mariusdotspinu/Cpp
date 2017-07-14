//
// Created by Marius on 7/6/2017.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <deque>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

bool IsEmpty(const char *word) {
    if (strlen(word) == 0) {
        return true;
    }
    return false;
}

bool HasFirstLetterVowel(const char *word) {
    if (word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U' ||
        word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') {
        return true;
    }

    return false;
}

int VowelsCount(const char *word) {
    int count = 0;

    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') {
            count++;
        }
    }

    return count;
}

void PrintVector(const vector<const char *> container) {

    for (vector<const char *>::const_iterator it = container.begin(); it != container.end(); it++) {
        cout << *it << "\t";
    }

    cout << endl;
}

const char *GetLongestWord(const vector<const char *> container) {
    int max = 0;
    const char *result = "";

    for (vector<const char *>::const_iterator it = container.begin(); it != container.end(); ++it) {
        if (strlen(*it) > max) {
            max = strlen(*it);
            result = *it;
        }
    }

    return result;
}

void FillVector(vector<const char *> &container, const char *fileName) {
    FILE *fp = fopen(fileName, "r");

    char line[1000];

    char wordElement[2];
    char *word = new char[100];
    if (fp != NULL) {

        while (fgets(line, sizeof(line), fp) != NULL) {
            strcpy(word, "");

            for (int i = 0; i < strlen(line); i++) {

                if ((line[i] == ' ' || line[i] == '\n') && !IsEmpty(word)) {
                    container.push_back(word);
                    word = new char[100];
                    strcpy(word, "");

                } else {
                    wordElement[0] = line[i];
                    wordElement[1] = '\0';
                    strcat(word, wordElement);
                }
            }
        }

        if (feof(fp)) {
            cout << "Reached end of file !" << endl;
        }
    } else {
        perror("Error reading from file !");
    }

    delete[] word;
    fclose(fp);
}

int MoreThanFourVowelsCount(const vector<const char *> container) {
    int wordCount = 0;

    for (unsigned int i = 0; i < container.size(); i++) {
        if (VowelsCount(container.at(i)) > 4) {
            wordCount++;
        }
    }

    return wordCount;
}

void RemoveIfLengthBiggerThan(vector<const char *> &container, int length) {
    for (unsigned int i = 0; i < container.size(); i++) {
        if (strlen(container.at(i)) > length) {
            container.erase(remove(container.begin(), container.end(), container.at(i)), container.end());
            i--;
        }
    }
}

deque<const char *> NoFirsLetterVowel(const vector<const char *> container) {
    deque<const char *> deq;

    for (unsigned int i = 0; i < container.size(); i++) {
        if (!HasFirstLetterVowel(container.at(i))) {
            deq.push_back(container.at(i));
        }
    }

    return deq;
}

priority_queue<const char*> GetSortedWords(const vector<const char*> container){
    priority_queue<const char*, vector<const char*>, less<const char*> > mQueue;

    for(unsigned int i = 0 ; i < container.size(); i++){
        mQueue.push(container.at(i));
    }
    return mQueue;
}

stack<const char*> ReverseWords(const vector<const char*> container){
    stack<const char*> mStack;

    for(unsigned int i = 0 ; i < container.size(); i++){
        mStack.push(container.at(i));
    }

    return mStack;
}

int main() {

    vector<const char *> mContainer;
    deque<const char *> deq;
    priority_queue<const char*, vector<const char*>, less<const char*> > mQueue;
    stack<const char*> mStack;

    FillVector(mContainer, "C:\\Users\\Marius\\Desktop\\CTraining\\OOP\\stl1.txt");

    PrintVector(mContainer);
    cout << mContainer.size() << endl;

    cout << GetLongestWord(mContainer) << endl;

    cout << MoreThanFourVowelsCount(mContainer) << endl;

    deq = NoFirsLetterVowel(mContainer);

    for (unsigned int i = 0; i < deq.size(); i++) {
        cout << deq.at(i) << "\t";
    }

    cout << endl;

    RemoveIfLengthBiggerThan(mContainer, 4);
    PrintVector(mContainer);

    mQueue = GetSortedWords(mContainer);

    while(!mQueue.empty()){
        cout << mQueue.top() << "\t";
        mQueue.pop();
    }

    cout << endl;

    mStack = ReverseWords(mContainer);

    while(!mStack.empty()){
        cout << mStack.top() << "\t";
        mStack.pop();
    }

    cout << endl;
}