#include <iostream>
#include <ctime>
using namespace std;

int main() {
    // List of multiple test sentences
  const string tests[] = {
    "The quick brown fox jumps over the lazy dog.",
    "Typing fast requires a lot of focus and practice.",
    "C plus plus is a powerful programming language.",
    "I love learning new things every single day.",
    "Practice makes a person perfect in everything.",
    "Artificial intelligence is changing the world.",
    "Always comment your code to help others read it.",
    "Debugging teaches patience and attention to detail.",
    "Success comes to those who work hard and never quit.",
    "A computer does what you tell it to do, not what you want.",
    "Do not stop until you are proud of what you have achieved.",
    "Reading books improves knowledge and imagination.",
    "Keyboard shortcuts can save a lot of time while typing.",
    "Good habits are built by repeating small things daily.",
    "Believe in yourself because you are capable of more."
};

int totalTests = 15;

    // Generate random index
    srand(time(0));
    int randomIndex = rand() % totalTests;

    // Pick random test string
    string testText = tests[randomIndex];
    string userInput;

    cout << "===== Typing Speed Test =====\n\n";
    cout << "Type the sentence below and press Enter:\n\n";
    cout << testText << "\n\n";

    cout << "Press Enter to start...";
    cin.ignore();

    cout << "\nStart typing now:\n";

    // Start timer
    clock_t start = clock();

    getline(cin, userInput);

    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    int typedLength = userInput.length();
    int promptLength = testText.length();
    int correct = 0;

    int limit = (typedLength < promptLength) ? typedLength : promptLength;
    for (int i = 0; i < limit; i++) {
        if (userInput[i] == testText[i])
            correct++;
    }

    int errors = typedLength - correct;
    if (errors < 0) errors = 0;

    double minutes = timeTaken / 60.0;

    double grossWPM = (typedLength / 5.0) / minutes;
    if (grossWPM < 0) grossWPM = 0;

    double netWPM = ((typedLength - errors) / 5.0) / minutes;
    if (netWPM < 0) netWPM = 0;

    double accuracy = 0;
    if (typedLength > 0)
        accuracy = (correct * 100.0) / typedLength;

    cout << "\n==== RESULT ====\n";
    cout << "Sentence Selected: " << randomIndex + 1 << "\n";
    cout << "Time Taken: " << timeTaken << " seconds\n";
    cout << "Gross WPM: " << grossWPM << "\n";
    cout << "Net WPM: " << netWPM << "\n";
    cout << "Accuracy: " << accuracy << "%\n";

    return 0;
}

