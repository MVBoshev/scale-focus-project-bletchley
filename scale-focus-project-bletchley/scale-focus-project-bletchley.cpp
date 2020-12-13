#include <iostream>
#include <time.h>   
using namespace std;

int randomInt() {
    return rand() % (7 - 0 + 1) + 0;
}

int checkForSameNumberAndPosition(int* code, int* userGuess) {
    int count = 0;

    for (int i = 0; i < 4; i++) {
        if (code[i] == userGuess[i]) {
            count++;
            userGuess[i] = userGuess[i] * (-1);
        }
    }

    return count;
}

int checkOnlyForSameNumbers(int* code, int* userGuess) {
    int count = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (code[i] == userGuess[j] and i != j and code[i] != abs(userGuess[i])) {
                count++;
                userGuess[j] = userGuess[j] * (-1);
                break;
            }
        }
    }

    return count;
}

void outputResult(int* code, int* userGuess) {
    cout << "The count of guessed numbers which are at the same position as in the code is: " << checkForSameNumberAndPosition(code, userGuess) << endl;
    cout << "The count of guessed numbers which are not at the same position as in the code is: " << checkOnlyForSameNumbers(code, userGuess) << endl;
}

int main() {
    srand(time(NULL));

    int code[4] = { 0,7,7,7 };
    int userGuess[4] = { 7,4,2,4 };

    outputResult(code, userGuess);
    
    for (int i = 0; i < 4; i++)
        cout << code[i] << " ";
    cout << endl;
  

    for (int i = 0; i < 4; i++)
        cout << userGuess[i] << " ";
    cout << endl;
}
