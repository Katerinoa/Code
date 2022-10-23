#include <bits/stdc++.h>
#include "CardsStack.h"
#include "CardsQuene.h"
LinkStack Desktop;
CQuene Player1, Player2;
char Cards[52] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K',
                  'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K',
                  'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K',
                  'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
//���ҿ�������
void shuffle(char *Cards)
{
    srand(time(0));
    for (int i = 0; i < 51; i++)
    {
        int index = rand() % (52 - i) + i;
        if (index != i)
        {
            int t = Cards[i];
            Cards[i] = Cards[index];
            Cards[index] = t;
        }
    }
}
//��Ϸ��ʼ��
void initGame()
{
    initQuene(Player1);
    initQuene(Player2);
    initStack(Desktop);
    //���ҿ�����������ҷ���
    shuffle(Cards);
    int i = 0;
    for (; i < 26; i++)
        GetCards(Player1, Cards[i]);
    for (; i < 52; i++)
        GetCards(Player2, Cards[i]);
}
void GameStart()
{
    int round = 1;
    int flag = 1; // flagΪ1���1���ƣ�Ϊ2�����2����
    while (!QueneEmpty(Player1) && !QueneEmpty(Player2))
    {
        cout << "round" << round << ": ";
        CQuene &roundPlayer = (flag == 1) ? Player1 : Player2;
        char card = PlayCards(roundPlayer);
        cout << "���" << flag << "����: ";
        if (card == 'T')
            cout << 10;
        else
            cout << card;
        if (card) //���Ƴɹ�
        {
            int index = searchCard(Desktop, card);
            if (index)
            {
                cout << "  �ƶ����п���: " << card << " ���" << flag << "ȡ��: ";
                GetCards(roundPlayer, card);
                if (card == 'T')
                    cout << 10 << ' ';
                else
                    cout << card << ' ';
                while (index--)
                {
                    char tempCard = Pop(Desktop);
                    GetCards(roundPlayer, tempCard);
                    if (tempCard == 'T')
                        cout << 10 << ' ';
                    else
                        cout << tempCard << ' ';
                }
                cout << endl;
            }
            else
                Push(Desktop, card);
            cout << "  ʣ������: " << countCards(roundPlayer) << endl;
        }
        //����״̬
        flag = (flag == 1) ? 2 : 1;
        round++;
    }
}
void GameResult()
{
    if (QueneEmpty(Player2))
        cout << "���1ʤ��!" << endl;
    else
        cout << "���2ʤ��!" << endl;
}
int main()
{
    initGame();
    GameStart();
    GameResult();
    system("pause");
    return 0;
}