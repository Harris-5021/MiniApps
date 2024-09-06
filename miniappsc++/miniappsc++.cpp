#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std;


int main()
{
    bool running = true;
    int option = 0;
    while (running) {
        cout << "P4CS MINI APPLICATIONS" << endl;
        cout << "----------------------" << endl;
        cout << "Please select an option:" << endl;
        cout << "1) keep counting game" << endl;
        cout << "2) Square root calculator" << endl;
        cout << "3) Check digit generator" << endl;
        cout << "4) Check digit checker" << endl;
        cout << "9) Quit" << endl;

        cout << "please enter an option" << endl;
        cin >> option;

        switch (option) {
        case 1: {
            int i = 0; //tracking number of questions
            int j = 0; //random number 
            int RealAnsMinus = 0; //if minus operator is used
            int OneTimeInt = 0; //int that will only be used once
            int UserAns = 0; //User answer
            int RealAns = 0; //real answer
            int Score = 0; //score
            int PrevInt = 0; //previous int

            cout << "Keep Counting" << endl;
            cout << "------------" << endl;
            cout << "You will be presented with 10 addition questions" << endl;
            cout << "After the first question, the left - hand operand is the result of the previous addition." << endl;
            cout << " Press enter to start." << endl;

            cin.ignore(); //waits for user to press a key (enter)

            auto start = chrono::high_resolution_clock::now(); //start time

            for (int i = 0; i < 10; i++) //forloop 1 to 10
            {
                random_device random; //step 1 rand number
                mt19937 gen(random()); //step 2 rand number

                uniform_int_distribution<> distance(1, 10); //step 3 rand number

                int j = distance(gen); // j = rand

                if (i == 0) { //first iteration
                    int OneTimeInt = distance(gen); //OneTimeInt = rand

                    if (j > 5) {
                        RealAns = j + OneTimeInt;
                        cout << "what is " << j << "+" << OneTimeInt << "?" << endl;
                    }
                    else {
                        RealAns = j - OneTimeInt;
                        cout << "what is " << j << "-" << OneTimeInt << "?" << endl;
                    }

                    cin >> UserAns;
                    if (UserAns == RealAns) {
                        Score++;
                    }
                    else {
                        cout << "incorrect answer, the actual answer was" << "  " << RealAns << endl;
                        break;
                    }
                    PrevInt = RealAns;
                }

                if (i > 0) {
                    if (j > 5) {
                        RealAns = j + PrevInt;
                        cout << "what is " << PrevInt << "+" << j << "?" << endl;
                    }
                    else {
                        RealAns = PrevInt - j;
                        cout << "what is " << PrevInt << "-" << j << "?" << endl;
                    }

                    cin >> UserAns;

                    if (UserAns == RealAns) {
                        Score++;
                    }
                    else {
                        cout << "incorrect answer, the actual answer was" << "  " << RealAns << endl;
                        i = 10;
                    }
                    PrevInt = RealAns;
                }
            }
            auto end = chrono::high_resolution_clock::now(); //end time
            auto duration = chrono::duration_cast<chrono::seconds>(end - start).count();

            cout << "your final score is" << "  " << Score << "!" << endl;
            if (Score == 10) {
                cout << "You took:" << duration << "seconds" << endl;
            }
            break;
        }
        case 2: {
            int PostiveNumber; //Number user will enter
            int DecimalPlaces; //The amount of decimal places the user wants
            double UpperBound; //Upper bound
            double LowerBound; //Lower bound
            double Average = 0.0; // Final answer
            double AverageSquared; //Working backwards from square root to see what number we are currently at
            double Precision = 0.0; //Converts decimal places (user input) to actual decimal places needed
            bool Range = true; //Gives user option to select another range if they choose a number outside of 1 to 7
            cout << "Square Root Calculator" << endl;
            cout << "----------------------" << endl;
            cout << "Please enter a positive number" << endl;
            cin >> PostiveNumber;

            cout << "How many decimal places do you want the solution calculated to (range is 1 to 7)" << endl;
            cin >> DecimalPlaces;
            if (DecimalPlaces < 1 || DecimalPlaces > 7) {
                cout << "Please choose the amount of decimal places in the range of 1 to 7" << endl;
                break;
            }

            if (DecimalPlaces == 1) {
                Precision = 0.1;
            }
            else if (DecimalPlaces == 2) {
                Precision = 0.01;
            }
            else if (DecimalPlaces == 3) {
                Precision = 0.001;
            }
            else if (DecimalPlaces == 4) {
                Precision = 0.0001;
            }
            else if (DecimalPlaces == 5) {
                Precision = 0.00001;
            }
            else if (DecimalPlaces == 6) {
                Precision = 0.000001;
            }
            else if (DecimalPlaces == 7) {
                Precision = 0.0000001;
            }
            UpperBound = PostiveNumber;
            if (PostiveNumber == 0) {
                LowerBound = 0;
            }
            else {
                LowerBound = 1;
            }
            while ((UpperBound - LowerBound) >= Precision) {
                Average = (LowerBound + UpperBound) / 2;
                AverageSquared = Average * Average;
                if (AverageSquared > PostiveNumber) {
                    UpperBound = Average;
                }
                else {
                    LowerBound = Average;
                }
            }
            if (UpperBound - LowerBound <= Precision) {
                cout << fixed << setprecision(DecimalPlaces)
                    << "The square root of " << PostiveNumber
                    << " to " << DecimalPlaces << " decimal places is "
                    << Average << endl;
            }
            break;
        }
        case 3: {
            int UserCode = 0;
            int FirstDigit = 0;
            int SecondDigit = 0;
            int ThirdDigit = 0;
            int FourthDigit = 0;
            int FifthDigit = 0;
            int SixthDigit = 0;
            int OddIndexesAdded = 0;
            int EvenIndexesAdded = 0;
            int IndexTotal = 0;
            int Remainder = 0;
            cout << "Check-Digit Calculator" << endl;
            cout << "----------------------" << endl;
            cout << "This calculator will take a 5 digit number" << endl;
            cout << "and generate a trailing 6th check digit" << endl;
            cout << "Please enter 5-digit number to generate final " << endl;
            cout << "code:" << endl;

            cin >> UserCode; //code stores into variable
            
            if (UserCode < 10000 || UserCode > 99999) {
                cout << "Please enter a 5 digit number" << endl;
                break;
                }
            
            
            FirstDigit = (UserCode / 10000);       //dividing to move decimal place to the left, modulo takes off number furthest to right
            SecondDigit = (UserCode / 1000) % 10;
            ThirdDigit = (UserCode / 100) % 10;
            FourthDigit = (UserCode / 10) % 10;
            FifthDigit = UserCode % 10;

           OddIndexesAdded = (FirstDigit + ThirdDigit + FifthDigit) * 7;

           EvenIndexesAdded = (SecondDigit + FourthDigit) * 3;

           IndexTotal = OddIndexesAdded + EvenIndexesAdded;
           Remainder = (IndexTotal / 10) % 10;

           if (Remainder == 0) {
               SixthDigit = 0;
           }
           else {
              SixthDigit = (10 - Remainder);
           }

           cout << "The 6 digit final number is" << "   " << FirstDigit << SecondDigit << ThirdDigit << FourthDigit << FifthDigit << SixthDigit << endl;

            break;
        }
        case 4: {

            int UserDigit = 0;
            int FirstUserDigit = 0;
            int SecondUserDigit = 0;
            int ThirdUserDigit = 0;
            int FourthUserDigit = 0;
            int FifthUserDigit = 0;
            int SixthUserDigit = 0;
            int OddDigit = 0;
            int EvenDigit = 0;
            int DigitTotal = 0;
            int RemainderDigit = 0;
            int CrossReferenceDigit = 0;
            cout << "Check-Digit Checker" << endl;
            cout << "-------------------" << endl;
            cout << "Please enter 6 - digit number to check" << endl;
            cin >> UserDigit;

            if (UserDigit < 100000 || UserDigit > 99999) {
                cout << "Please enter a 6 digit number to continue" << endl;
                break;
            }

            FirstUserDigit = (UserDigit / 100000);       //dividing to move decimal place to the left, modulo takes off number furthest to right
            SecondUserDigit = (UserDigit / 10000) % 10;
            ThirdUserDigit = (UserDigit / 1000) % 10;
            FourthUserDigit = (UserDigit / 100) % 10;
            FifthUserDigit = (UserDigit / 10) % 10;
            SixthUserDigit = UserDigit % 10;

            OddDigit = (FirstUserDigit + ThirdUserDigit + FifthUserDigit) * 7;

            EvenDigit = (SecondUserDigit + FourthUserDigit) * 3;

            DigitTotal = OddDigit + EvenDigit;
            RemainderDigit = (DigitTotal / 10) % 10;

            if (RemainderDigit == 0) {
                CrossReferenceDigit = 0;
            }
            else {
                CrossReferenceDigit = (10 - RemainderDigit);
            }

            if (CrossReferenceDigit == SixthUserDigit) {

                cout << "The final number generated is" << "   " << CrossReferenceDigit << endl;

                cout << "Therefore, The number is valid" << endl;
            }
            else {

                cout << "The final number generated is" << "   " << CrossReferenceDigit << endl;
                cout << "Therefore, The number is invalid" << endl;
            }
            break;
        }
        case 9: {
            cout << "exiting..." << endl;
            running = false;
            break;
        }
        default:
            cout << "Thanks for playing!" << endl;
        }
    }
    return 0;
}