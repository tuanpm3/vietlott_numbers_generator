#include <iostream>
#include <random>
#include <chrono>

using namespace std;

void vietlott_mega_6_45()
{
    time_t currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    std::default_random_engine pseudo_random_generator(currentTime);
    std::uniform_int_distribution<int> int_distribution(1, 45);

    printf ("Lucky number today: ");
    for (int i = 0; i < 6; i++) {
        printf("%02d ", int_distribution(pseudo_random_generator));
    }
    printf ("\n");
}

void vietlott_mega_3plus()
{
    time_t currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    std::default_random_engine pseudo_random_generator(currentTime);
    std::uniform_int_distribution<int> int_distribution(0, 999);

    printf ("Lucky number today: ");
    for (int i = 0; i < 2; i++) {
        printf("%03d ", int_distribution(pseudo_random_generator));
    }
    printf ("\n");
}

int main(int argc, char *argv[])
{
    //////////////////////////////// Shun - CppDeveloper ////////////////////////////////
    bool run = true;
    while (run)
    {
        cout << "0: Exit" << endl;
        cout << "1: Vietlott Jackpot" << endl;
        cout << "2: Vietlott Mega3+" << endl;
        cout << "Your choice is: ";
        int choice = 0;
        cin >> choice;

        if (cin.fail()) { // user nhap chu
           cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else { // user nhap so
           run = ((choice < 0) || (choice > 2)); // check gia tri nhap vao
        }

        if (run) {
            cout << "================================" << endl;
            cout << "Wrong input, please input again." << endl;
            continue;
        }

        switch (choice) {
        case 0:
            run = false;
            break;
        case 1:
            run = true;
            vietlott_mega_6_45();
            break;
        case 2:
            run = true;
            vietlott_mega_3plus();
            break;
        default:
            break;
        }
    }
    //////////////////////////////// Shun - CppDeveloper ////////////////////////////////

    return 0;
}
