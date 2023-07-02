#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Casino {
private:
    static double budget; //static변수 선언

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
//특정 값으로 초기화
double Casino::budget = 100.0;


class Card : public Casino {
private:
    //string shape 삭제 -> 게임A는 카드를 열어 높은 숫자가 나오면 승리
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
    double winCount;  //bool* win 대신 사용

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

    //남은 플레이어의 예산 구할 때 연산자 오버로딩 + 추가 사용 키워드:const
    friend double operator+(const double& budget, const Player& player) {
        return budget + player.budget;
    }
};

class Dealer : public Casino{
private:
    //name 삭제 -> 게임에서 dealer1,2로 구분
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

    void start() { //카드 플레이 히스토리 출력되게
        double gamesPlayed = 0.0;

        double dealer1Wins = 0.0;
        double dealer2Wins = 0.0;

        double player1Wins = 0.0;
        double player2Wins = 0.0;
        double player3Wins = 0.0;

        //동적으로 복사하여 생성
        dealer1 = new Dealer();
        dealer2 = new Dealer(*dealer1);

        string playerName1, playerName2, playerName3;
        cout << "플레이어 1의 이름을 입력하세요: ";
        cin >> playerName1;

        cout << "플레이어 2의 이름을 입력하세요: ";
        cin >> playerName2;

        cout << "플레이어 3의 이름을 입력하세요: ";
        cin >> playerName3;

        double budget1, budget2, budget3;

        cout << "플레이어 1의 예산을 입력하세요: ";
        cin >> budget1;
        cout << "플레이어 2의 예산을 입력하세요: ";
        cin >> budget2;
        cout << "플레이어 3의 예산을 입력하세요: ";
        cin >> budget3;

        //동적으로 할당
        player1 = new Player(playerName1, budget1);
        player2 = new Player(playerName2, budget2);
        player3 = new Player(playerName3, budget3);

        //총 6번의 게임
        for (int i = 0; i < 6; i++) {

            player1->setBudget(player1->getBudget() - 50); //한 게임당 참가비50
            player2->setBudget(player2->getBudget() - 50);
            player3->setBudget(player3->getBudget() - 50);
            Casino::addToBudget(150);



            //카드 분배
            int number1 = rand() % 13 + 1;
            player1->setCard(new Card(number1));


            int number2 = rand() % 13 + 1;
            player2->setCard(new Card(number2));


            int number3 = rand() % 13 + 1;
            player3->setCard(new Card(number3));

            cout << "-------------게임 " << gamesPlayed + 1 << "--------------" << endl;
            cout << "딜러 1이 받은 카드: " << dealer1->getCard1()->getNumber() << endl;
            cout << "딜러 2가 받은 카드: " << dealer2->getCard2()->getNumber() << endl;

            cout << player1->getName() << "이 받은 카드: " << " " << player1->getCard()->getNumber() << endl;
            cout << player2->getName() << "이 받은 카드: " << " " << player2->getCard()->getNumber() << endl;
            cout << player3->getName() << "이 받은 카드: " << " " << player3->getCard()->getNumber() << endl;

            //이긴 사람 찾기

            if (player1->getCard()->getNumber() > dealer1->getCard1()->getNumber() && player1->getCard()->getNumber() > dealer2->getCard2()->getNumber() && player1->getCard()->getNumber() > player2->getCard()->getNumber() && player1->getCard()->getNumber() > player3->getCard()->getNumber()) {
                player1->setBudget(player1->getBudget() + 100);
                Casino::deductFromBudget(100);
                player1->incrementWinCount();
                cout << player1->getName() << "이 이겼습니다!" << endl;
                player1Wins++;
            }


            else if (player2->getCard()->getNumber() > dealer1->getCard1()->getNumber() && player2->getCard()->getNumber() > dealer2->getCard2()->getNumber() && player2->getCard()->getNumber() > player1->getCard()->getNumber() && player2->getCard()->getNumber() > player3->getCard()->getNumber()) {
                player2->setBudget(player2->getBudget() + 100);
                Casino::deductFromBudget(100);
                player2->incrementWinCount();
                cout << player2->getName() << "이 이겼습니다!" << endl;
                player2Wins++;
            }


            else if (player3->getCard()->getNumber() > dealer1->getCard1()->getNumber() && player3->getCard()->getNumber() > dealer2->getCard2()->getNumber()) {
                player3->setBudget(player3->getBudget() + 100);
                Casino::deductFromBudget(100);
                player3->incrementWinCount();
                cout << player3->getName() << "이 이겼습니다!" << endl;
                player3Wins++;
            }


            else if (dealer1->getCard1()->getNumber() > dealer2->getCard2()->getNumber() && dealer1->getCard1()->getNumber() > player1->getCard()->getNumber() && dealer1->getCard1()->getNumber() > player2->getCard()->getNumber() && dealer1->getCard1()->getNumber() > player3->getCard()->getNumber()) {
                cout << "딜러 1이 이겼습니다!" << endl;
                dealer1Wins++;
            }



            else if (dealer2->getCard1()->getNumber() > dealer1->getCard2()->getNumber() && dealer2->getCard1()->getNumber() > player1->getCard()->getNumber() && dealer2->getCard1()->getNumber() > player2->getCard()->getNumber() && dealer2->getCard1()->getNumber() > player3->getCard()->getNumber()) {
                cout << "딜러 2가 이겼습니다!" << endl;
                dealer2Wins++;
            }

            else
                cout << "무효" << endl;

            gamesPlayed++;

            double totalRemainingBudget = player1->getBudget() + player2->getBudget() + player3->getBudget();

            //카지노와 각각 플레이어들의 남은 예산
            cout << endl;
            cout << player1->getName() << "의 잔액: " << player1->getBudget() << endl;
            cout << player2->getName() << "의 잔액: " << player2->getBudget() << endl;
            cout << player3->getName() << "의 잔액: " << player3->getBudget() << endl;
            cout << "카지노 예산: " << Casino::getBudget() << endl;
            cout << "플레이어 전체 잔액: " << totalRemainingBudget << endl;
        }

        cout << endl << "-----------------------" << endl; //전체 인원 별 승률
        cout << player1->getName() << "의 승률: " << (player1Wins / gamesPlayed) * 100 << "%\n";
        cout << player2->getName() << "의 승률: " << (player2Wins / gamesPlayed) * 100 << "%\n";
        cout << player3->getName() << "의 승률: " << (player3Wins / gamesPlayed) * 100 << "%\n";
        cout << "딜러 1의 승률: " << (dealer1Wins / gamesPlayed) * 100 << " %\n";
        cout << "딜러 2의 승률: " << (dealer2Wins / gamesPlayed) * 100 << " %\n";
    
    }
};

int main() {
    Handler handler;
    handler.start();

    return 0;
}