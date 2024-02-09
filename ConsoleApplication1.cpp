#include <iostream>
using namespace std;

// Класс BankAccount для представления банковского счета клиента
class BankAccount {
private:
    string password;
    double balance;
public:
    BankAccount(string password, double balance) {
        this->password = password;
        this->balance = balance;
    }

    bool verifyPassword(string inputPassword) {
        return inputPassword == password;
    }

    bool checkBalance(double amount) {
        return balance >= amount;
    }

    void withdraw(double amount) {
        balance -= amount;
        cout << "Выдано " << amount << " денег" << endl;
    }
};

int main() 
{
    setlocale(LC_ALL, "");
    // Создание объекта BankAccount
    BankAccount account("123456", 1000);

    string password;
    double amount;

    // Проверка пароля
    cout << "Введите пароль: ";
    cin >> password;

    if (!account.verifyPassword(password)) {
        cout << "Пароль неверный" << endl;
        return 0;
    }

    // Проверка суммы
    cout << "Введите сумму для снятия: ";
    cin >> amount;

    if (!account.checkBalance(amount)) {
        cout << "Недостаточно средств на счету" << endl;
        return 0;
    }

    // Выдача денег
    account.withdraw(amount);

    return 0;
}