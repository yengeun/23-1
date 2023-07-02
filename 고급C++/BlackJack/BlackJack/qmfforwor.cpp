#include <vector>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

class Casino {
protected:
    const int NUMBER_OF_CARDS = 52;
    std::string suits[4] = { "Spades", "Hearts", "Diamonds", "Clubs" };
    std::string ranks[13] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "Jack", "Queen", "King" };
private:
    static double budget;

public:
    static double getBudget() {
        return budget;
    }
};

// Casino 클래스의 budget 정의 및 초기화
double Casino::budget = 10000.0;


class Card : private Casino{
private:
    string shape;
    int num;
    
public:
    Card(int number); //카드에 번호 넣기 
    void show(); //카드 보여주기 

    
        Card() {
            setShape();
        }

        void setShape() {
            vector<int> deck(NUMBER_OF_CARDS);

            // Initialize cards
            for (int i = 0; i < NUMBER_OF_CARDS; i++)
                deck[i] = i;

            // Shuffle the cards
            srand(time(0));
            for (int i = 0; i < NUMBER_OF_CARDS; i++) {
                // Generate an index randomly
                int index = rand() % NUMBER_OF_CARDS;
                int temp = deck[i];
                deck[i] = deck[index];
                deck[index] = temp;
            }

            shape = suits[deck[0] / 13];
            num = deck[0] % 13;
        }

        string getShape() {

            return ranks[num] + " of " + shape;

        }


        int getNum() const {
            return num;
        }



    int CardPoint()
    {
        int temp = 0;
        if (num % 13 == 0)
        {
            temp = temp + 10;
        }

        else if (num % 13 < 10)
        {
            temp = temp + num % 13;
        }
        else
        {
            temp = temp + 10;
        }

        return (temp);
    }
};



class DeckofCards {
private:
    
    vector<Card> number; //카드 52장. 
public:
    DeckofCards();
    void init();
    Card getCard();

    Card(int number)
    {
        this->number = number;
    }

    DeckofCards() {
        srand(time(NULL));
        init();
    }

    void shuffle() {
        for (int i = 0; i < 100; i++) {
            Card temp;
            int left;
            int right;

            left = rand() % NUMBER_OF_CARDS;
            right = rand() % NUMBER_OF_CARDS;
            temp = number[left];
            number[left] = number[right];
            number[right] = temp;
        }
    }

    Card DeckofCards::getCard() {
        Card card;
        if (number.size() >= 1) {

            card = number[number.size() - 1];
            number.pop_back();
        }
        return card;
    }

    void DeckofCards::init() {
        number.clear();
        for (int i = 0; i < 52; i++) {
            number.push_back(i + 1);
        }
    }

};

class Dealer : private Casino {
private:
    string name;
    int budget;
    Card* card;

        Dealer() {
        card = new Card();
    }

    ~Dealer() {
        delete card;
    }
    void setShape(Card* newCard) {
        card = newCard;
    }

    std::string getShape() {
        
        return "Dealer의 카드: " + card->getShape();
    }


};

class Person : private Casino {
private:
    string name;
    Card* card;
        bool win;
        double budget;
    
public:
    Person();    //사람을 생성함.. 이름 나이 입력 없이.. 
    Person(string name);  //사람을 생성함.. 이름만 가지고 
    
    string getName() const;    //사람의 이름을 돌려줌. 
         
    void setName(string name);  //사람의 이름을 설정함. 
    

    

    Person(string name) {
        this->name = name;

    }

    string getName() const
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }


};

/* 게임을 하는 사람에 대한 정보를 담는 클래스 */
class Player :public Person {  //사람에 대한것을 상속 받는다. 
private:
    int Point;        //게임에 사용되는 사이버 머니? (초기에 얼마로 할까요? )
    vector <Card> myCard;  //가지고 있는 카드 

public:
    Player();
    Player(int Point);
    Player(string name, int Point);
   

    int getPoint() const;    //포인트가 얼마나 남았나 확인.. 
    void setPoint(int point);  //포인트를 설정
    void changePoint(int point);//포인트를 변경.. 구입, 차감을 위하여 

   
    int addCard(Card); // card 한장을 더 받다. 
    void showMyCard(); // card를 보여준다. 
    int myCardPoint(); // card 점수를 보여준다. 
    int clearCard();

    Player() {
    }

    Player(int _Point) {
        Point = _Point;
    }

    Player(string _name, int _Point) :Person(_name) {
        Point = _Point;
    }

  
    int getPoint() const {
        return Point;
    }

    void setPoint(int point) {
        this->Point = point;

    }

    void changePoint(int point) {
        this->Point += Point;
    }

    int clearCard()
    {
        myCard.clear();
        return 0;
    }

    int addCard(Card add)
    {
        myCard.push_back(add);
        return 0;
    }

    void showMyCard()
    {
        int temp = 0;
        for (int i = 0; i < myCard.size(); i++)
        {
            myCard[i].show();
            temp = myCardPoint();
        }
        cout << " " << temp;
    }

    bool playCard(DeckofCards* deck) {
        bool ret = false;  //burst;

    //A에 대하여 고려하지 않았다. 
    int myCardPoint()
    {
        int ret = 0;
        for (int i = 0; i < myCard.size(); i++)
        {
            int temp = myCard[i].CardPoint();

            if (temp > 10)
            {
                ret = ret + 10;
            }
            else
            {
                ret = ret + temp;
            }
        }

        
    }


};

class GameA {

    
 
   
};
class Handler {

public:

    int start()
    {

        //클래스 카드를 이용하여 카드 객체를 하나 만든다. 
        DeckofCards Deck;
        //카드를 잘 섞는다. 
        Deck.shuffle();


        int playerCount = 3;

        Player* gamer = new Player[playerCount];

        //딜러설정
        Player dealer("딜러", 50000);

        cout << "게임하는 분의 정보를 입력해 주세요 ? " << endl;

        for (int i = 0; i < playerCount; i++)
        {
            string inputName;
            cout << endl << i + 1 << "번째 player의 이름 : ";
            cin >> inputName;
            gamer[i].setName(inputName);


            int point;
            cout << inputName << "님의 포인트는 얼마입니까? ";
            cin >> point;
            gamer[i].setPoint(point);
        }

        //for (int  i = 0 ; i < playerCount; i ++ ) {
        int i;
        for (i = 0; i < playerCount; i++)
        {
            cout << gamer[i].getName() << ", Point " << gamer[i].getPoint() << endl;
        }
        cout << " *********************************** " << endl;

        cout << " 게임을 시작하겠습니다. " << endl << endl;



        int end = 0;
        vector<int> beting;

        while (end == 0)
        {
            //플레이어의 포인터 안내.
            for (i = 0; i < playerCount; i++)
            {
                cout << gamer[i].getName() << " 님의 남은 포인트는 ";
                cout << gamer[i].getPoint() << endl;
            }


            //첫번째 카드 받기.. 
            for (i = 0; i < playerCount; i++)
            {
                Card temp = Deck.getCard();
                gamer[i].addCard(temp);
                cout << gamer[i].getName() << " : ";
                gamer[i].showMyCard();
                cout << "\n";
            }
            //딜러 첫번째.
            Card temp = Deck.getCard();
            dealer.addCard(temp);
            cout << dealer.getName() << " : ";
            dealer.showMyCard();
            cout << "\n";








            //게임 시작. 
            for (i = 0; i < playerCount; i++)
            {
                gamer[i].playCard(&Deck);
                cout << "\n";
            }



            if (dealer.myCardPoint() > 21)
            {
                cout << " 딜러 BURST..." << endl;
                int winerpoint = 0;
                for (i = 0; i < playerCount; i++)
                {
                    if (gamer[i].myCardPoint() > winerpoint)
                    {
                        winerpoint = gamer[i].myCardPoint();
                    }
                }

                for (i = 0; i < playerCount; i++)
                {
                    if (gamer[i].myCardPoint() == winerpoint && gamer[i].myCardPoint() < 21)
                    {
                        cout << gamer[i].getName() << "님이 이겼습니다. " << endl;
                        gamer[i].setPoint(gamer[i].getPoint() + beting[i]);
                    }
                    else
                    {
                        gamer[i].setPoint(gamer[i].getPoint() - beting[i]);
                    }
                }
            }


            else
            {
                cout << dealer.getName() << " : ";
                dealer.showMyCard();
                cout << endl;

                for (i = 0; i < playerCount; i++)
                {
                    cout << gamer[i].getName() << " : ";
                    gamer[i].showMyCard();
                    cout << "\n";
                }

                int winerpoint = dealer.myCardPoint();

                for (i = 0; i < playerCount; i++)
                {
                    if (gamer[i].myCardPoint() > winerpoint)
                    {
                        if (gamer[i].myCardPoint() > 21);
                        else
                        {
                            winerpoint = gamer[i].myCardPoint();
                        }
                    }
                }



                for (i = 0; i < playerCount; i++)
                {
                    if (winerpoint == dealer.myCardPoint())
                    {
                        cout << "딜러가 이겼습니다. " << endl;
                        gamer[i].setPoint(gamer[i].getPoint() - beting[i]);
                    }
                    else if (gamer[i].myCardPoint() == winerpoint)
                    {
                        cout << gamer[i].getName() << "님이 이겼습니다. " << endl;
                        gamer[i].setPoint(gamer[i].getPoint() + beting[i]);
                    }
                    else
                    {
                        gamer[i].setPoint(gamer[i].getPoint() - beting[i]);
                    }
                }
            }







            cout << endl << " *********************************** " << endl;
            //for (int  i = 0 ; i < playerCount; i ++ ) {
            for (i = 0; i < playerCount; i++)
            {
                cout << gamer[i].getName() << ", Point " << gamer[i].getPoint() << endl;
            }
            cout << " *********************************** " << endl;

            return 0;
        }

};