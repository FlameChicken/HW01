#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;
}

int main()
{
    int status[4] = { 0,0,0,0 };
    // 0: HP, 1: MP, 2: 공격력, 3: 방어력
    // 쓰레기값 방지

    int hpPotion;
    int mpPotion;
    int level = 1;

    // HP / MP 입력 검사
    while (true)
    {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> status[0] >> status[1];

        if (status[0] <= 50 || status[1] <= 50)
        {
            cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
        }
        else
        {
            break;
        }
    }

    // 공격력 / 방어력 입력 검사
    while (true)
    {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> status[2] >> status[3];

        if (status[2] <= 0 || status[3] <= 0)
        {
            cout << "공격력이나 방어력이 너무 작습니다. 다시 입력해주세요.\n";
        }
        else
        {
            break;
        }
    }

    // 포션 지급
    setPotion(5, &hpPotion, &mpPotion);
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n";

    while (true)
    {
        cout << "=============================================\n";
        cout << "<스탯 관리 시스템>\n";
        cout << "1. HP UP\n";
        cout << "2. MP UP\n";
        cout << "3. 공격력 UP\n";
        cout << "4. 방어력 UP\n";
        cout << "5. 현재 능력치\n";
        cout << "6. Level UP\n";
        cout << "0. 나가기\n";

        int menu;
        cout << "번호를 선택해주세요: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            if (hpPotion > 0)
            {
                status[0] += 20;
                hpPotion--;

                cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n";
                cout << "현재 HP: " << status[0] << endl;
                cout << "남은 HP 포션 수: " << hpPotion << endl;
            }
            else
            {
                cout << "포션이 부족합니다.\n";
            }
            break;

        case 2:
            if (mpPotion > 0)
            {
                status[1] += 20;
                mpPotion--;

                cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n";
                cout << "현재 MP: " << status[1] << endl;
                cout << "남은 MP 포션 수: " << mpPotion << endl;
            }
            else
            {
                cout << "포션이 부족합니다.\n";
            }
            break;

        case 3:
            status[2] *= 2;
            cout << "* 공격력이 2배로 증가되었습니다.\n";
            cout << "현재 공격력: " << status[2] << endl;
            break;

        case 4:
            status[3] *= 2;
            cout << "* 방어력이 2배로 증가되었습니다.\n";
            cout << "현재 방어력: " << status[3] << endl;
            break;

        case 5:
            cout << "* 현재 능력치\n";
            cout << "레벨 : " << level << endl;
            cout << "HP : " << status[0] << endl;
            cout << "MP : " << status[1] << endl;
            cout << "공격력 : " << status[2] << endl;
            cout << "방어력 : " << status[3] << endl;
            cout << "남은 HP/MP 포션 : " << hpPotion << " / " << mpPotion << endl;
            break;

        case 6:
            level++;
            hpPotion++;
            mpPotion++;

            cout << "* 레벨업! HP/MP 포션이 지급됩니다.\n";
            cout << "현재 레벨 : " << level << endl;
            cout << "남은 HP/MP 포션 수 : " << hpPotion << "/" << mpPotion << endl;
            break;

        case 0:
            cout << "프로그램을 종료합니다.\n";
            return 0;

        default:
            cout << "잘못된 입력입니다.\n";
        }
    }
}