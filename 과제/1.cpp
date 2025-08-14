#include <iostream>
using namespace std;

// 배열 인덱스를 위한 상수 정의
const int HP = 0;
const int MP = 1;
const int att = 2;
const int def = 3;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    if (count == 0) {
        // 초기화
        *p_HPPotion = 5;
        *p_MPPotion = 5;
    }
    else if (count == 1) {
        // HP포션 차감 (1번 선택시)
        (*p_HPPotion)--;
    }
    else if (count == 2) {
        // MP포션 차감 (2번 선택시)
        (*p_MPPotion)--;
    }
}

int main() {
    int cha[4] = { 0, 0, 0, 0 }; // HP, MP, att, def 초기화
    int hpPotion, mpPotion;

    cout << "HP와 MP를 입력해주세요: ";
    cin >> cha[HP] >> cha[MP];
    while (cha[HP] <= 50 || cha[MP] <= 50) {
        cout << "값이 너무 작습니다. 다시 입력해주세요: ";
        cin >> cha[HP] >> cha[MP];
    }

    cout << "공격력과 방어력을 입력해주세요: ";
    cin >> cha[att] >> cha[def];
    while (cha[att] <= 0 || cha[def] <= 50) {
        cout << "값이 너무 작습니다. 다시 입력해주세요: ";
        cin >> cha[att] >> cha[def]; // HP, MP가 아니라 att, def를 다시 입력받아야 함
    }

    // 포션 초기 설정
    setPotion(0, &hpPotion, &mpPotion);

    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n";
    cout << "=============================================\n";
    cout << "<스탯 관리 시스템>\n";
    cout << "1. HP 회복\n";
    cout << "2. MP 회복\n";
    cout << "3. HP 강화\n";
    cout << "4. MP 강화\n";
    cout << "5. 공격 스킬 사용\n";
    cout << "6. 필살기 사용\n";
    cout << "7. 나가기\n";

    int a;
    while (true) { // 무한 루프로 변경
        cout << "번호를 선택해주세요: ";
        cin >> a;

        if (a == 1) {
            if (hpPotion > 0) {
                cha[HP] += 20;
                setPotion(a, &hpPotion, &mpPotion); // a값(1)을 그대로 전달
                cout << "* HP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n";
                cout << "현재 HP: " << cha[HP] << "\n남은 포션 수: " << hpPotion << "\n";
            }
            else {
                cout << "HP 포션이 부족합니다.\n";
            }
        }
        else if (a == 2) {
            if (mpPotion > 0) {
                cha[MP] += 20;
                setPotion(a, &hpPotion, &mpPotion); // a값(2)을 그대로 전달
                cout << "* MP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n";
                cout << "현재 MP: " << cha[MP] << "\n남은 포션 수: " << mpPotion << "\n";
            }
            else {
                cout << "MP 포션이 부족합니다.\n";
            }
        }
        else if (a == 3) {
            cha[HP] *= 2;
            cout << "* HP가 2배로 증가되었습니다.\n현재 HP: " << cha[HP] << "\n";
        }
        else if (a == 4) {
            cha[MP] *= 2;
            cout << "* MP가 2배로 증가되었습니다.\n현재 MP: " << cha[MP] << "\n";
        }
        else if (a == 5) {
            if (cha[HP] >= 50) {
                cha[HP] -= 50;
                cout << "* 스킬을 사용하여 HP가 50 소모되었습니다.\n현재 HP: " << cha[HP] << "\n";
            }
            else {
                cout << "스킬 사용이 불가합니다.\n";
            }
        }
        else if (a == 6) {
            cha[MP] /= 2;
            cout << "* 스킬을 사용하여 MP가 50% 소모되었습니다.\n현재 MP: " << cha[MP] << "\n";
        }
        else if (a == 7) {
            cout << "프로그램을 종료합니다.\n";
            break;
        }
        else {
            cout << "잘못된 입력입니다.\n";
        }
    }

    return 0;
}