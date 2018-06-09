#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
typedef struct student{
  string name;
  bool sex;
  double score;
}student;
vector<student>s;
bool cmp(student a,student b)
{
  if(a.score!=b.score) return a.score>b.score;
  return a.name<b.name;
}
int main()
{
  freopen("score.csv","r",stdin);
  string temp;
  getline(cin,temp);
  int cnt=0;
  while(getline(cin,temp))
  {
    student tempp;
    stringstream ss;
    ss<<temp;
    ss>>tempp.name;
    tempp.name.pop_back();
    ss>>temp;
    if(temp[0]=='F') tempp.sex=false;
    else tempp.sex=true;
    ss>>tempp.score;
    s.push_back(tempp);
  }
  double avr=0;
  double avb=0,avg=0;
  int cntb=0,cntg=0;
  cnt=s.size();
  for(int i=0;i<cnt;++i)
  {
    avr+=s[i].score;
    if(s[i].sex) cntb++,avb+=s[i].score;
    else cntg++,avg+=s[i].score;
  }
  avr=avr/cnt;
  avb/=cntb,avg/=cntg;
  sort(s.begin(),s.end(),cmp);
  cout<<"all average: "<<avr<<endl;
  cout<<"boy average: "<<avb<<endl;
  cout<<"girl average: "<<avg<<endl;
  for(int i=0;i<cnt;++i)
  {
     cout<<s[i].name<<" "<<(s[i].sex?"Male":"Female")<<" "<<s[i].score<<endl;
  }
}

