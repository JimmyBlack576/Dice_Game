#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

void Throw(int dice)
{
    switch (dice)
    {
    case 1:
        cout << "\t===========" << endl;
        cout << "\t|         |" << endl;
        cout << "\t|         |" << endl;
        cout << "\t|    *    |" << endl;
        cout << "\t|         |" << endl;
        cout << "\t|         |" << endl;
        cout << "\t===========" << endl;
        break;
    case 2:
        cout << "\t===========" << endl;
        cout << "\t|         |" << endl;
        cout << "\t|    *    |" << endl;
        cout << "\t|         |" << endl;
        cout << "\t|    *    |" << endl;
        cout << "\t|         |" << endl;
        cout << "\t===========" << endl;
        break;
    case 3:
        cout << "\t===========" << endl;
        cout << "\t|         |" << endl;
        cout << "\t|  *      |" << endl;
        cout << "\t|    *    |" << endl;
        cout << "\t|      *  |" << endl;
        cout << "\t|         |" << endl;
        cout << "\t===========" << endl;
        break;
    case 4:
        cout << "\t===========" << endl;
        cout << "\t|         |" << endl;
        cout << "\t|  *   *  |" << endl;
        cout << "\t|         |" << endl;
        cout << "\t|  *   *  |" << endl;
        cout << "\t|         |" << endl;
        cout << "\t===========" << endl;
        break;
    case 5:
        cout << "\t===========" << endl;
        cout << "\t|         |" << endl;
        cout << "\t|  *   *  |" << endl;
        cout << "\t|    *    |" << endl;
        cout << "\t|  *   *  |" << endl;
        cout << "\t|         |" << endl;
        cout << "\t===========" << endl;
        break;
    case 6:
        cout << "\t===========" << endl;
        cout << "\t|         |" << endl;
        cout << "\t|  *   *  |" << endl;
        cout << "\t|  *   *  |" << endl;
        cout << "\t|  *   *  |" << endl;
        cout << "\t|         |" << endl;
        cout << "\t===========" << endl;
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int choice, dice1, dice2,playerpoints=0,pcpoints=0;
    char cast;
    srand(time(NULL));
    do {
        cout<< "Привет =) \n\n"
            << "Сыграем в кости? \n\n"
            << "1. Начать игру! \n"
            << "2. Выйти из игры \n";
        cin >> choice;
        //определение очерёдности хода
        if (choice == 1) {
            do {
                cout << "Пробный бросок: \n";
                Sleep(800);
                cout << "У кого выпадет большее значение, того первый ход =) \n";
                Sleep(800);
                cout << "Ты бросаешь... \n";
                cout << "Нажми \"x\" чтобы бросить кубики ";
                cin >> cast;
                Sleep(1500);
                dice1 = rand() % 6+1;
                cout << "У тебя выпало \n";
                Throw(dice1);
                cout << "Моя очередь...\n";
                Sleep(1500);
                dice2 = rand() % 6+1;
                cout << "У меня выпало \n";
                Throw(dice2);
                if (dice1 == dice2) {
                    cout << "Ничья! \n"
                        << "Ещё разок =)\n\n";
                }while (cast != 'x');
               
            } while (dice1 == dice2);
            //Начинается игра
            if (dice1 > dice2) {
                cout << "\nТы выиграл! Бросаешь первым =)\n\n\n";
                for (int i = 1; i <= 3; i++)
                {
                    Sleep(800);
                    cout <<"\t" << i << " РАУНД \n\n";
                    do {
                        Sleep(800);
                        cout << "Нажми \"x\" чтобы бросить кубики ";
                        cin >> cast;
                    } while (cast != 'x');

                    cout << "Твои кубики крутятся...\n";
                    Sleep(1500);
                    dice1 = 1 + rand() % 6;
                    dice2 = 1 + rand() % 6;
                    Throw(dice1);
                    Throw(dice2);
                    playerpoints += dice1 + dice2;
                    Sleep(800);
                    cout << "Ты набрал " << playerpoints << " очков! \n";
                    Sleep(800);
                    cout << "Моя очередь... \n";
                    Sleep(1500);
                    dice1 = 1 + rand() % 6;
                    dice2 = 1 + rand() % 6;
                    Throw(dice1);
                    Throw(dice2);
                    pcpoints+= dice1 + dice2;
                    cout << "У меня " << pcpoints << " очков =)\n\n\n";
                    
                    cout << " Результаты " << i << " раунда \n";
                    cout << "Твои очки -> " << playerpoints<<endl;
                    cout << "Мои очки -> " << pcpoints<<endl<<endl;
                    Sleep(2000);

                }
            }
            else {
                Sleep(800);
                cout << "У меня выпало больше! Ход мой! =)\n\n\n";
                for (int i = 1; i <= 3; i++) {
                    cout << "\t" << i << " РАУНД \n\n";
                    Sleep(800);
                    cout << "Я бросаююю...\n";
                    Sleep(1500);
                    dice1 = 1 + rand() % 6;
                    dice2 = 1 + rand() % 6;
                    Throw(dice1);
                    Throw(dice2);
                    pcpoints += dice1 + dice2;
                    cout << "Я набрал " << pcpoints << " очков! \n";
                    Sleep(800);
                    cout << "Твоя очередь... \n";
                    Sleep(800);
                    cout << "Нажми \"x\" чтобы бросить кубики ";
                    cin >> cast;
                    Sleep(1500);
                    dice1 = 1 + rand() % 6;
                    dice2 = 1 + rand() % 6;
                    Throw(dice1);
                    Throw(dice2);
                    playerpoints += dice1 + dice2;
                    cout << "У тебя " << playerpoints << " очков =)\n\n\n";

                    cout << " Результаты " << i << " раунда \n";
                    cout << "Твои очки -> " << playerpoints << endl;
                    cout << "Мои очки -> " << pcpoints << endl<<endl;
                    Sleep(2000);
                }
            }
            

       
           if (playerpoints > pcpoints) 
           {
                cout << "Поздравляю! Ты выиграл! \n";
                break;
           }
            else if (playerpoints < pcpoints) 
            {
                cout << "Не раскисай! В следующий раз тебе обязательно повезёт! =)\n";
                break;
            }
            else 
            {
                cout << "Надо же! Ничья =)\n";
                break;
            }
        }else if (choice == 2)
        {
            cout << "Увидимся в следующей игре! =)\n"; break;
        }
        else
        {
            cout << "Ну в меню кажется нет таких Циферок =P\n";
            cout << "Попробуй прицелиться точнее! xD\n\n\n";
        }
        

    } while (choice != 2);
    
}

