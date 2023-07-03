#include <iostream>
#include <iomanip>

using namespace std;

void IfQuestions()
{
    short int A = 5, B = -8, C = 18, D = 0;

    cout << "Question 1: " << boolalpha << (A > B) << std::endl;
    cout << "Question 2: " << boolalpha << (B <= 0) << std::endl;
    cout << "Question 3: " << boolalpha << (D != 0) << std::endl;
    cout << "Question 4: " << boolalpha << (C == 17) << std::endl;

    C = 18; // In case this was a typo in the assignment doc
    
    cout << "Question 5: " << boolalpha << (A > B && C > D) << std::endl;
    cout << "Question 6: " << boolalpha << (C != (B + 28)) << std::endl;
    cout << "Question 7: " << boolalpha << (D >= C || A == B) << std::endl;
    cout << "Question 8: " << boolalpha << ((C + 1) == (D + 19)) << std::endl;
    cout << "Question 9: " << boolalpha << (B == 0 || C == 0 || D == 0) << std::endl;
    cout << "Question 10: " << boolalpha << (A == 0 && (B > 1 || C > 1)) << std::endl;
    cout << "Question 11: " << boolalpha << (!(A == 5) || !(C = 0)) << std::endl;

    C = 18; // In case this was a typo in the assignment doc

    cout << "Question 12: " << boolalpha << (A > (B + C) && A < (D + B)) << std::endl;
}

void Question13()
{
    float A = 20.5, B = -20.4;
    if (A > (B + 40))
        cout << "Yes";
    else
        cout << "No";
}

void Question14()
{
    float Yoga = 2.5;
    Yoga++; Yoga++;
    if (!(Yoga < 5))
        Yoga--;
    else
        Yoga++;
    cout << Yoga;
}

void Question15()
{
    bool Hungry = true;
    bool Thirsty = false;
    if (Hungry || Thirsty)
    {
        cout << "I'm not happy";
    }
    else
    {
        cout << "I'm very happy";
    }
}

void Question16()
{
    cout << "1";
    int H = -50;
    if (H < (H + 1))
        cout << "2";
    else
        cout << "3";
}

void Question17()
{
    short int X = 15, Y = 18;
    if (X > 9 && Y < 18)
        cout << "passion";
    else
        cout << "papaya";
}

void DonutEater()
{
    short totalDonuts = 0;
    cout << "How many donuts do you want to eat, little piggy? ";
    cin >> totalDonuts;

    short dozenDonuts = 0;
    short singleDonuts = 0;

    dozenDonuts = totalDonuts / 12;
    singleDonuts = totalDonuts % 12;

    cout << "This is " << dozenDonuts << " dozen plus " << singleDonuts << " single donut" << (singleDonuts == 1 ? "" : "s") << endl;

    if (0 == totalDonuts)
    {
        cout << "C'mon, just one donut?" << endl;
    }
    else if (totalDonuts >= 1 && totalDonuts <= 2)
    {
        cout << "That's a rather whimpy amount of donuts." << endl;
    }
    else if (totalDonuts >= 3 && totalDonuts <= 6)
    {
        cout << "Now you're just getting started! What else for breakfast?" << endl;
    }
    else if (totalDonuts >= 7 && totalDonuts <= 9)
    {
        cout << "Just make sure you leave some room for a cinnamon roll!" << endl;
    }
    else if (totalDonuts >= 10 && totalDonuts <= 12)
    {
        cout << "Sure you don't want to try for a baker's dozen?" << endl;
    }
    else if (totalDonuts > 12)
    {
        cout << "Uh, you might want to be checked for diabeetus." << endl;
    }
}

int main()
{
    IfQuestions();

    cout << endl;
    cout << "Question 13: ";
    Question13();

    cout << endl;
    cout << "Question 14: ";
    Question14();

    cout << endl;
    cout << "Question 15: ";
    Question15();

    cout << endl;
    cout << "Question 16: ";
    Question16();

    cout << endl;
    cout << "Question 17: ";
    Question17();

    cout << endl << endl;
    DonutEater();
}
