#include<bits/stdc++.h>

using namespace std;

int v[5][5],x,y,a,b;

bool vercol(int col,int u)
{
    for(int i=1;i<=3;i++) if(v[u][i]!=col) return false;
    return true;
}

bool verlin(int lin,int u)
{
    for(int i=1;i<=3;i++) if(v[i][u]!=lin) return false;
    return true;
}

bool verdiag1(int diag)
{
    for(int i=1;i<=3;i++) if(v[i][i]!=diag) return false;
    return true;
}

bool verdiag2(int diag)
{
    for(int i=1;i<=3;i++) if(v[i][4-i]!=diag) return false;
    return true;
}

bool vercast(int jucator)
{
    if(vercol(jucator,1)) return true;
    if(vercol(jucator,2)) return true;
    if(vercol(jucator,3)) return true;
    if(verlin(jucator,1)) return true;
    if(verlin(jucator,2)) return true;
    if(verlin(jucator,3)) return true;
    if(verdiag1(jucator)) return true;
    if(verdiag2(jucator)) return true;
    return false;
}

bool remiza()
{
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++) if(v[i][j]==0) return false;
    return true;
}

int main()
{
    int j1=1,j2=2;
    while(j1)
    {
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++) cout<<v[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
        cout<<"[J1] Coord x = "; cin>>x;
        cout<<"[J1] Coord y = "; cin>>y;
        if(v[x][y]==0) v[x][y]=1;
        else
        {
            while(v[x][y]!=0)
            {
                for(int i=1;i<=50;++i) cout<<"\n";
                cout<<"Pozitie ocupata, incearca din nou"<<endl<<endl;
                for(int i=1;i<=3;i++)
                {
                    for(int j=1;j<=3;j++) cout<<v[i][j]<<" ";
                    cout<<"\n";
                }
                cout<<"\n"<<"\n";
                cout<<"[J1] Coord x = "; cin>>x;
                cout<<"[J1] Coord y = "; cin>>y;
                if(v[x][y]==0)
                {
                    v[x][y]=1;
                    break;
                }
            }
        }
        if(vercast(1)==true)
        {
            for(int i=1;i<=50;++i) cout<<"\n";
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++) cout<<v[i][j]<<" ";
                cout<<"\n";
            }
            cout<<"\n"<<"Jucatorul 1 este castigator!";
            break;
        }
        if(remiza()==true)
        {
            for(int i=1;i<=50;++i) cout<<"\n";
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++) cout<<v[i][j]<<" ";
                cout<<"\n";
            }
            cout<<"\n"<<"Remiza";
            break;
        }
        for(int i=1;i<=50;++i) cout<<"\n";
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++) cout<<v[i][j]<<" ";
            cout<<"\n";
        }
        cout<<endl;
        cout<<"[J2] Coord x = "; cin>>a;
        cout<<"[J2] Coord y = "; cin>>b;
        if(!v[a][b]) v[a][b]=2;
        else
        {
            while(v[a][b])
            {
                for(int i=1;i<=50;++i) cout<<"\n";
                cout<<"Pozitie ocupata, incearca din nou"<<endl<<endl;
                for(int i=1;i<=3;i++)
                {
                    for(int j=1;j<=3;j++) cout<<v[i][j]<<" ";
                    cout<<"\n";
                }
                cout<<"\n"<<"\n";
                cout<<"[J2] Coord x = "; cin>>a;
                cout<<"[J2] Coord y = "; cin>>b;
                if(!v[a][b])
                {
                    v[a][b]=2;
                    break;
                }
            }
        }
        if(vercast(2)==true)
        {
            for(int i=1;i<=50;++i) cout<<"\n";
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++) cout<<v[i][j]<<" ";
                cout<<"\n";
            }
            cout<<"\n"<<"Jucatorul 2 este castigator!";
            break;
        }
        for(int i=1;i<=50;++i) cout<<"\n";
    }
    return 0;
}
