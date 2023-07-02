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

// Casino Ŭ������ budget ���� �� �ʱ�ȭ
double Casino::budget = 10000.0;


class Card : private Casino{
private:
    string shape;
    int num;
    
public:
    Card(int number); //ī�忡 ��ȣ �ֱ� 
    void show(); //ī�� �����ֱ� 

    
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
    
    vector<Card> number; //ī�� 52��. 
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
        
        return "Dealer�� ī��: " + card->getShape();
    }


};

class Person : private Casino {
private:
    string name;
    Card* card;
        bool win;
        double budget;
    
public:
    Person();    //����� ������.. �̸� ���� �Է� ����.. 
    Person(string name);  //����� ������.. �̸��� ������ 
    
    string getName() const;    //����� �̸��� ������. 
         
    void setName(string name);  //����� �̸��� ������. 
    

    

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

/* ������ �ϴ� ����� ���� ������ ��� Ŭ���� */
class Player :public Person {  //����� ���Ѱ��� ��� �޴´�. 
private:
    int Point;        //���ӿ� ���Ǵ� ���̹� �Ӵ�? (�ʱ⿡ �󸶷� �ұ��? )
    vector <Card> myCard;  //������ �ִ� ī�� 

public:
    Player();
    Player(int Point);
    Player(string name, int Point);
   

    int getPoint() const;    //����Ʈ�� �󸶳� ���ҳ� Ȯ��.. 
    void setPoint(int point);  //����Ʈ�� ����
    void changePoint(int point);//����Ʈ�� ����.. ����, ������ ���Ͽ� 

   
    int addCard(Card); // card ������ �� �޴�. 
    void showMyCard(); // card�� �����ش�. 
    int myCardPoint(); // card ������ �����ش�. 
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

    //A�� ���Ͽ� ������� �ʾҴ�. 
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

        //Ŭ���� ī�带 �̿��Ͽ� ī�� ��ü�� �ϳ� �����. 
        DeckofCards Deck;
        //ī�带 �� ���´�. 
        Deck.shuffle();


        int playerCount = 3;

        Player* gamer = new Player[playerCount];

        //��������
        Player dealer("����", 50000);

        cout << "�����ϴ� ���� ������ �Է��� �ּ��� ? " << endl;

        for (int i = 0; i < playerCount; i++)
        {
            string inputName;
            cout << endl << i + 1 << "��° player�� �̸� : ";
            cin >> inputName;
            gamer[i].setName(inputName);


            int point;
            cout << inputName << "���� ����Ʈ�� ���Դϱ�? ";
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

        cout << " ������ �����ϰڽ��ϴ�. " << endl << endl;



        int end = 0;
        vector<int> beting;

        while (end == 0)
        {
            //�÷��̾��� ������ �ȳ�.
            for (i = 0; i < playerCount; i++)
            {
                cout << gamer[i].getName() << " ���� ���� ����Ʈ�� ";
                cout << gamer[i].getPoint() << endl;
            }


            //ù��° ī�� �ޱ�.. 
            for (i = 0; i < playerCount; i++)
            {
                Card temp = Deck.getCard();
                gamer[i].addCard(temp);
                cout << gamer[i].getName() << " : ";
                gamer[i].showMyCard();
                cout << "\n";
            }
            //���� ù��°.
            Card temp = Deck.getCard();
            dealer.addCard(temp);
            cout << dealer.getName() << " : ";
            dealer.showMyCard();
            cout << "\n";








            //���� ����. 
            for (i = 0; i < playerCount; i++)
            {
                gamer[i].playCard(&Deck);
                cout << "\n";
            }



            if (dealer.myCardPoint() > 21)
            {
                cout << " ���� BURST..." << endl;
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
                        cout << gamer[i].getName() << "���� �̰���ϴ�. " << endl;
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
                        cout << "������ �̰���ϴ�. " << endl;
                        gamer[i].setPoint(gamer[i].getPoint() - beting[i]);
                    }
                    else if (gamer[i].myCardPoint() == winerpoint)
                    {
                        cout << gamer[i].getName() << "���� �̰���ϴ�. " << endl;
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