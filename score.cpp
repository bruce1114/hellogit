#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef struct student{
  string name;
  bool sex;
  double score;
}student;
student s[1000];
bool cmp(student a,student b)
{
  if(a.score!=b.score) return a.score>b.score;
  return a.name<b.name;
}
int main()
{
  string temp;
  ifstream fin("score.csv");
  getline(fin,temp);
  int cnt=0;
  while(getline(fin,temp))
  {
    stringstream ss;
    ss<<temp;
    ss>>s[cnt].name;
    int l=s[cnt].name.length();
    s[cnt].name[l-1]=0;
    string tempp;
    ss>>tempp;
    if(tempp[0]=='F') s[cnt].sex=false;
    else s[cnt].sex=true;
    ss>>s[cnt].score;
    cnt++;
  }
  double avr=0;
  double avb=0,avg=0;
  int cntb=0,cntg=0;
  for(int i=0;i<cnt;++i)
  {
    avr+=s[i].score;
    if(s[i].sex)
    {
      cntb++,avb+=s[i].score;
    }
    else cntg++,avg+=s[i].score;
  }
  avr=avr/cnt;
  avb/=cntb,avg/=cntg;
  sort(s,s+cnt,cmp);
  cout<<"all average: "<<avr<<endl;
  cout<<"boy average: "<<avb<<endl;
  cout<<"girl average: "<<avg<<endl;
  for(int i=0;i<cnt;++i)
  {
     cout<<s[i].name<<" "<<(s[i].sex?"Male":"Female")<<" "<<s[i].score<<endl;
  }
}

