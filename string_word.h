#include <vector>
#include <string>
using namespace std;
class Army {
    private: 
        vector<string> names;
    public:
        void addClass(string name) {
            this->names.push_back(name);
        }
        void removeClass() {
            this->names.pop_back();
        }
        string getName() {
                string name;
            for (auto i = this->names.begin();
                    i != this->names.end(); i++) {  // Vector new line
                //cout << (*i) << endl;   // Vector change
                name = *i;
                return name;
            }
                return name;
        }
};

char string_word_getFirstLetter(string name);
