#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Casino {
private:
    static double budget; //static���� ����

public:
    static double getBudget() {
        return budget;
    }

    static void addToBudget(int amount) {
        budget += amount;
    }

    static void deductFromBudget(int amount) {
        budget -= amount;
    }

    static void resetBudget() {
        budget = 10000;
    }
};
//Ư�� ������ �ʱ�ȭ
double Casino::budget = 100.0;


class Card : public Casino {
private:
    //string shape ���� -> ����A�� ī�带 ���� ���� ���ڰ� ������ �¸�
    int number;
    

public:
    Card( int number) {
       
        this->number = number;
    }

   

    int getNumber() {
        return number;
    }
   
};

class GameA : public Card {} ;
class GameB : public Card {};

class Player {
private:
    string name;
    Card* card;
    double budget;
    double winCount;  //bool* win ��� ���

public:
    Player(string& name, double budget) {
        this->name = name;
        this->budget = budget;
        winCount = 0.0;
        card = nullptr;
    }

    ~Player() {
        delete card;
    }

    string getName() {
        return name;
    }

    Card* getCard() {
        return card;
    }

    void setCard(Card* card) {
        this->card = card;
    }

    double getBudget() {
        return budget;
    }

    void setBudget(double budget) {
        this->budget = budget;
    }

    int getWinCount() {
        return winCount;
    }

    void incrementWinCount() {
        winCount++;
    }

    //���� �÷��̾��� ���� ���� �� ������ �����ε� + �߰� ��� Ű����:const
    friend double operator+(const double& budget, const Player& player) {
        return budget + player.budget;
    }
};

class Dealer : public Casino{
private:
    //name ���� -> ���ӿ��� dealer1,2�� ����
    Card* card1;
    Card* card2;

public:
    Dealer() {
        srand(time(0));
        
        
        int number1 = rand() % 13 + 1;
        card1 = new Card(number1);

        
        int number2 = rand() % 13 + 1;
        card2 = new Card(number2);
    }

    Card* getCard1() {
        return card1;
    }

    Card* getCard2() {
        return card2;
    }

    ~Dealer() {
        delete card1;
        delete card2;
    }
};

class Handler {
private:
    Dealer* dealer1;
    Dealer* dealer2;
    Player* player1;
    Player* player2;
    Player* player3;

public:
    Handler() {
        dealer1 = nullptr;
        dealer2 = nullptr;
        player1 = nullptr;
        player2 = nullptr;
        player3 = nullptr;
    }

    ~Handler() {
        delete dealer1;
        delete dealer2;
        delete player1;
        delete player2;
        delete player3;
    }

    void start() { //ī�� �÷��� �����丮 ��µǰ�
        double gamesPlayed = 0.0;

        double dealer1Wins = 0.0;
        double dealer2Wins = 0.0;

        double player1Wins = 0.0;
        double player2Wins = 0.0;
        double player3Wins = 0.0;

        //�������� �����Ͽ� ����
        dealer1 = new Dealer();
        dealer2 = new Dealer(*dealer1);

        string playerName1, playerName2, playerName3;
        cout << "�÷��̾� 1�� �̸��� �Է��ϼ���: ";
        cin >> playerName1;

        cout << "�÷��̾� 2�� �̸��� �Է��ϼ���: ";
        cin >> playerName2;

        cout << "�÷��̾� 3�� �̸��� �Է��ϼ���: ";
        cin >> playerName3;

        double budget1, budget2, budget3;

        cout << "�÷��̾� 1�� ������ �Է��ϼ���: ";
        cin >> budget1;
        cout << "�÷��̾� 2�� ������ �Է��ϼ���: ";
        cin >> budget2;
        cout << "�÷��̾� 3�� ������ �Է��ϼ���: ";
        cin >> budget3;

        //�������� �Ҵ�
        player1 = new Player(playerName1, budget1);
        player2 = new Player(playerName2, budget2);
        player3 = new Player(playerName3, budget3);

        //�� 6���� ����
        for (int i = 0; i < 6; i++) {

            player1->setBudget(player1->getBudget() - 50); //�� ���Ӵ� ������50
            player2->setBudget(player2->getBudget() - 50);
            player3->setBudget(player3->getBudget() - 50);
            Casino::addToBudget(150);



            //ī�� �й�
            int number1 = rand() % 13 + 1;
            player1->setCard(new Card(number1));


            int number2 = rand() % 13 + 1;
            player2->setCard(new Card(number2));


            int number3 = rand() % 13 + 1;
            player3->setCard(new Card(number3));

            cout << "-------------���� " << gamesPlayed + 1 << "--------------" << endl;
            cout << "���� 1�� ���� ī��: " << dealer1->getCard1()->getNumber() << endl;
            cout << "���� 2�� ���� ī��: " << dealer2->getCard2()->getNumber() << endl;

            cout << player1->getName() << "�� ���� ī��: " << " " << player1->getCard()->getNumber() << endl;
            cout << player2->getName() << "�� ���� ī��: " << " " << player2->getCard()->getNumber() << endl;
            cout << player3->getName() << "�� ���� ī��: " << " " << player3->getCard()->getNumber() << endl;

            //�̱� ��� ã��

            if (player1->getCard()->getNumber() > dealer1->getCard1()->getNumber() && player1->getCard()->getNumber() > dealer2->getCard2()->getNumber() && player1->getCard()->getNumber() > player2->getCard()->getNumber() && player1->getCard()->getNumber() > player3->getCard()->getNumber()) {
                player1->setBudget(player1->getBudget() + 100);
                Casino::deductFromBudget(100);
                player1->incrementWinCount();
                cout << player1->getName() << "�� �̰���ϴ�!" << endl;
                player1Wins++;
            }


            else if (player2->getCard()->getNumber() > dealer1->getCard1()->getNumber() && player2->getCard()->getNumber() > dealer2->getCard2()->getNumber() && player2->getCard()->getNumber() > player1->getCard()->getNumber() && player2->getCard()->getNumber() > player3->getCard()->getNumber()) {
                player2->setBudget(player2->getBudget() + 100);
                Casino::deductFromBudget(100);
                player2->incrementWinCount();
                cout << player2->getName() << "�� �̰���ϴ�!" << endl;
                player2Wins++;
            }


            else if (player3->getCard()->getNumber() > dealer1->getCard1()->getNumber() && player3->getCard()->getNumber() > dealer2->getCard2()->getNumber()) {
                player3->setBudget(player3->getBudget() + 100);
                Casino::deductFromBudget(100);
                player3->incrementWinCount();
                cout << player3->getName() << "�� �̰���ϴ�!" << endl;
                player3Wins++;
            }


            else if (dealer1->getCard1()->getNumber() > dealer2->getCard2()->getNumber() && dealer1->getCard1()->getNumber() > player1->getCard()->getNumber() && dealer1->getCard1()->getNumber() > player2->getCard()->getNumber() && dealer1->getCard1()->getNumber() > player3->getCard()->getNumber()) {
                cout << "���� 1�� �̰���ϴ�!" << endl;
                dealer1Wins++;
            }



            else if (dealer2->getCard1()->getNumber() > dealer1->getCard2()->getNumber() && dealer2->getCard1()->getNumber() > player1->getCard()->getNumber() && dealer2->getCard1()->getNumber() > player2->getCard()->getNumber() && dealer2->getCard1()->getNumber() > player3->getCard()->getNumber()) {
                cout << "���� 2�� �̰���ϴ�!" << endl;
                dealer2Wins++;
            }

            else
                cout << "��ȿ" << endl;

            gamesPlayed++;

            double totalRemainingBudget = player1->getBudget() + player2->getBudget() + player3->getBudget();

            //ī����� ���� �÷��̾���� ���� ����
            cout << endl;
            cout << player1->getName() << "�� �ܾ�: " << player1->getBudget() << endl;
            cout << player2->getName() << "�� �ܾ�: " << player2->getBudget() << endl;
            cout << player3->getName() << "�� �ܾ�: " << player3->getBudget() << endl;
            cout << "ī���� ����: " << Casino::getBudget() << endl;
            cout << "�÷��̾� ��ü �ܾ�: " << totalRemainingBudget << endl;
        }

        cout << endl << "-----------------------" << endl; //��ü �ο� �� �·�
        cout << player1->getName() << "�� �·�: " << (player1Wins / gamesPlayed) * 100 << "%\n";
        cout << player2->getName() << "�� �·�: " << (player2Wins / gamesPlayed) * 100 << "%\n";
        cout << player3->getName() << "�� �·�: " << (player3Wins / gamesPlayed) * 100 << "%\n";
        cout << "���� 1�� �·�: " << (dealer1Wins / gamesPlayed) * 100 << " %\n";
        cout << "���� 2�� �·�: " << (dealer2Wins / gamesPlayed) * 100 << " %\n";
    
    }
};

int main() {
    Handler handler;
    handler.start();

    return 0;
}