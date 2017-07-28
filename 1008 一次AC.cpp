#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#define MAX 500
using namespace std;

string NameOfHaab[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
string NameOfTzolkin[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int Num;
int NumberOfDay_Haab;
string Month_Haab;
int Year_Haab;

int NumberOfDay_Tzolkin;
string Month_Tzolkin;
int Year_Tzolkin;

int compare_month_Haab(string MonthOfHaab){
    int i = 0;
    for(i=0;i < 20;i++){
        if(MonthOfHaab.compare(NameOfHaab[i]) == 0){
            return i;
        }
    }
    return MAX;

}


void Reverse(int Total){
    int year;
    int month;
    int day;
    year = Total / 260;
    month = (Total % 260)%20;
    day = (Total%260)%13;
    NumberOfDay_Tzolkin = day+1;
    Month_Tzolkin=NameOfTzolkin[month];
    Year_Tzolkin=year;
}

int main(){
    char dot;
    cin >> Num;
    cout << Num << endl;
    int k =Num;
    int CountNumber,The_Total_Days;
        while(cin >> NumberOfDay_Haab >> dot>>Month_Haab>>Year_Haab){
                if(Year_Haab <= 5000){
                CountNumber = compare_month_Haab(Month_Haab);
                if(CountNumber<100){
                The_Total_Days = 365*Year_Haab+20*CountNumber+NumberOfDay_Haab;
                Reverse(The_Total_Days);
                cout << NumberOfDay_Tzolkin <<" "<<Month_Tzolkin<<" "<<Year_Tzolkin<<endl;
            }
        }
    }

}
