/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2017 by Anav Mehta                                      *
 *                                                                         *
 *   http://3dwaffles.blogspot.com                                         *
 *                                                                         *
 ***************************************************************************/

#include <iostream>
using namespace std;


int drawBoard(int n, char a[])
{
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int fillBoard(int n, int a[])
{
    int b[100];
//    int a[100];
    int lastindex = 1;
    for(int k=0; k<n; k++)
    {
        //cout << "k=" << k << "n/2=" << n/2 << "lastindex =" << lastindex << endl;
        if(k < n/2)
        {
            b[k] = lastindex;
            lastindex = lastindex + 1;
        }
        else if(k > n/2)
        {
            b[k] = lastindex;
            lastindex = lastindex - 1;
        }
        else
        {
            b[k] = lastindex;
            lastindex = lastindex - 1;
        }
        //cout << "b[k]=" << b[k] << endl;
    }
    b[0] = 0;

    lastindex = n/2;

    int moves = 0;
    for(int k=1; k<n; k++)
    {

        for(int l=0; l<b[k]; l++)
        {
            a[moves] = lastindex;
            moves++;
 //           cout << lastindex << endl;
            if(k %2 == 1)
            {
                lastindex = lastindex + 2;
            }
            else
            {
                lastindex = lastindex - 2;
            }

        }
        //cout << "here " << b[k]<<endl;

        if(k < n/2)
        {
            if(k % 2 == 1)
            {
                lastindex = lastindex - 1;
            }
            else
            {
                lastindex = lastindex + 1;
            }
        }
        else if (k > n/2)
        {
            if(k %2 == 1)
            {
                lastindex = lastindex -3;
            }
            else
            {
                lastindex = lastindex +3 ;
            }
        }
        else
        {
            if(k % 2 == 1)
            {
                lastindex = lastindex - 3;
            }
            else
            {
                lastindex = lastindex + 3;
            }
        }
    }

    return(moves);

}



int moveBoard(int n, char a[], int k, int undo)
{
    if(undo == 0)
    {
        if(a[k] == 'T')
        {
            cout << "Toad ";
            if((a[k+1] == '-') && (k < n))
            {
                a[k] = '-';
                a[k+1] = 'T';
                cout << "slides right from " << k+1 << " to " << k+2 << endl;
                return(k+1);
            }
            else if((k < n+1) && (a[k+1] != '-') && (a[k+2] == '-'))
            {
                a[k+2] = 'T';
                a[k]= '-';
                cout << "jumps right from " << k+1 << " to " << k+3 << endl;
                return(k+2);
            }
        }
        if(a[k] == 'F')
        {
            cout << "Frog ";
            if((a[k-1] == '-') && (k > 0))
            {
                a[k] = '-';
                a[k-1] = 'F';
                cout << "slides left from " << k+1 << " to " << k << endl;
                return(k-1);
            }
            else if((k >= 2) && (a[k-1] != '-') && (a[k-2] == '-'))
            {
                a[k-2] = 'F';
                a[k]= '-';
                cout << "jumps left from " << k+1 << " to " << k-1 << endl;
                return(k-2);
            }
        }
    }
    else
    {
        // undo logic
        if(a[k] == 'F')
        {
            if((a[k+1] == '-') && (k < n))
            {
                a[k] = '-';
                a[k+1] = 'F';
            }
            else if((k < n+1) && (a[k+1] != '-') && (a[k+2] == '-'))
            {
                a[k+2] = 'F';
                a[k]= '-';
            }
        }
        if(a[k] == 'T')
        {
            if((a[k-1] == '-') && (k > 0))
            {
                a[k] = '-';
                a[k-1] = 'T';
            }
            else if((k >= 2) && (a[k-1] != '-') && (a[k-2] == '-'))
            {
                a[k-2] = 'T';
                a[k]= '-';
            }
        }
    }
}
int main()
{
    int n, k, newk;
    int pick;
    char a[100];
    int b[100];
    int moveno=0;
    int nummoves;
    int moveStack[1000];

    n = -1;
    while((n <= 0) || (n%2 == 0))
    {
        cout << "Enter the size of the board (odd integer > 0)" << endl;
        cin >> n;
    }

    for(int i=0; i<n; i++)
    {
        if(i < n/2)
        {
            a[i] = 'T';
        }
        else if (i > n/2)
        {
            a[i] = 'F';
        }
        else a[i] = '-';
    }
    drawBoard(n, a);
    nummoves = fillBoard(n, b);
    int j=0;

    while(j < nummoves)
    {

        k = b[j];
        j++;
        k = k - 1;
        newk = moveBoard(n, a, k, 0);

        drawBoard(n, a);


    }

}
