#ifndef CONFIG
#define CONFIG

#include <QObject>
#include <QDebug>
#include <QString>
#include <ctime>

extern const int position[9][9];

class Matrix{
public:
    int mtr[9][9];
    Matrix(){
        for(int i=0;i<9;++i)
            for(int j=0;j<9;++j)
                mtr[i][j]=0;
    }
    int count_0(){
        int cnt=0;
        for(int i=0;i<9;++i)
            for(int j=0;j<9;++j)
                if(mtr[i][j]==0)
                    cnt++;
        return cnt;
    }
    bool operator!=(const Matrix&a)const{
        for(int i=0;i<9;++i)
            for(int j=0;j<9;++j)
                if(mtr[i][j]!=a.mtr[i][j])
                    return 1;
        return 0;
    }
    int __init__(const QString&a)
    {
        int cnt=0;
        int len=a.length();
        for(int i=0;i<len;++i)
            if(a[i]=='.'||a[i]=='_')
            {
                mtr[cnt/9][cnt%9]=0;
                cnt++;
            }
            else if(a[i]>='0' && a[i]<='9')
            {
                mtr[cnt/9][cnt%9]=a[i].digitValue();
                cnt++;
            }
        return cnt==81;
    }
    void print(){
        QString s;
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(mtr[i][j]==0) s+='.';
                else s+=mtr[i][j]+'0';
            }
        }
            qDebug()<<s;
    }
};

struct Trip
{
    int x;
    int y;
    int v;
};

#endif // CONFIG

