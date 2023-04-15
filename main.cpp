#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout<<"Введите количество воды (мл): ";
    int water;
    std::cin>>water;

    std::cout<<"Введите количество молока в мл: ";
    int milk;
    std::cin>>milk;

    int milkAmer=0;
    int waterAmer=300;
    int milkLat=270;
    int waterLat=30;

    int chosenDrink=0;

    bool noWforAmer=water<300;
    bool noWforLat=water<30;
    bool noMforLat=milk<270;

    int americanos=0;
    int lattes=0;

    while (!noWforAmer || !noWforLat && !noMforLat) {
        std::cout << "Выберите напиток (1 — американо, 2 — латте): ";
        std::cin >> chosenDrink;
        if (chosenDrink==1) {
            if (!noWforAmer) {
                ++americanos;
                std::cout << "=============\nПодождите\n=============\n";
                std::cout << "Ваш напиток готов.\n=============\n";
                water-=waterAmer;
                noWforAmer=water<300;
            } else {
                std::cout << "Не хватает воды для американо\n";
            }
        } else if (chosenDrink==2) {
            if (!noWforLat && !noMforLat) {
                ++lattes;
                std::cout << "=============\nПодождите\n=============\n";
                std::cout << "Ваш напиток готов.\n=============\n";
                water-=waterLat;
                milk-=milkLat;
                noWforLat=water<30;
                noMforLat=milk<270;
            }
            if (noWforLat) {
                std::cout << "Не хватает воды для латте\n";
            }
            if (noMforLat) {
                std::cout << "Не хватает молока для латте\n";
            }
        } else {
            std::cout << "Неверно выбран напиток! Попробуйте еще раз\n";
        }
    }


}
