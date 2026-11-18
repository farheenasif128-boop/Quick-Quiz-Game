#include <iostream>
#include <fstream>
using namespace std;

enum Menu
{
    START = 1,
    EXIT = 2
};

struct Question
{
    string question;
    string option1;
    string option2;
    string option3;
    string option4;
    int correctAnswer;
};

void showMenu();
void startQuiz();

int main()
{
    showMenu();
    return 0;
}

void showMenu()
{
    int choice;

    cout << "=============================\n";
    cout << "       QUIZ GAME\n";
    cout << "=============================\n";
    cout << "1. Start Quiz\n";
    cout << "2. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case START:
            startQuiz();
            showMenu(); 
            break;

        case EXIT:
            cout << "\nThank You for using Quiz Game!\n";
            break;

        default:
            cout << "\nInvalid Choice! Try Again.\n\n";
            showMenu(); 
    }
}

void startQuiz()
{
    string name;
    int score = 0;
    int answer;

    cout << "\nEnter Your Name: ";
    cin >> name;
    Question q[5];

    q[0].question = "1. What is the extension of C++ file?";
    q[0].option1 = "1) .py";
    q[0].option2 = "2) .cpp";
    q[0].option3 = "3) .html";
    q[0].option4 = "4) .java";
    q[0].correctAnswer = 2;
    
    q[1].question = "2. Which symbol is used for comments in C++?";
    q[1].option1 = "1) //";
    q[1].option2 = "2) ##";
    q[1].option3 = "3) **";
    q[1].option4 = "4) &&";
    q[1].correctAnswer = 1;

    q[2].question = "3. Which function is used to display output?";
    q[2].option1 = "1) cin";
    q[2].option2 = "2) print";
    q[2].option3 = "3) cout";
    q[2].option4 = "4) input";
    q[2].correctAnswer = 3;

    q[3].question = "4. Which loop repeats code multiple times?";
    q[3].option1 = "1) if";
    q[3].option2 = "2) loop";
    q[3].option3 = "3) for";
    q[3].option4 = "4) switch";
    q[3].correctAnswer = 3;

    q[4].question = "5. C++ is a?";
    q[4].option1 = "1) Programming Language";
    q[4].option2 = "2) Game";
    q[4].option3 = "3) Browser";
    q[4].option4 = "4) Software";
    q[4].correctAnswer = 1;

    for(int i = 0; i < 5; i++)
    {
        cout << "\n" << q[i].question << endl;
        cout << q[i].option1 << endl;
        cout << q[i].option2 << endl;
        cout << q[i].option3 << endl;
        cout << q[i].option4 << endl;

        cout << "Enter Your Answer: ";
        cin >> answer;

        if(answer == q[i].correctAnswer)
        {
            cout << "Correct Answer!\n";
            score++;
        }
        else
        {
            cout << "Wrong Answer!\n";
        }
    }

    cout << "\n=====================\n";
    cout << "Quiz Finished!\n";
    cout << "Your Score: " << score << "/5\n";
    cout << "=====================\n";

    ofstream file("score.txt", ios::app);

    if(file.is_open())
    {
        file << "Name: " << name << " Score: " << score << "/5" << endl;
        file.close();

        cout << "Score Saved in File Successfully!\n";
    }
    else
    {
        cout << "File Error!\n";
    }
}