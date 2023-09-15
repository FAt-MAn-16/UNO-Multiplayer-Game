#include <iostream>
using namespace std;
class Player
{
    string name;
    typedef struct Hand{
        int rowNo;
        int colNo:
        hand *next;
    } hand;
    Player(string name1)
    {
        name=name1;
        hand *head;
        for(int i=1;i<=7;i++)
        {
            addCard();
        }
    }
    void addCard()
    {
        Id newCard = getCard(); // Id from card file
        hand* newC;
        newC->rowNo=newCard.rowNo;
        newC->colNo=newCard.colNo;
        newC->next=NULL;
        hand* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newC;
    }
    void delCard(int rno, int cno)
    {
        hand* temp=head;
        hand* prev=NULL;
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
        if(!temp)
        {
            cout<<"Card does not exist"<<endl;
        }
    }
}
