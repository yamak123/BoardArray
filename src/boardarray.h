#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            int pos = -1;

            for(int i=0; i < index; i++) {
                Entry existing = array[i];
                if(entry->compare(&existing)) {
                    pos = i;
                    break;
                }
            }

            if(pos == -1) {
                if(index < SIZE) {
                    array[index++] = *entry;
                } else {
                    cout << entry->name << "'s score is too low to be added!" << endl;
                }
                return;
            }

            for(int i=index; i > pos; i--) {
                array[i] = array[i - 1];
            }
            array[pos] = *entry;
            if(index < SIZE) index++;
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};