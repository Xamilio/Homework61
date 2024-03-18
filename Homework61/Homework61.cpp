#include <iostream>
#include <stdexcept>

using namespace std;

bool HappyNumber(int number) {
    if (number < 100000 || number > 999999) {
        throw out_of_range("Номер должен содержать 6 цифр");
    }

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 6; ++i) {
        if (i < 3)
        {
            sum1 += number % 10;
        }
        else 
        {
            sum2 += number % 10;
        }
        number /= 10;
    }
    return sum1 == sum2;
}

int main() {
    try {
        int number;
        cout << "Введите 6 значное число: ";
        cin >> number;

        if (cin.fail()) {
            throw invalid_argument("Неверный Ввод ");
        }

        HappyNumber(number);
        cout << number << " Это в счастливое число" << endl;
    }
    catch (const out_of_range& ex) {
        cerr << "Ошибка: " << ex.what() << endl;
    }
    catch (const invalid_argument& ex) {
        cerr << "Ошибка: " << ex.what() << endl;
    }
}