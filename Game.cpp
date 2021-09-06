/*
Before understanding the code, it is advisable to read the methodology.
Rules are slightly different from traditional standards due to conflict of ideas.
We tried our best to build the application and minimize errors, but still,
 an application is never really complete. The application is running on
 Code Blocks and all basic steps are conducted easily , but still there
 are chances that bugs may occur, if so we are very sorry for that.
 We hope that you can forgive us upon that and enjoy our application with
your friends and family.*/


#include<iostream>
#include<cstdlib>
#include<vector>
#include<bits/stdc++.h>
#include<conio.h>
#include<stddef.h>
#include<string>
using namespace std;




//Card Info
typedef struct CardId //structure of card
{
    int rowNo;
    int colNo;
} Id;
vector<int> col{0,1,2,3,4,5,6,7,8,9,10,11,12,13}; //to store available columns
vector<int> row{0,1,2,3,4,5,6,7};   //to store available rows
int Deck[8][14]= {{0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0}};
int cnt=0;  // to count played cards
void updateRow()   // read from methodology
{
    for(int i=0; i<8; i++)
    {
        int flag=0;
        for(int j = 0; j<14; j++)
        {
            if(Deck[i][j]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int k=0; k<row.size(); k++)
            {
                if(row[k]==i)
                {
                    int temp= row[k];
                    row[k]= row[row.size()-1];
                    row[row.size()-1]= temp;
                }
            }
            row.pop_back();
        }
    }
}
void updateColumn()    // read from methodology
{
    for(int i=0; i<14; i++)
    {
        int flag=0;
        for(int j = 0; j<8; j++)
        {
            if(Deck[j][i]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int k=0; k<col.size(); k++)
            {
                if(col[k]==i)
                {
                    int temp= col[k];
                    col[k]= col[col.size()-1];
                    col[col.size()-1]= temp;
                }
            }
            col.pop_back();
        }
    }
}
Id random()     // read from methodology
{
    srand(time(0));
    Id card;
    cnt++;
    if(cnt>35)
    {
        updateRow();
        updateColumn();
        cnt=0;
    }
    int r= rand()%row.size();
    int c= rand()%col.size();
    card.rowNo= row[r];
    card.colNo= col[c];
    return card;
}
Id getCard()    // read from methodology
{

    Id card=random();

    while(Deck[card.rowNo][card.colNo])
    {
        card=random();
    }
    Deck[card.rowNo][card.colNo]=1;

    return card;
}


//Player Info


class hand   // Linked List structure
{
public:
    int rowNo;
    int colNo;
    hand* next;
};


class Player : public hand   //Inheritance of Hand class in Player
{
public:
    string name;
    hand* head=NULL;
public:
    void setName(string name1)
    {
        name=name1;
    }
    void addCard()     // read from methodology
    {

        Id newCard = getCard(); // Id structure from above
        hand* newC=new hand();

        newC->rowNo=newCard.rowNo;
        newC->colNo=newCard.colNo;
        newC->next=NULL;
        if(head==NULL)
        {

            head=newC;
            return;
        }
        hand* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newC;

    }
    void delCard(int rno, int cno)        // read from methodology
    {
        hand* temp=head;
        hand* prev=new hand();
        while(temp!=NULL)
        {
            if(cno==13)
            {
                if((temp->rowNo==rno||temp->rowNo==(rno+1)||temp->rowNo==(rno+2)||temp->rowNo==(rno+3)) && temp->colNo==cno)
                {
                    if(temp==head)
                    {
                        head = head->next;
                    }
                    if(temp->next==NULL)
                    {
                        prev->next=NULL;
                    }
                    prev->next=temp->next;
                    break;
                }
            }
            else
            {
                if((temp->rowNo==rno||temp->rowNo==(rno+4)) && temp->colNo==cno)
                {
                    if(temp==head)
                    {
                        head = head->next;
                    }
                    if(temp->next==NULL)
                    {
                        prev->next=NULL;
                    }
                    prev->next=temp->next;
                    break;
                }
            }
            prev=temp;
            temp=temp->next;
        }

    }
};

// Some major functions used in main

void displayCard(int r, int c)     // read from methodology
{
    if(c==13)
    {
        cout<<"W";
        if(r<=3)
            cout<<"C";
        else
            cout<<"F";
        cout<<"\t";
        return;
    }
    if(r==0||r==4)
        cout<<"R";
    if(r==1||r==5)
        cout<<"Y";
    if(r==2||r==6)
        cout<<"G";
    if(r==3||r==7)
        cout<<"B";
    if(c<=9)
        cout<<c;
    if(c==10)
        cout<<"S";
    if(c==11)
        cout<<"R";
    if(c==12)
        cout<<"T";
    cout<<"\t";
}
int getRow(string card)      // read from methodology
{
    char ch=card[0];
    if(ch=='R')
        return 0;
    if(ch=='Y')
        return 1;
    if(ch=='G')
        return 2;
    if(ch=='B')
        return 3;
    if(ch=='W')
    {
        if(card[1]=='C')
            return 0;
        if(card[1]=='F')
            return 4;

    }
    return -1;
}
int getCol(string card)      // read from methodology
{
    char ch=card[1];
    if(ch=='S')
        return 10;
    if(ch=='R')
        return 11;
    if(ch=='T')
        return 12;
    if(ch=='F'||ch=='C')
        return 13;
    int num= (int)ch-48;
    return num;
}
bool checkCard(int r, int c, string s)      // read from methodology
{
    int r1=getRow(s);
    int c1=getCol(s);
    if(c1==13)
    {
        return true;
    }
    else
    {
        if((r==r1||r==(r1+4)) || c==c1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}
void displayHand(hand* head1)   // displays hand by selecting nodes of LL
{
    hand* temp;
    temp=head1;
    do
    {
        displayCard(temp->rowNo,temp->colNo);
        temp=temp->next;
    }
    while(temp!=NULL);
    return;
}


int main()
{
    cout<<"UNO - Multiplayer Card Game Version 1.0 by Shubh,Divya And Rashika"<<endl;
    int n;
    cout<<"Enter number of players"<<endl;
    cin>>n;
    string p[n+1];
    for(int i=1; i<=n; i++)
    {
        cout<<"Enter name of Player "<<i<<endl;
        cin>>p[i];
    }
    cout<<"Its time for some UNO!!"<<endl;
    cout<<"Loading..."<<endl;
    Player* players= new Player[n+1];
    for(int i=1; i<=n; i++)
    {
        cout<<p[i]<<"'s cards generating..."<<endl;
        players[i].name=p[i];

        for(int j=1; j<=7; j++)
        {

            players[i].addCard();
        }

    }
    int rot=1;       //Specifies which player is playing
    cout<<"Game Loaded"<<endl;
    Id TopCard = getCard(); // Getting first card
    while(TopCard.colNo==13)
    {
        Deck[TopCard.rowNo][TopCard.colNo]=0;  //checking whether it is not a wild card
        TopCard= getCard();
    }
    string colour;   //to store colour after wild card is played
    int prev;      //to store previous value of rot after updation
    int fla;
    string cardPlayed;  //to store card entered by user
    while(rot>=(-n)||rot<=n)   //condition is like this because reverse will turn rot into negative for reverse play of chances
    {
        prev=rot;
        cout<<"\n\n\n"<<p[abs(rot)]<<"'s chance"<<endl;

        //Last played Card
        cout<<"Last Played card is ";
        displayCard(TopCard.rowNo,TopCard.colNo);
        if(!colour.empty())
        {
            cout<<"Colour switched to "<<colour;
            TopCard.rowNo=getRow(colour);
            colour="";
        }
        cout<<endl<<"Your hand is :  ";


        //Hand of the player

        displayHand(players[abs(rot)].head);


        //Card played by the player

        cout<<endl<<"What you wanna do \nDraw(enter D)/Play card(P)"<<endl;
        char choice;
        cin>>choice;
        int flag=1;
        do
        {
            if(choice=='P')
            {
                fla=1;
                do
                {
                    cout<<"Enter your card"<<endl;

                    cin>>cardPlayed;


                    if(checkCard(TopCard.rowNo,TopCard.colNo,cardPlayed))
                    {
                        TopCard.rowNo=getRow(cardPlayed);
                        TopCard.colNo=getCol(cardPlayed);
                        players[abs(rot)].delCard(getRow(cardPlayed),getCol(cardPlayed));
                        fla=1;
                    }
                    else
                    {
                        cout<<"Invalid Card, Huh! NOOB";
                        fla=0;

                    }
                }
                while(fla==0);
            }
            else if(choice=='D')
            {
                players[abs(rot)].addCard();
                cout<<"One Card added"<<endl;
                displayHand(players[abs(rot)].head);
                flag=1;
            }
            else
            {
                cout<<"Broooo, \"Small Brain, Try Again\" "<<endl;
                flag=0;
            }
        }
        while(flag==0);

        if(players[abs(rot)].head==NULL)
        {
            cout<<"GG BOiiiiii, "<<players[abs(rot)].name<<" won!!, easy peasy , kal aana"<<endl;
            cout<<"Game Ended";
            break;
        }


        //Updation of rot

        if(cardPlayed.compare("WF")==0)
        {
            players[abs(rot)+1].addCard();
            players[abs(rot)+1].addCard();
            players[abs(rot)+1].addCard();
            players[abs(rot)+1].addCard();
            cout<<"Which Colour do you want to be played - R,Y,G,B ?"<<endl;
            cin>>colour;
            rot+=2;
        }
        else if(cardPlayed.compare("WC")==0)
        {
            cout<<"Which Colour do you want to be played - R,Y,G,B ?"<<endl;
            cin>>colour;
            rot++;
        }
        else if(cardPlayed[1]=='T')
        {
            players[abs(rot)+1].addCard();
            players[abs(rot)+1].addCard();
            rot+=2;
        }
        else if(cardPlayed[1]=='S')
        {
            rot+=2;
        }
        else if(cardPlayed[1]=='R')
        {
            rot=-rot;
            rot++;
        }
        else
        {
            rot++;
        }
        if(prev<0)
        {
            if(rot==0)
            {
                rot=-n;
            }
            if(rot==1)
            {
                rot=-n+1;
            }
        }
        else if(prev>0)
        {
            if(rot==n+1)
                rot=1;
            if(rot==n+2)
                rot=2;
            if(rot==0)
                rot=-n;
        }
    }
    return 0;
}
//Thank You
