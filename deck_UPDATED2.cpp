#include <iostream>
using namespace std;
Class Card
{
    typedef struct CardId
    {
        int rowNo;
        int colNo;
    } Id;
    vector<int> col[14]={0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    vector<int> row[8]={0,1,2,3,4,5,6,7};
    int Deck[8][14];
    Deck[4][0]=1;
    Deck[5][0]=1;
    Deck[6][0]=1;
    Deck[7][0]=1;
    int cnt=0;
    Id random()
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
        Deck[r][c]=1;
        return card;
    }
    Id getCard()
    {
        Id card=random();
        while(Deck[card.rowNo][card.colNo])
        {
            card=random();
        }
        return card;
    }
    void updateRow()
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
    void updateColumn()
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
}
